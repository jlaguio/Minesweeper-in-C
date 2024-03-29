/**
 * @ Author: MMMM
 * @ Create Time: 2024-02-25 15:06:24
 * @ Modified time: 2024-03-29 21:59:10
 * @ Description:
 * 
 * This file defines the page handler for the page where the user can actually play minesweeper
 */

#ifndef PAGE_PLAY_INTERACTIVE_
#define PAGE_PLAY_INTERACTIVE_

#include "../game/game.c"

#include "../utils/utils.asset.h"
#include "../utils/utils.page.h"
#include "../utils/utils.component.h"

#include "../settings.c"

#include <string.h>
#include <ctype.h>

/**
 * Configures the main menu.
 * 
 * @param   { p_obj }   pArgs_Page  The page instance we need to configure.
*/
void PageHandler_playI(p_obj pArgs_Page) {

  Page *this = (Page *) pArgs_Page;
  Game *pGame = (Game *) this->pSharedObject;
  int dWidth, dHeight, dMargin, x, y;

  // Component names
  char *sPlayIComponent = "play-i.fixed";
  char *sHeaderComponent = "header.fixed.aleft-x.atop-y";
  char *sFooterComponent = "footer.fixed.aleft-x.atop-y";
  char *sFieldContainerComponent = "field-container.fixed";
  char *sFieldComponent = "field.acenter-x.acenter-y";
  char *sFieldCursorComponent = "field-cursor.aleft-x.atop-y";
  char *sGamePromptComponent = "game-prompt.fixed.aleft-x.abottom-y";
  char *sGameInfoComponent = "game-info.fixed.aleft-x.atop-y";
  char *sPopupComponent = "popup.fixed";

  // For inspect components
  char sInspectKey[STRING_KEY_MAX_LENGTH];
  char sFlagKey[STRING_KEY_MAX_LENGTH];

  // Some of the component contents
  char sGamePromptText[STRING_KEY_MAX_LENGTH];
  char sGameInfoText[STRING_KEY_MAX_LENGTH];

  // Buffer for minesweeper grid 
  char *sGridBuffer;

  // Pressed key
  char cKeyPressed = 0;
  
  // Do stuff based on page status
  switch(this->ePageStatus) {

    case PAGE_ACTIVE_INIT:

      // Get the dimensions 
      dWidth = IO_getWidth();
      dHeight = IO_getHeight();
      dMargin = 3;
      
      // Create component tree
      Page_addComponentContext(this, sPlayIComponent, "root", 0, 0, dWidth, dHeight, "primary", "secondary");
      Page_addComponentContainer(this, sHeaderComponent, sPlayIComponent, dWidth / 2 - Game_getCharWidth(pGame) / 2, dMargin);
      Page_addComponentContainer(this, sFooterComponent, sPlayIComponent, dWidth / 2 - Game_getCharWidth(pGame) / 2, dHeight - dMargin);
      Page_addComponentContainer(this, sFieldContainerComponent, sPlayIComponent, dWidth / 2, dHeight / 2);
      Page_addComponentText(this, sFieldComponent, sFieldContainerComponent, 0, 0, "primary-darken-0.75", "", "");
      Page_addComponentAsset(this, sFieldCursorComponent, sFieldComponent, 0, 0, "accent", "", "field-cursor");
      Page_addComponentText(this, sGameInfoComponent, sHeaderComponent, 0, 0, "", "", "");
      Page_addComponentText(this, sGamePromptComponent, sFooterComponent, 0, 0, "", "", "");
      Page_addComponentPopup(this, sPopupComponent, dWidth / 2, dHeight / 2, 56, 14, "secondary", "accent", "", "", "");

      // This is stupid but LMAO
      for(x = 0; x < pGame->field.dWidth; x++) {
        for(y = 0; y < pGame->field.dHeight; y++) {

          // The key
          sprintf(sFlagKey, "flag-%d-%d", x, y);

          // Create the component
          Page_addComponentText(this, 
            sFlagKey, 
            sFieldContainerComponent, 
            
            x * GAME_CELL_WIDTH - Game_getCharWidth(pGame) / 2 + 1, 
            y * GAME_CELL_HEIGHT - Game_getCharHeight(pGame) / 2,  
            
            "accent2", "", "");

          sprintf(sFlagKey, "flag-darken-%d-%d", x, y);

          Page_addComponentText(this, 
            sFlagKey, 
            sFieldContainerComponent, 
            
            x * GAME_CELL_WIDTH - Game_getCharWidth(pGame) / 2 + 1, 
            y * GAME_CELL_HEIGHT - Game_getCharHeight(pGame) / 2,  
            
            "accent2-darken-0.36", "", " ");
        }
      }

      // Display the actual grid
      sGridBuffer = String_alloc(Game_getCharWidth(pGame) * Game_getCharHeight(pGame) * 4);
      Game_displayGrid(pGame, sGridBuffer);
      Page_setComponentText(this, sFieldComponent, sGridBuffer);
      String_kill(sGridBuffer);

    break;

    case PAGE_ACTIVE_RUNNING:
      
      // Key handling
      cKeyPressed = EventStore_get(this->pSharedEventStore, "key-pressed");

      // If no popup is active
      if(Page_getUserState(this, "is-popup")) {

        // Switch between options
        if(cKeyPressed == '\t')
          Page_toggleComponentPopup(this, sPopupComponent, "secondary", "accent");

        // Submit popup
        else if(cKeyPressed == '\n' || cKeyPressed == '\r') {
          Page_disableComponentPopup(this, sPopupComponent);
          Game_unpause(pGame);

          // First option
          if(Page_readComponentPopup(this, sPopupComponent) == 0) {

            // Reset component tree since the game UI needs that
            Page_resetComponents(this);
            Page_idle(this);

            // If game over (retry button)
            if(Game_isDone(pGame)) {
              Page_setNext(this, "play");

            // If not game over (exit button)
            } else {
              Page_setNext(this, "menu");
            }

            // Make sure the function doesn't try to access the borked component tree down there.
            return;
          
          // Second option
          } else {

            // If game over
            if(Game_isDone(pGame)) {
              
              // Reset component tree since the game UI needs that
              Page_resetComponents(this);

              // Go to menu next
              Page_idle(this);
              Page_setNext(this, "menu");
            }
          }
        }

      } else {

        // Switch based on what key was last pressed
        switch(cKeyPressed) {

          // Escape character to go back
          case 27:
            Page_enableComponentPopup(this, sPopupComponent);
            Page_setComponentPopupText(this, sPopupComponent, "Exit.to.main.menu??\nGame.wont.be.saved.\0");
            Page_setComponentPopupOptions(this, sPopupComponent, "yes", "no.");
            Game_pause(pGame);
          break;

          // Check the field if valid then save file after
          case '\n': case '\r':

            // Do the inspection algorithm
            Game_inspect(pGame, pGame->dCursorX, pGame->dCursorY);

            // Display the actual grid
            sGridBuffer = String_alloc(Game_getCharWidth(pGame) * Game_getCharHeight(pGame) * 4);
            Game_displayGrid(pGame, sGridBuffer);
            Page_setComponentText(this, sFieldComponent, sGridBuffer);
            String_kill(sGridBuffer);
          break;

          default:

            // The game ended
            if(Game_isDone(pGame)) {
              Page_enableComponentPopup(this, sPopupComponent);
              Page_setComponentPopupText(this, sPopupComponent, Game_getEndMessage(pGame));
              Page_setComponentPopupOptions(this, sPopupComponent, "retry", "exit.");

              return;
            }

            // WASD movement
            if(cKeyPressed == tolower(Settings_getGameMoveUp(this->pSharedEventStore)) ||
              cKeyPressed == toupper(Settings_getGameMoveUp(this->pSharedEventStore)))
              Game_decrementY(pGame);
              
            if(cKeyPressed == tolower(Settings_getGameMoveDown(this->pSharedEventStore)) ||
              cKeyPressed == toupper(Settings_getGameMoveDown(this->pSharedEventStore)))
              Game_incrementY(pGame);

            if(cKeyPressed == tolower(Settings_getGameMoveLeft(this->pSharedEventStore)) ||
              cKeyPressed == toupper(Settings_getGameMoveLeft(this->pSharedEventStore)))
              Game_decrementX(pGame);
            
            if(cKeyPressed == tolower(Settings_getGameMoveRight(this->pSharedEventStore)) ||
              cKeyPressed == toupper(Settings_getGameMoveRight(this->pSharedEventStore)))
              Game_incrementX(pGame);

            // Flag placement
            if(cKeyPressed == tolower(Settings_getGameToggleFlag(this->pSharedEventStore)) ||
              cKeyPressed == toupper(Settings_getGameToggleFlag(this->pSharedEventStore))) {

              // If does not have a flag
              if(!Grid_getBit(pGame->field.pFlagGrid, pGame->dCursorX, pGame->dCursorY))
                Game_addFlag(pGame);
              
              // If already has a flag
              else Game_removeFlag(pGame);
            }
            
            // For each cell, check if it's been inspected, and if so, change color
            for(x = 0; x < pGame->field.dWidth; x++) {
              for(y = 0; y < pGame->field.dHeight; y++) {

                // Check if it's been inspected
                if(Grid_getBit(pGame->field.pInspectGrid, x, y)) {

                  // Unique key for each component
                  sprintf(sInspectKey, "inspector-%d-%d", x, y);

                  // A lighter component for numbers > 0
                  if(pGame->field.aNumbers[y][x] > 0) {
                    Page_addComponentContext(this, 
                      sInspectKey, 
                      sFieldContainerComponent, 
                      
                      x * GAME_CELL_WIDTH - Game_getCharWidth(pGame) / 2, 
                      y * GAME_CELL_HEIGHT - Game_getCharHeight(pGame) / 2 - 1, 
                      
                      GAME_CELL_WIDTH + 1, 
                      GAME_CELL_HEIGHT + 1, 
                      
                      "primary-darken-0.25", "");
                  
                  // A darker component
                  } else {
                    Page_addComponentContext(this, 
                      sInspectKey, 
                      sFieldContainerComponent, 
                      
                      x * GAME_CELL_WIDTH - Game_getCharWidth(pGame) / 2, 
                      y * GAME_CELL_HEIGHT - Game_getCharHeight(pGame) / 2 - 1, 
                      
                      GAME_CELL_WIDTH + 1, 
                      GAME_CELL_HEIGHT + 1, 
                      
                      "primary-darken-0.5", "");
                  }
                }
                
                // The key
                sprintf(sFlagKey, "flag-%d-%d", x, y);
                
                // If there's a flag on it
                if(Grid_getBit(pGame->field.pFlagGrid, x, y))
                  Page_setComponentText(this, sFlagKey, "▐▀ ");
                
                // Remove flag if it exists
                else
                  Page_setComponentText(this, sFlagKey, "");
              }
            }

          break;
        }

        // Update UI
        Page_setComponentPos(this, sFieldCursorComponent, 
          pGame->dCursorX * GAME_CELL_WIDTH, 
          pGame->dCursorY * GAME_CELL_HEIGHT);

        // Game information text
        sprintf(sGameInfoText, "frame rate:      %s\ntime elapsed:    %s\nmines left:      %s\n",
          Game_getFPS(pGame),
          Game_getTime(pGame),
          Game_getMinesLeft(pGame));
        Page_setComponentText(this, sGameInfoComponent, sGameInfoText);

        // Prompt text
        sprintf(sGamePromptText, "[%s%s%s%s]   to move\n[enter]  to inspect a tile\n[%s]      to place a flag\n[esc]    to go back to menu",
          String_renderEscChar(Settings_getGameMoveUp(this->pSharedEventStore)),
          String_renderEscChar(Settings_getGameMoveLeft(this->pSharedEventStore)),
          String_renderEscChar(Settings_getGameMoveDown(this->pSharedEventStore)),
          String_renderEscChar(Settings_getGameMoveRight(this->pSharedEventStore)),
          String_renderEscChar(Settings_getGameToggleFlag(this->pSharedEventStore)));
        Page_setComponentText(this, sGamePromptComponent, sGamePromptText);
      }

    break;

    default:

    break;
  }
}

#endif
/**
 * @ Author: MMMM
 * @ Create Time: 2024-02-25 15:06:24
 * @ Modified time: 2024-03-28 08:58:02
 * @ Description:
 * 
 * This file defines the page handler for the page where the user can actually edit a minesweeper game
 */

#ifndef PAGE_EDITOR_INTERACTIVE_
#define PAGE_EDITOR_INTERACTIVE_

#include "../utils/utils.asset.h"
#include "../utils/utils.page.h"
#include "../utils/utils.component.h"

/**
 * Configures the main menu.
 * 
 * @param   { p_obj }   pArgs_Page  The page instance we need to configure.
*/
void PageHandler_editorI(p_obj pArgs_Page) {

  Page *this = (Page *) pArgs_Page;
  int dWidth, dHeight, dMargin;

  // Component names
  char *sEditorIComponent = "editor-i.fixed";
  
  // The cursor location for changing the mine field
  char cCursorX = 0;
  char cCursorY = 0;

  // Do stuff based on page status
  switch(this->ePageStatus) {

    case PAGE_ACTIVE_INIT:

      // Get the dimensions 
      dWidth = IO_getWidth();
      dHeight = IO_getHeight();
      dMargin = 44;

      // Create component tree
      Page_addComponentContext(this, sEditorIComponent, "root", 0, 0, dWidth, dHeight, "seconadary", "primary");

      // Define initial user states
      if(Page_getUserState(this, "editor-i-cursor-x") == -1) Page_setUserState(this, "editor-i-cursor-x", cCursorX);
      if(Page_getUserState(this, "editor-i-cursor-y") == -1) Page_setUserState(this, "editor-i-cursor-y", cCursorY);
    break;

    case PAGE_ACTIVE_RUNNING:
      
      // Key handling
      cCursorX = Page_getUserState(this, "editor-i-cursor-x");
      cCursorY = Page_getUserState(this, "editor-i-cursor-y");

      // Switch based on what key was last pressed
      switch(EventStore_get(this->pSharedEventStore, "key-pressed")) {

        // Escape character to go back
        case 27:
          Page_idle(this);
          Page_setNext(this, "menu");
        break;

        // Check the field if valid then save file after
        case '\n': case '\r':

        break;

        default:


        break;
      }


    break;

    default:

    break;
  }
}

#endif
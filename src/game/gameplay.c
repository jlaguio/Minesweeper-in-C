/**
 * @ Author: MMMM
 * @ Create Time: 2024-03-21 7:16:46
 * @ Modified time: 2024-03-28 20:53:14
 * @ Modified time: 2024-03-28 21:09:08
 * @ Description:
 * 
 * Executes tasks involved in-game.
 */

#ifndef GAMEPLAY_
#define GAMEPLAY_

#include "field.obj.h"
// #include "profile.game.c"
#include "./game.c"

#include "../utils/utils.file.h"
#include "../utils/utils.grid.h"
#include "../utils/utils.string.h"

#include <stdio.h>
#include <string.h>

/**
 * Intializes the field's data according to the difficulty.
 * This function is used for classic games.
 * 
 * @param   { GameDifficulty }    eGameDifficulty   The game's difficulty.
 * @param   { Field * }     pField   The field to be modified.
*/
void Gameplay_initClassic(GameDifficulty eDifficulty, Field *pField) {

    // For easy mode
    if(eDifficulty == GAME_DIFFICULTY_EASY) {
        
        // Sets up the field's width and height
        pField->dWidth = GAME_EASY_ROWS;
        pField->dHeight = GAME_EASY_COLUMNS;
        
        // Populates the field with mines 
        Field_populateRandom(pField, GAME_EASY_MINES);
    }
    
    // For difficult mode
    else {

        // Sets up the field's width and height
        pField->dWidth = GAME_DIFFICULT_ROWS;
        pField->dHeight = GAME_DIFFICULT_COLUMNS;

        // Populates the field with mines
        Field_populateRandom(pField, GAME_DIFFICULT_MINES);
    }
}

/**
 * Intializes the field's data according to the custom game's specs.
 * 
 * @param   { Field * }     pField   The field to be modified.
 * @param   { sName * }     sName    Name of the custom level.
*/
void Gameplay_initCustom(Field *pField, char *sName) {
    
    // Declares the path of the custom level's file.
    char *sPath = String_alloc(LEVEL_PATH_MAX_SIZE);

    // Sets the cutom level's file path
    snprintf(sPath, LEVEL_PATH_MAX_SIZE, "%s%s.txt", LEVELS_FOLDER_PATH, sName);

    // Populates the field with mines
    Field_populateCustom(pField, sPath);

    // Deallocates the memory for the file path's string
    String_kill(sPath);
}

/**
 * Selects the type of game (classic or custom) to be played.
 * 
 * @param   { GameType }    eType    The type of game to be played.
 * @param   { Field * }     pField   The field to be modified.
*/
void Gameplay_selectType(GameType eType, Field *pField) {

    // For classic games
    if(eType == GAME_TYPE_CLASSIC) {

        GameDifficulty eDifficulty;
        // TODO: input game difficulty

        //! remove this line later on
        eDifficulty = GAME_DIFFICULTY_EASY;

        Gameplay_initClassic(eDifficulty, pField);

    // For custom games
    } else {

        // TODO: input custom level name
        char *sName = "";
        
        // TODO: check if the level exists; if not, handle the error

        Gameplay_initCustom(pField, sName);
    }

    // Initializes each of the tile's flag placement status
    Grid_clear(pField->pFlagGrid, 0);

    // Initializes each of the tile's inspection status
    Grid_clear(pField->pInspectGrid, 0);

    // Specifies the number of mines adjacent to each tile
    Field_setNumbers(pField);
}

/**
 * Inspects a tile.
 * 
 * @param   { Field * }     pField      The field to be modified.
 * @param   { int }         x           The tile's x-coordinate in index notation.
 * @param   { int }         y           The tile's y-coordinate in index notation.
*/
void Gameplay_inspect(Game *this, int x, int y) {
    int i, j;

    Field *pField = &this->gameField;

    // If there is a flag there, don't inspect it
    if(Grid_getBit(pField->pFlagGrid, x, y))
        return;

    // Considers the specific tile inspected
    Field_inspect(pField, x, y);

    // Ends the game if a mine has been inspected
    if(Grid_getBit(pField->pMineGrid, x, y)) {
        Game_end(this, GAME_OUTCOME_LOSS);
        return;
    }

    // Cascades the inspection if the number on the tile is 0
    if(pField->aNumbers[x][y] == 0) {

        // The following loops check each adjacent tile within bounds of the field

        // Loops through each row
        for(i = x - 1; i <= x + 1; i++) {
            if(i >= 0 && i <= pField->dHeight - 1) {

                // Loops through each column
                for(j = y - 1; j <= y + 1; j++) {
                    if(j >= 0 && j <= pField->dWidth - 1) {

                        // Recures the function if the number on the tile is 0
                        // only when it hasn't been inspected
                        if(!pField->aNumbers[i][j] && 
                           !Grid_getBit(pField->pInspectGrid, i, j))
                            Gameplay_inspect(this, i, j);

                        // Marks the tile as inspected
                        if(pField->aNumbers[i][j] >= 0)
                            Field_inspect(pField, i, j);

                    }
                }
            }
        }
    }
}

/**
 * Adds a flag on a tile only if it hasn't been inspected.
 * Also marks it as inspected.
 * 
 * @param   { Field * }     pField   The field to be modified.
 * @param   { int }         x        The tile's x-coordinate in index notation.
 * @param   { int }         y        The tile's y-coordinate in index notation.
*/
void Gameplay_addFlag (Field *pField, int x, int y) {
    if(!Grid_getBit(pField->pInspectGrid, x, y)) {
        Grid_setBit(pField->pFlagGrid, x, y, 1);
    }
}

/**
 * Removes a flag from a tile only if it currently has a flag.
 * Also marks it as uninspected.
 * 
 * @param   { Field * }     pField   The field to be modified.
 * @param   { int }         x        The tile's x-coordinate in index notation.
 * @param   { int }         y        The tile's y-coordinate in index notation.
*/
void Gameplay_removeFlag (Field *pField, int x, int y) {
    if(Grid_getBit(pField->pFlagGrid, x, y)) {
        Grid_setBit(pField->pFlagGrid, x, y, 0);
    }
}

#endif
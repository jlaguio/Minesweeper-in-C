/**
 * @ Author: MMMM
 * @ Create Time: 2024-01-29 17:00:34
 * @ Modified time: 2024-03-31 02:58:59
 * @ Description:
 * 
 * The main game file.
 */

#include "./engine.c"
#include "game/field.obj.h"
#include "game/game.c"
#include "game/stats.game.c"
#include "game/editor.game.c"

#include "utils/utils.asset.h"
#include "utils/utils.file.h"
#include "utils/utils.hashmap.h"
#include "utils/utils.graphics.h"
#include "utils/utils.thread.h"
#include "utils/utils.theme.h"
#include "utils/utils.grid.h"
#include "utils/utils.io.h"

#include <stdio.h>
#include <wchar.h>

int main() {

  // HashMap *pMyHashMap = HashMap_create();

  // for(int i = 0; i < 16; i++) {
  //   char *sKey = calloc(16, 1);
  //   sprintf(sKey, "%dasd%d", i, i);
    
  //   Animation *pTest = Animation_create(sKey, NULL, 0);
  //   HashMap_add(pMyHashMap, sKey, pTest);
  // }
  
  // char *sKeys[16];
  // HashMap_getKeys(pMyHashMap, sKeys);

  // for(int i = 0; i < 16; i++)
  //   printf("%s\n", sKeys[i]);

  // IO io;
  // IO_init(&io);
  // IO_exit(&io);

  Game test;
  Profile profile;
  test.pProfile = &profile;

  // Profile_register(&profile, "MOD", "KLANG");
  strcpy(profile.sCurrentProfile, "MOD");
  
  // Game_setup(&test,GAME_TYPE_CLASSIC, GAME_DIFFICULTY_EASY);
  Editor_setup(&test);
  Editor_setSaveName(&test, "BIGDEV");
  Editor_loadLevel(&test);

  Game_inspect(&test, 0, 0);
  Game_inspect(&test, 0, 8);
  Game_inspect(&test, 5, 2);
  Game_inspect(&test, 4, 9);
  Game_inspect(&test, 5, 9);
  // char *bruh = Game_getTime(&test);

  Stats_update(&test);

  while(1);

  return 0;
}
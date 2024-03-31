# MINEZ (in C)
<!-- 
<pre>
    ▀████▄     ▄███▀▀████▀▀███▄   ▀███▀▀███▀▀▀███ ███▀▀▀███         █      
      ████    ████    ██    ███▄    █    ██    ▀█ █▀   ███      ▀▄█████▄▀  
      █ ██   ▄█ ██    ██    █ ███   █    ██   █   ▀   ███       ██  █████  
      █  ██  █▀ ██    ██    █  ▀██▄ █    ██████      ███      ▀▀█████████▀▀
      █  ██▄█▀  ██    ██    █   ▀██▄█    ██   █  ▄  ███   ▄     ▀███████▀  
      █  ▀██▀   ██    ██    █     ███    ██     ▄█ ███   ▄█     ▀ ▀▀█▀▀ ▀  
    ▄███▄ ▀▀  ▄████▄▄████▄▄███▄    ██  ▄███████████████████         ▀      
</pre> -->

<!-- Styling -->
<style>
	* {
		box-sizing: border-box;
		font-family: system-ui, 'Segoe UI', sans-serif;
	}

	table {
		td:first-child {
			width: 64px;
			text-align: right;
		}

		th:first-child {
			width: 64px;
			text-align: right;
		}

		td {
			width: 480px;
			text-align: left;
			vertical-align: top;
			padding: 8px;
		}

		th {
			width: 480px;
			text-align: left;
			vertical-align: top;
			padding: 8px;
		}

		pre {
			font-family: monospace, Ubuntu;
			font-size: 12;
		}
	}
</style>

## 1 Introduction

> Sample gameplay (classic, easy)

![minez](README/gameplay.easy.png)

> Sample gameplay (classic, difficult)

![minez](README/gameplay.diff.png)

> Sample win screen (classic, difficult)

![minez](README/gameplay.win.diff.png)

> Sample lose screem (classic, difficult)

![minez](README/gameplay.lose.diff.png)

> The home page

![minez](README/minez.png)

> The login page

![minez](README/login.png)

Welcome to a rough implementation of minesweeper... in C!
Brought to you by MMMM.

## 2 Running the Program

### Windows 10

If you are using Windows 10 and have not migrated to using the modern Windows Terminal (you're still using conhost), then the following commands should suffice to run the program. Otherwise, refer to the commands for Windows 11; the Windows Terminal has a different set of features which don't allow our program to do some important stuff (like resizing the console).

```C
gcc main.c -o main
main run
```

### Windows 11

Fortunately, even after migrating to using the Windows Terminal, the legacy console (conhost) is still accessible when running it directly using the `conhost` command (or, alternatively, looking for it manually in your Windows folder). After the console appears, just follow the same commands outlined for Windows 10.

```
conhost
gcc main.c -o main
main run
```

### Unix-based

Need I say more?

```
gcc main.c -o main
./main run
```
---
> NOTE: If you do not specify the `run` parameter after calling the main executable, you will be greated with the following message:
> ![compilation-warning](README/compilation-warning.png)
> To actually run the program, you must specify the `run` parameter.
> 
> As an added feature, **one can also specify `run dev` instead**; this will run an alternative executable used for debugging.

## 3 Project Structure

```
📦machine-project
 ┣ 📂build
 ┃ ┣ 📂.debug
 ┃ ┃ ┣ 📜debug.txt
 ┃ ┃ ┣ 📜log.unix.txt
 ┃ ┃ ┗ 📜log.win.txt
 ┃ ┣ 📜minesweeper.unix.o
 ┃ ┗ 📜minesweeper.win.exe
 ┣ 📂src
 ┃ ┣ 📂assets
 ┃ ┃ ┣ 📜body-font.asset.txt
 ┃ ┃ ┣ 📜header-font.asset.txt
 ┃ ┃ ┣ 📜icon.asset.txt
 ┃ ┃ ┣ 📜intro.asset.txt
 ┃ ┃ ┗ 📜menu.asset.txt
 ┃ ┣ 📂data
 ┃ ┃ ┣ 📜accounts.data.txt
 ┃ ┃ ┗ 📜themes.data.txt
 ┃ ┣ 📂game
 ┃ ┃ ┣ 📜account.class.h
 ┃ ┃ ┗ 📜field.obj.h
 ┃ ┣ 📂pages
 ┃ ┃ ┣ 📜account.page.c
 ┃ ┃ ┣ 📜custom.page.c
 ┃ ┃ ┣ 📜help.page.c
 ┃ ┃ ┣ 📜intro.page.c
 ┃ ┃ ┣ 📜menu.page.c
 ┃ ┃ ┣ 📜play.page.c
 ┃ ┃ ┗ 📜settings.page.c
 ┃ ┣ 📂utils
 ┃ ┃ ┣ 📂unix
 ┃ ┃ ┃ ┣ 📜utils.io.unix.h
 ┃ ┃ ┃ ┣ 📜utils.string.unix.h
 ┃ ┃ ┃ ┗ 📜utils.thread.unix.h
 ┃ ┃ ┣ 📂win
 ┃ ┃ ┃ ┣ 📜utils.io.win.h
 ┃ ┃ ┃ ┣ 📜utils.string.win.h
 ┃ ┃ ┃ ┗ 📜utils.thread.win.h
 ┃ ┃ ┣ 📜utils.aes.h
 ┃ ┃ ┣ 📜utils.asset.h
 ┃ ┃ ┣ 📜utils.buffer.h
 ┃ ┃ ┣ 📜utils.component.h
 ┃ ┃ ┣ 📜utils.debug.h
 ┃ ┃ ┣ 📜utils.event.h
 ┃ ┃ ┣ 📜utils.file.h
 ┃ ┃ ┣ 📜utils.graphics.h
 ┃ ┃ ┣ 📜utils.grid.h
 ┃ ┃ ┣ 📜utils.hashmap.h
 ┃ ┃ ┣ 📜utils.io.h
 ┃ ┃ ┣ 📜utils.math.h
 ┃ ┃ ┣ 📜utils.page.h
 ┃ ┃ ┣ 📜utils.queue.h
 ┃ ┃ ┣ 📜utils.string.h
 ┃ ┃ ┣ 📜utils.theme.h
 ┃ ┃ ┣ 📜utils.thread.h
 ┃ ┃ ┗ 📜utils.types.h
 ┃ ┣ 📜engine.c
 ┃ ┣ 📜events.c
 ┃ ┣ 📜minesweeper.c
 ┃ ┗ 📜minesweeper.dev.c
 ┣ 📜main
 ┣ 📜main.c
 ┣ 📜main.exe
```
> **NOTE:** the README and its associated files are excluded here.
> Additionally, the `.debug` folder is not populated in the github repo
> but may contain additional files following the build process.

### 3.1 `build`, `src`, and `main.c`

The three main components of the file tree are the `build` and `src` folders, alongside the `main.c` file.


The `main.c` file basically just acts as a "makefile" for the entire project (since we couldn't really use a makefile without enforcing people to install it for our project). 

The `build` folder contains the resulting executables produced by `main.c`, which depend on the environment running the build step. Any additional logs and debug files are also created here and may be viewed in a text editor.

The `src` folder contains the actual source code that enables the game to operate. Any state and data files relevant to the program might also be created here (for instance, files containing information about user accounts, file containing program settings, and files containing text art assets and theme options).

### 3.2 `src/utils`

This folder basically contains a library of utilities that enable the game to function. None of the files here implement any of the game logic, and this library can be used for another program entirely. Nonetheless, it is important to note that some of the files contained in this folder depend on other utility files also included therein.

### 3.3 `src/pages`, `src/events.c`, `src/engine.c`, and `src/game`

### 3.4 `src/minesweeper.c` and `src/minesweeper.dev.c`

### 3.5 `src/assets` and `src/data`

## 4 Implementation Outline

### 4.1 Function Table

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>engine.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>1</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Engine_init(Engine *this) </pre></td>
		<td colspan="3"> Initializes the engine.
 This function is annotated differently because it does a lot of things.
 
<br></td>
	</tr>
	<tr>
		<td>2</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Engine_exit(Engine *this) </pre></td>
		<td colspan="3"> Do some clean up after the entire program runs.
 Frees whatever was allocated.
 
<br></td>
	</tr>
	<tr>
		<td>3</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Engine_main(
	p_obj pArgs_Engine,
	int tArg_NULL
) </pre></td>
		<td colspan="3"> The main thread of the engine.
 
<br></td>
	</tr>
	<tr>
		<td>4</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Engine_getState(Engine *this) </pre></td>
		<td colspan="3"> Returns the state of the engine.
 Returns a 1 when the engine is currently running.
 Returns a 0 when all its processes have exited.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>events.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>5</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char EventListener_keyPressed(void) </pre></td>
		<td colspan="3"> Listens for key presses.
 This function can wait for a key press or just return 0 when nothing happens.
 In this case, it waits for a key press but the implementation can vary.
 
<br></td>
	</tr>
	<tr>
		<td>6</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventHandler_keyPressed(
	p_obj pArgs_Event,
	p_obj pArgs2_EventStore
) </pre></td>
		<td colspan="3"> Handles key presses.
 Basically, what happens after a key is pressed.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>minesweeper.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>minesweeper.dev.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>settings.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>7</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Settings_init(
	EventStore *pSharedEventStore,
	ThemeManager *pSharedThemeManager
) </pre></td>
		<td colspan="3"> Sets certain keybinds in the event store.
 Sets the current theme in the theme manager.
 
<br></td>
	</tr>
	<tr>
		<td>8</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Settings_getKeybinds(
	int *dKeybindCount,
	char *sKeybindArray[]
) </pre></td>
		<td colspan="3"> Tells us what keybinds we have for the game.
 This function assumes that there is enough space on the output buffer.
 
<br></td>
	</tr>
	<tr>
		<td>9</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char Settings_getGameMoveUp(EventStore *pSharedEventStore) </pre></td>
		<td colspan="3"> Returns the key bound to the move up functionality.
 
<br></td>
	</tr>
	<tr>
		<td>10</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char Settings_getGameMoveDown(EventStore *pSharedEventStore) </pre></td>
		<td colspan="3"> Returns the key bound to the move down functionality.
 
<br></td>
	</tr>
	<tr>
		<td>11</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char Settings_getGameMoveLeft(EventStore *pSharedEventStore) </pre></td>
		<td colspan="3"> Returns the key bound to the move left functionality.
 
<br></td>
	</tr>
	<tr>
		<td>12</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char Settings_getGameMoveRight(EventStore *pSharedEventStore) </pre></td>
		<td colspan="3"> Returns the key bound to the move right functionality.
 
<br></td>
	</tr>
	<tr>
		<td>13</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char Settings_getGameToggleFlag(EventStore *pSharedEventStore) </pre></td>
		<td colspan="3"> Returns the key bound to the toggle flag functionality.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>editor.game.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>14</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Editor_setup(Game *this) </pre></td>
		<td colspan="3"> Initializes the game object.
 
<br></td>
	</tr>
	<tr>
		<td>15</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Editor_init(
	Game *this,
	int dWidth,
	int dHeight
) </pre></td>
		<td colspan="3"> Sets the size of the game field.
 
<br></td>
	</tr>
	<tr>
		<td>16</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Editor_setSaveName(
	Game *this,
	char *sName
) </pre></td>
		<td colspan="3"> Sets the name of the level for saving.
 
<br></td>
	</tr>
	<tr>
		<td>17</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Editor_getSaveName(Game *this) </pre></td>
		<td colspan="3"> Gets the name of the game object.
 
<br></td>
	</tr>
	<tr>
		<td>18</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Editor_levelExists(
	Game *this,
	char *sLevelName
) </pre></td>
		<td colspan="3"> Checks if a certain level already exists or if there are too many levels files already.
 
<br></td>
	</tr>
	<tr>
		<td>19</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Editor_levelAddable(
	Game *this,
	char *sLevelName
) </pre></td>
		<td colspan="3"> Returns whether or not we can still add another level (or too much).
 
<br></td>
	</tr>
	<tr>
		<td>20</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Editor_countMines(Game *this) </pre></td>
		<td colspan="3"> Returns the number of mines on the field.
 Returns 0 if no mines or if there are too many mines.
 Max number of mines is dWidth * dHeight - 1.
 
<br></td>
	</tr>
	<tr>
		<td>21</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Editor_loadLevel(Game *this) </pre></td>
		<td colspan="3"> Loads a level unto the game object.
 
<br></td>
	</tr>
	<tr>
		<td>22</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Editor_saveLevel(Game *this) </pre></td>
		<td colspan="3"> Saves a level into the levels folder.
 If this is called independent of Level_register, it overwrites duplicate files.
 
<br></td>
	</tr>
	<tr>
		<td>23</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Editor_register(Game* this) </pre></td>
		<td colspan="3"> Registers a new custom level into the .levels.data.txt file and saves it's contents in the same directory.
 If the level exists, the function terminates.
 
<br></td>
	</tr>
	<tr>
		<td>24</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Editor_addMine(Game *this) </pre></td>
		<td colspan="3"> Adds a mine on a tile and recomputes numbers.
 
<br></td>
	</tr>
	<tr>
		<td>25</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Editor_removeMine(Game *this) </pre></td>
		<td colspan="3"> Removes a mine from a tile and recomputes numbers.
 
<br></td>
	</tr>
	<tr>
		<td>26</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Editor_clearMines(Game *this) </pre></td>
		<td colspan="3"> Clears the mine grid.
 
<br></td>
	</tr>
	<tr>
		<td>27</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Editor_getErrorMessage(Game *this) </pre></td>
		<td colspan="3"> Returns a description of the most recent error from the editor.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>field.obj.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>28</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_init(
	Field *this,
	int dWidth,
	int dHeight
) </pre></td>
		<td colspan="3"> Initializes the field object.
 We give the field object a new instance of the grid class.
 Note that this time the return type is void since we're not treating this 
    construct as a class.
 
<br></td>
	</tr>
	<tr>
		<td>29</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_clearMines(Field *this) </pre></td>
		<td colspan="3"> Clears the mines on the mine grid.
 
<br></td>
	</tr>
	<tr>
		<td>30</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_clearFlags(Field *this) </pre></td>
		<td colspan="3"> Clears the flags on the flag grid.
 
<br></td>
	</tr>
	<tr>
		<td>31</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_populateRandom(
	Field *this,
	int dMines
) </pre></td>
		<td colspan="3"> Populates the mine grid with random mines.
 
<br></td>
	</tr>
	<tr>
		<td>32</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_populateCustom(
	Field *this,
	char *sPath
) </pre></td>
		<td colspan="3"> Populates the mine grid with mines from a custom level.
 
<br></td>
	</tr>
	<tr>
		<td>33</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_setNumbers(Field *this) </pre></td>
		<td colspan="3"> Specifies the number of mines adjacent to each tile.
 
<br></td>
	</tr>
	<tr>
		<td>34</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Field_inspect(
	Field *pField,
	int x,
	int y
) </pre></td>
		<td colspan="3"> Considers a tile inspected.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>game.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>35</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_setup(
	Game *this,
	GameType eGameType,
	GameDifficulty eGameDifficulty
) </pre></td>
		<td colspan="3"> Initializes the game object.
 
<br></td>
	</tr>
	<tr>
		<td>36</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_init(Game *this) </pre></td>
		<td colspan="3"> Sets up the field of the game based on the type and the difficulty.
 
<br></td>
	</tr>
	<tr>
		<td>37</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_end(
	Game *this,
	GameOutcome eOutcome
) </pre></td>
		<td colspan="3"> Ends the game.
 
<br></td>
	</tr>
	<tr>
		<td>38</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_clear(Game *this) </pre></td>
		<td colspan="3"> Clears the mines and the flags.
 
<br></td>
	</tr>
	<tr>
		<td>39</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Game_hasWon(Game *this) </pre></td>
		<td colspan="3"> Checks whether or not the game has been finished. 
 
<br></td>
	</tr>
	<tr>
		<td>40</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Game_isWon(Game *this) </pre></td>
		<td colspan="3"> Checks just the enum.
 
<br></td>
	</tr>
	<tr>
		<td>41</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_displayGrid(
	Game *this,
	char *sOutputBuffer
) </pre></td>
		<td colspan="3"> Creates a display of the grid as a text asset.
 
<br></td>
	</tr>
	<tr>
		<td>42</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_inspect(
	Game *this,
	int x,
	int y
) </pre></td>
		<td colspan="3"> Inspects a tile.
 
<br></td>
	</tr>
	<tr>
		<td>43</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_addFlag (Game *this) </pre></td>
		<td colspan="3"> Adds a flag on a tile only if it hasn't been inspected.
 
<br></td>
	</tr>
	<tr>
		<td>44</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_removeFlag(Game *this) </pre></td>
		<td colspan="3"> Removes a flag from a tile only if it currently has a flag.
 
<br></td>
	</tr>
	<tr>
		<td>45</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_pause(Game *this) </pre></td>
		<td colspan="3"> Pauses the game.
 
<br></td>
	</tr>
	<tr>
		<td>46</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_unpause(Game *this) </pre></td>
		<td colspan="3"> Unpauses the game.
 
<br></td>
	</tr>
	<tr>
		<td>47</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_incrementX(Game *this) </pre></td>
		<td colspan="3"> Increments the cursor along the x axis (to the right).
 Skips tiles that have already been inspected.
 
<br></td>
	</tr>
	<tr>
		<td>48</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_decrementX(Game *this) </pre></td>
		<td colspan="3"> Decrements the cursor along the x axis (to the left).
 Skips tiles that have already been inspected.
 
<br></td>
	</tr>
	<tr>
		<td>49</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_incrementY(Game *this) </pre></td>
		<td colspan="3"> Increments the cursor along the y axis (down).
 Skips tiles that have already been inspected.
 
<br></td>
	</tr>
	<tr>
		<td>50</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_decrementY(Game *this) </pre></td>
		<td colspan="3"> Decrements the cursor along the y axis (up).
 Skips tiles that have already been inspected.
 
<br></td>
	</tr>
	<tr>
		<td>51</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Game_getCharWidth(Game *this) </pre></td>
		<td colspan="3"> How many characters wide the grid is.
 
<br></td>
	</tr>
	<tr>
		<td>52</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Game_getCharHeight(Game *this) </pre></td>
		<td colspan="3"> How many characters tall the grid is.
 
<br></td>
	</tr>
	<tr>
		<td>53</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Game_isDone(Game *this) </pre></td>
		<td colspan="3"> Returns whether or not the game has ended.
 
<br></td>
	</tr>
	<tr>
		<td>54</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Game_getTime(Game *this) </pre></td>
		<td colspan="3"> Returns the time elapsed since the game started.
 
<br></td>
	</tr>
	<tr>
		<td>55</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Game_getMinesLeft(Game *this) </pre></td>
		<td colspan="3"> Returns the number of mines left.
 
<br></td>
	</tr>
	<tr>
		<td>56</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Game_getFPS(Game *this) </pre></td>
		<td colspan="3"> Returns how many fps the game is running at.
 Default is 32.
 
<br></td>
	</tr>
	<tr>
		<td>57</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Game_quit(Game *this) </pre></td>
		<td colspan="3"> Quits the current game.
 This sets the outcome of the game to GAME_OUTCOME_QUIT.
 
<br></td>
	</tr>
	<tr>
		<td>58</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Game_save(Game *this) </pre></td>
		<td colspan="3"> "Saves" the current game.
 Sets the save state to 1.
 
<br></td>
	</tr>
	<tr>
		<td>59</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Game_getEndMessage(Game *this) </pre></td>
		<td colspan="3"> Returns a description of how the game ended.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>profile.game.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>60</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Profile_init(Profile *this) </pre></td>
		<td colspan="3"> Initializes the profile object.
 
<br></td>
	</tr>
	<tr>
		<td>61</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Profile_login(
	Profile *this,
	char *sUsername,
	char *sPassword
) </pre></td>
		<td colspan="3"> Attempts to log into a profile given the credentials.
 This is some weak ass password storing (plain text bruh).
 
<br></td>
	</tr>
	<tr>
		<td>62</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Profile_register(
	Profile *this,
	char *sUsername,
	char *sPassword
) </pre></td>
		<td colspan="3"> Sets the active profile to the one indicated.
 
<br></td>
	</tr>
	<tr>
		<td>63</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Profile_delete(
	Profile *this,
	char *sUsername
) </pre></td>
		<td colspan="3"> Deletes a profile.
 
<br></td>
	</tr>
	<tr>
		<td>64</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Profile_save(char *sName) </pre></td>
		<td colspan="3"> Saves the data newly-created profile in its corresponding text file.
 
<br> //!! FIX THISS
 
<br></td>
	</tr>
	<tr>
		<td>65</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Profile_getErrorMessage(Profile *this) </pre></td>
		<td colspan="3"> Returns a description of the last error encountered by the profile object.
 
<br></td>
	</tr>
	<tr>
		<td>66</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">ProfileError Profile_getErrorId(Profile *this) </pre></td>
		<td colspan="3"> Returns the actual enum representing the latest error.
 
<br></td>
	</tr>
	<tr>
		<td>67</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Profile_setErrorId(
	Profile *this,
	ProfileError eError
) </pre></td>
		<td colspan="3"> Sets the error stored by the profile object.
 
<br></td>
	</tr>
	<tr>
		<td>68</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Profile_getCurrent(Profile *this) </pre></td>
		<td colspan="3"> Returns the name of the currently active profile.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>stats.game.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>69</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Stats_saveGame(Game *this) </pre></td>
		<td colspan="3"> Saves the information held by the most recent game.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>account.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>70</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_account(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>editor.interactive.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>71</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_editorI(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>editor.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>72</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_editor(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>help.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>73</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_help(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>login.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>74</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_login(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the logjn page.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>menu.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>75</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_menu(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>play.interactive.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>76</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_playI(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>play.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>77</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_play(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>settings.page.c</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>78</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageHandler_settings(p_obj pArgs_Page) </pre></td>
		<td colspan="3"> Configures the main menu.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.asset.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>79</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Asset *Asset_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the Asset class.
 
<br></td>
	</tr>
	<tr>
		<td>80</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Asset *Asset_init(
	Asset *this,
	char *sName,
	int dHeight,
	char *sContentArray[]
) </pre></td>
		<td colspan="3"> Initializes an instance of the Asset class.
 
<br></td>
	</tr>
	<tr>
		<td>81</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Asset *Asset_create(
	char *sName,
	int h,
	char *sContentArray[]
) </pre></td>
		<td colspan="3"> Creates an initialized instance of the Asset class.
<br></td>
	</tr>
	<tr>
		<td>82</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Asset_kill(Asset *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the Asset class.
 
<br></td>
	</tr>
	<tr>
		<td>83</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void AssetManager_init(AssetManager *this) </pre></td>
		<td colspan="3"> Initializes the asset manager.
 
<br></td>
	</tr>
	<tr>
		<td>84</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void AssetManager_exit(AssetManager *this) </pre></td>
		<td colspan="3"> Cleans up after the asset manager.

<br></td>
	</tr>
	<tr>
		<td>85</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void AssetManager_createAsset(
	AssetManager *this,
	char *sAssetKey,
	int h,
	char *sContentArray[]
) </pre></td>
		<td colspan="3"> Creates a new asset which is then appended to its hash map.
 
<br></td>
	</tr>
	<tr>
		<td>86</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char **AssetManager_getAssetText(
	AssetManager *this,
	char *sAssetKey
) </pre></td>
		<td colspan="3"> Retrieves an asset from its database of assets.
 It returns the content of that asset as opposed to a pointer to the asset object.
 
<br></td>
	</tr>
	<tr>
		<td>87</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int AssetManager_getAssetHeight(
	AssetManager *this,
	char *sAssetKey
) </pre></td>
		<td colspan="3"> Retrieves an asset from its database of assets.
 It returns the height of the asset.
 
<br></td>
	</tr>
	<tr>
		<td>88</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int AssetManager_getAssetWidth(
	AssetManager *this,
	char *sAssetKey
) </pre></td>
		<td colspan="3"> Retrieves an asset from its database of assets.
 It returns the default width of the asset.
 
<br></td>
	</tr>
	<tr>
		<td>89</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void AssetManager_createTextAsset(
	AssetManager *this,
	char *sText,
	char *sFont
) </pre></td>
		<td colspan="3"> Creates a new asset which is then appended to its hash map.
 This asset is a text asset drawn with the font provided.
 The provided font just refers to a set of characters drawn in Unicode.
 Note that the key is generated from both the text and the font. It is
    written as <sText>-<sFont>.
 
<br></td>
	</tr>
	<tr>
		<td>90</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void AssetManager_readAssetFile(
	AssetManager *this,
	char *sDelimeter,
	char *sFilepath
) </pre></td>
		<td colspan="3"> Reads sprites from an asset text file and converts them into instances of the asset class above.
 Honestly, it's okay if this file takes a while to execute because this is only run once and not
    during each frame anyway.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.buffer.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>91</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Buffer *Buffer_new() </pre></td>
		<td colspan="3"> Allocates memory for a new instance of the buffer class.
 
<br></td>
	</tr>
	<tr>
		<td>92</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Buffer *Buffer_init(
	Buffer *this,
	int dWidth,
	int dHeight,
	int dDefaultFG,
	int dDefaultBG
) </pre></td>
		<td colspan="3"> Initializes an instance of the buffer class.
 Sets its current length to 0.
 
<br></td>
	</tr>
	<tr>
		<td>93</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Buffer *Buffer_create(
	int dWidth,
	int dHeight,
	int dDefaultFG,
	int dDefaultBG
) </pre></td>
		<td colspan="3"> Creates an initialized instance of the buffer class.
 Sets its current length to 0.
 
<br></td>
	</tr>
	<tr>
		<td>94</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Buffer_kill(Buffer *this) </pre></td>
		<td colspan="3"> Frees the memory associated with an instance of the buffer class.
 
<br></td>
	</tr>
	<tr>
		<td>95</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Buffer_write(
	Buffer *this,
	int x,
	int y,
	int h,
	char *sBlock[]
) </pre></td>
		<td colspan="3"> Writes onto a rectangular section of the buffer, starting on (x, y).
 
<br></td>
	</tr>
	<tr>
		<td>96</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Buffer_contextRect(
	Buffer *this,
	int x,
	int y,
	int w,
	int h,
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Creates a context within the buffer.
 In this case, a context is a basically a rectangular slice of the 2d array where a certain style
    (be it a color change or something else) is applied to that slice.
 
<br></td>
	</tr>
	<tr>
		<td>97</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Buffer_contextCircle(
	Buffer *this,
	int x,
	int y,
	int r,
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Creates a circular context within the buffer.
 A context here is a basically a circular slice of the 2d array where a certain style
    (be it a color change or something else) is applied to that slice.
 
<br></td>
	</tr>
	<tr>
		<td>98</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Buffer_print(Buffer *this) </pre></td>
		<td colspan="3"> Outputs the buffer to the screen as one massive blob.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.component.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>99</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Component *Component_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the Component class.
 
<br></td>
	</tr>
	<tr>
		<td>100</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Component *Component_init(
	Component *this,
	char *sName,
	Component *pParent,
	int x,
	int y,
	int w,
	int h,
	int dAssetHeight,
	char **aAsset,
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Initializes an instance of the Component class.
 
<br></td>
	</tr>
	<tr>
		<td>101</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Component *Component_create(
	char *sName,
	Component *pParent,
	int x,
	int y,
	int w,
	int h,
	int dAssetHeight,
	char **aAsset,
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Creates an initialized instance of the Component class.
 
<br></td>
	</tr>
	<tr>
		<td>102</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Component_kill(Component *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the Component class.
 
<br></td>
	</tr>
	<tr>
		<td>103</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Component_add(
	Component *this,
	Component *pChild
) </pre></td>
		<td colspan="3"> Adds a component child to the children array.
 If there are too many children, nothing happens.
 The function returns 1 on success and 0 on failure.
 
<br></td>
	</tr>
	<tr>
		<td>104</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Component_config(Component *this) </pre></td>
		<td colspan="3"> Computes the position of the component based on parent components.
</td>
	</tr>
	<tr>
		<td>105</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_init(ComponentManager *this) </pre></td>
		<td colspan="3"> Allocates memory for an instance of the ComponentManager class.
 
<br></td>
	</tr>
	<tr>
		<td>106</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_exit(ComponentManager *this) </pre></td>
		<td colspan="3"> Exits the component manager.
 
<br></td>
	</tr>
	<tr>
		<td>107</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int ComponentManager_add(
	ComponentManager *this,
	char *sKey,
	char *sParentKey,
	int x,
	int y,
	int w,
	int h,
	int dAssetHeight,
	char **aAsset,
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Adds a component as a child of the specified component with the given id.
 
<br></td>
	</tr>
	<tr>
		<td>108</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_setPos(
	ComponentManager *this,
	char *sKey,
	int x,
	int y
) </pre></td>
		<td colspan="3"> Set the position of a specified component.
 
<br></td>
	</tr>
	<tr>
		<td>109</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_setSize(
	ComponentManager *this,
	char *sKey,
	int w,
	int h
) </pre></td>
		<td colspan="3"> Set the size of a specified component.
 
<br></td>
	</tr>
	<tr>
		<td>110</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_setZIndex(
	ComponentManager *this,
	char *sKey,
	int zIndex
) </pre></td>
		<td colspan="3"> Set the z index of a specified component.
 
<br></td>
	</tr>
	<tr>
		<td>111</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_setHidden(
	ComponentManager *this,
	char *sKey,
	int bIsHidden
) </pre></td>
		<td colspan="3"> Sets the visibility of a component.
 1 means hidden, 0 means visible.
 
<br></td>
	</tr>
	<tr>
		<td>112</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_setColor(
	ComponentManager *this,
	char *sKey,
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Set the color of a specified component.
 
<br></td>
	</tr>
	<tr>
		<td>113</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_setAsset(
	ComponentManager *this,
	char *sKey,
	int dAssetHeight,
	char **aAsset
) </pre></td>
		<td colspan="3"> Set the asset of the specified component.
 
<br></td>
	</tr>
	<tr>
		<td>114</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int ComponentManager_exists(
	ComponentManager *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Checks if a component exists within the manager.
 
<br></td>
	</tr>
	<tr>
		<td>115</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_render(
	ComponentManager *this,
	Buffer *pBuffer
) </pre></td>
		<td colspan="3"> Renders the components in the tree to the specified buffer.
 
<br></td>
	</tr>
	<tr>
		<td>116</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ComponentManager_reset(ComponentManager *this) </pre></td>
		<td colspan="3"> Removes all the components stored by the manager.
 Resets the component map too.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.event.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>117</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">EventListener *EventListener_new() </pre></td>
		<td colspan="3"> Allocates memory for a new event handler instance.
 
<br></td>
	</tr>
	<tr>
		<td>118</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">EventListener *EventListener_init(
	EventListener *this,
	f_event_listener fEventListener
) </pre></td>
		<td colspan="3"> Initializes an event listener instance.
 
<br></td>
	</tr>
	<tr>
		<td>119</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">EventListener *EventListener_create(f_event_listener fEventListener) </pre></td>
		<td colspan="3"> Creates an initialized event handler instance.
 
<br></td>
	</tr>
	<tr>
		<td>120</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventListener_kill(EventListener *this) </pre></td>
		<td colspan="3"> Deallocates the memory associated with an event listener instance. 
 
<br></td>
	</tr>
	<tr>
		<td>121</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char EventListener_trigger(EventListener *this) </pre></td>
		<td colspan="3"> Waits for the event trigger and returns the outcome of the event.
 This should return 0 when nothing happens.
 
<br></td>
	</tr>
	<tr>
		<td>122</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">EventHandler *EventHandler_new() </pre></td>
		<td colspan="3"> Allocates memory for a new event handler instance.
 
<br></td>
	</tr>
	<tr>
		<td>123</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">EventHandler *EventHandler_init(
	EventHandler *this,
	EventHandler *pNextHandler,
	f_event_handler fEventHandler
) </pre></td>
		<td colspan="3"> Initializes an event handler instance.
 
<br></td>
	</tr>
	<tr>
		<td>124</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">EventHandler *EventHandler_create(
	EventHandler *pNextHandler,
	f_event_handler fEventHandler
) </pre></td>
		<td colspan="3"> Creates an initialized event handler instance.
 
<br></td>
	</tr>
	<tr>
		<td>125</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventHandler_kill(EventHandler *this) </pre></td>
		<td colspan="3"> Deallocates the memory associated with an event handler instance. 
 
<br></td>
	</tr>
	<tr>
		<td>126</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventHandler_chain(
	EventHandler *this,
	EventHandler *pNextHandler
) </pre></td>
		<td colspan="3"> Appends an event handler after another one.
 
<br></td>
	</tr>
	<tr>
		<td>127</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Event *Event_new() </pre></td>
		<td colspan="3"> Allocates memory for a new event instance.
 
<br></td>
	</tr>
	<tr>
		<td>128</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Event *Event_init(
	Event *this,
	Event *pNextEvent,
	EventType eEventType,
	EventHandler *pHeadHandler,
	char cState
) </pre></td>
		<td colspan="3"> Initializes an event instance
 
<br></td>
	</tr>
	<tr>
		<td>129</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Event *Event_create(
	Event *pNextEvent,
	EventType eEventType,
	EventHandler *pHeadHandler,
	char cState
) </pre></td>
		<td colspan="3"> Creates a new initialized event.
 
<br></td>
	</tr>
	<tr>
		<td>130</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Event_kill(Event *this) </pre></td>
		<td colspan="3"> Releases an event instance from memory.
 
<br></td>
	</tr>
	<tr>
		<td>131</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Event_chain(
	Event *this,
	Event *pNextEvent
) </pre></td>
		<td colspan="3"> Chains a new event to an existing event.
 
<br></td>
	</tr>
	<tr>
		<td>132</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Event_resolve(
	Event *this,
	EventStore *pEventStore
) </pre></td>
		<td colspan="3"> Resolves an event.
 
<br></td>
	</tr>
	<tr>
		<td>133</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventStore_init(EventStore *this) </pre></td>
		<td colspan="3"> Initializes the event store.
 
<br></td>
	</tr>
	<tr>
		<td>134</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventStore_exit(EventStore *this) </pre></td>
		<td colspan="3"> Cleans up after the event store.
 
<br></td>
	</tr>
	<tr>
		<td>135</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventStore_set(
	EventStore *this,
	char *sKey,
	char cValue
) </pre></td>
		<td colspan="3"> This function sets the value of a certain entry to a given int.
 If the entry does not exist, a new entry is created. The values we store
    must be non-negative because the EventStore_get() function returns -1
    upon encountering an error.
 
<br></td>
	</tr>
	<tr>
		<td>136</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventStore_setString(
	EventStore *this,
	char *sValueKey,
	char *sStringKey
) </pre></td>
		<td colspan="3"> This function updates a string value stored by the event store object.
 The new value appended to the string is based on the current value stored in sValueKey.
 
<br></td>
	</tr>
	<tr>
		<td>137</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventStore_clearString(
	EventStore *this,
	char *sStringKey
) </pre></td>
		<td colspan="3"> This function clears the string specified by the key.
 
<br></td>
	</tr>
	<tr>
		<td>138</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char EventStore_get(
	EventStore *this,
	char *sKey
) </pre></td>
		<td colspan="3"> This function gets the value stored by the entry with a given key.
 
<br></td>
	</tr>
	<tr>
		<td>139</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *EventStore_getHistory(
	EventStore *this,
	char *sKey
) </pre></td>
		<td colspan="3"> This function gets the value stored by the entry with a given key.
 
<br></td>
	</tr>
	<tr>
		<td>140</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *EventStore_getString(
	EventStore *this,
	char *sKey
) </pre></td>
		<td colspan="3"> This function returns the value of the current input string indicated by the key.
 
<br></td>
	</tr>
	<tr>
		<td>141</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventStore_clear(
	EventStore *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Resets a certain value on the event store.
 
<br></td>
	</tr>
	<tr>
		<td>142</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_init(
	EventManager *this,
	EventStore *pEventStore
) </pre></td>
		<td colspan="3"> Initializes the event manager object.
 
<br></td>
	</tr>
	<tr>
		<td>143</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_exit(EventManager *this) </pre></td>
		<td colspan="3"> Cleans up after the event manager object.
 
<br></td>
	</tr>
	<tr>
		<td>144</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_createEvent(
	EventManager *this,
	EventType eEventType,
	char cState
) </pre></td>
		<td colspan="3"> Creates an event and appends it to the event chain.
 
<br></td>
	</tr>
	<tr>
		<td>145</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_triggerEvent(
	p_obj pArgs_EventManager,
	int tArg_eEventType
) </pre></td>
		<td colspan="3"> Waits for event triggers and creates events when they occur.
 Note that we specify event type here so that we can pass this function into different threads
    for each event type. That way, different event types dont block each other when triggering.
 
<br></td>
	</tr>
	<tr>
		<td>146</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_resolveEvent(
	p_obj pArgs_EventManager,
	int tArg_NULL
) </pre></td>
		<td colspan="3"> Resolves the head event of the chain.
 
<br></td>
	</tr>
	<tr>
		<td>147</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_createEventHandler(
	EventManager *this,
	EventType eEventType,
	f_event_handler fEventHandler
) </pre></td>
		<td colspan="3"> Once an event handler has been added to the chain, it cannot be removed.
 
<br></td>
	</tr>
	<tr>
		<td>148</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void EventManager_createEventListener(
	EventManager *this,
	EventType eEventType,
	f_event_listener fEventListener
) </pre></td>
		<td colspan="3"> Creates an event listener for the specified event type.
 Note that if an event listener already exists for that event type, it overwrites the original listener.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.file.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>149</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">File *File_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the File class.
 
<br></td>
	</tr>
	<tr>
		<td>150</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">File *File_init(
	File *this,
	char *sPath
) </pre></td>
		<td colspan="3"> Initializes an instance of the File class.
 
<br></td>
	</tr>
	<tr>
		<td>151</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">File *File_create(char *sPath) </pre></td>
		<td colspan="3"> Creates an initialized instance of the File class.
 
<br></td>
	</tr>
	<tr>
		<td>152</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void File_kill(File *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the File class.
 
<br></td>
	</tr>
	<tr>
		<td>153</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void File_readText(
	File *this,
	int n,
	int *h,
	char **sOutputBuffer
) </pre></td>
		<td colspan="3"> Reads the text file stored at the path.
 
<br></td>
	</tr>
	<tr>
		<td>154</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void File_readBinObject(
	File *this,
	int dOffset,
	int n,
	p_obj pOutputObject
) </pre></td>
		<td colspan="3"> Reads a single entry from the binary file stored at the path.
 
<br></td>
	</tr>
	<tr>
		<td>155</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void File_writeText(
	File *this,
	int n,
	char *sContentBuffer[]
) </pre></td>
		<td colspan="3"> Writes to a text file.
 This function only appends data to the existing content of the file.
 
<br></td>
	</tr>
	<tr>
		<td>156</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int File_writeBin(
	File *this,
	int n,
	p_obj pObject
) </pre></td>
		<td colspan="3"> Writes to a binary file.
 This function only appends data to the existing content of the file.
 If the given pointer to the data object is NULL, we just exit the function.
 
<br></td>
	</tr>
	<tr>
		<td>157</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void File_clear(File *this) </pre></td>
		<td colspan="3"> Clears the contents of a file.
 Literally just opens it in write mode.
 
<br></td>
	</tr>
	<tr>
		<td>158</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int File_exists(char *sFilename) </pre></td>
		<td colspan="3"> Checks if a file exists or not.
 
<br></td>
	</tr>
	<tr>
		<td>159</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int File_newFile(char *sFilename) </pre></td>
		<td colspan="3"> Creates a new file with the specified name.
 If the file already exists, it leaves it untouched.
 Returns 1 on success, 0 on failure.
 
<br></td>
	</tr>
	<tr>
		<td>160</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int File_remove(char *sFilename) </pre></td>
		<td colspan="3"> Removes a new file with the specified name.
 Returns 1 on success, 0 on failure.
 
<br></td>
	</tr>
	<tr>
		<td>161</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void File_freeBuffer(
	int n,
	char *sBuffer[]
) </pre></td>
		<td colspan="3"> Frees a buffer that a file created.
 Must be called after File_readText().
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.graphics.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>162</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Graphics_getCodeFG(color color) </pre></td>
		<td colspan="3"> Returns the sequence to modify the current color of the terminal.
 
<br></td>
	</tr>
	<tr>
		<td>163</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Graphics_getCodeBG(color color) </pre></td>
		<td colspan="3"> Returns the sequence to modify the current color of the background of the terminal.
 
<br></td>
	</tr>
	<tr>
		<td>164</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *Graphics_getCodeFGBG(
	color colorFG,
	color colorBG
) </pre></td>
		<td colspan="3"> Returns the sequence to modify the current color of the foreground AND background of the terminal.
 
<br></td>
	</tr>
	<tr>
		<td>165</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">float Graphics_getColorDist(
	color color1,
	color color2
) </pre></td>
		<td colspan="3"> Returns the "pythagorean distance" between two colors.
 
<br></td>
	</tr>
	<tr>
		<td>166</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">color Graphics_RGB(
	int r,
	int g,
	int b
) </pre></td>
		<td colspan="3"> Returns the color associated with a set of rgb values.
 
<br></td>
	</tr>
	<tr>
		<td>167</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Graphics_lerp(
	color color1,
	color color2,
	float fAmount
) </pre></td>
		<td colspan="3"> Lerps between two colors by the specified amount.
 
<br></td>
	</tr>
	<tr>
		<td>168</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Graphics_delCode(char *sCode) </pre></td>
		<td colspan="3"> Releases allocated memory.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.grid.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>169</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Grid *Grid_new() </pre></td>
		<td colspan="3"> Allocates memory for a new instance of the grid class.
 
<br></td>
	</tr>
	<tr>
		<td>170</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Grid *Grid_init(
	Grid *this,
	int dWidth,
	int dHeight
) </pre></td>
		<td colspan="3"> Initializes an instance of the grid class.
 If the function receives a width or height that is too large, 32 becomes
    the default initialization of that parameter.
 
<br></td>
	</tr>
	<tr>
		<td>171</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Grid *Grid_create(
	int dWidth,
	int dHeight
) </pre></td>
		<td colspan="3"> Creates an initialized instance of the grid class.
 Sets its current length to 0.
 
<br></td>
	</tr>
	<tr>
		<td>172</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Grid_kill(Grid *this) </pre></td>
		<td colspan="3"> Frees the memory associated with an instance of the grid class.
 
<br></td>
	</tr>
	<tr>
		<td>173</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Grid_getBit(
	Grid *this,
	int x,
	int y
) </pre></td>
		<td colspan="3"> Returns the value at an entry on the grid.
 This function assumes that x and y are within range of the dimensions of the grid.
 
<br></td>
	</tr>
	<tr>
		<td>174</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Grid_setBit(
	Grid *this,
	int x,
	int y,
	int n
) </pre></td>
		<td colspan="3"> Sets the value of a certain bit on the grid. 
 
<br></td>
	</tr>
	<tr>
		<td>175</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Grid_clear(
	Grid *this,
	int n
) </pre></td>
		<td colspan="3"> Clears the values stored by a grid instance (sets them all to 0 or 1).
 
<br></td>
	</tr>
	<tr>
		<td>176</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Grid_getCount(Grid *this) </pre></td>
		<td colspan="3"> Returns how many bits are turned on.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.hashmap.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>177</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">HashMapEntry *HashMapEntry_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the HashMapEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>178</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">HashMapEntry *HashMapEntry_init(
	HashMapEntry *this,
	char *sKey,
	p_obj pObject
) </pre></td>
		<td colspan="3"> Initializes an instance of the HashMapEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>179</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">HashMapEntry *HashMapEntry_create(
	char *sKey,
	p_obj pObject
) </pre></td>
		<td colspan="3"> Creates an initialized instance of the HashMapEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>180</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMapEntry_kill(HashMapEntry *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the HashMapEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>181</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">HashMap *HashMap_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the HashMap class.
 
<br></td>
	</tr>
	<tr>
		<td>182</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">HashMap *HashMap_init(HashMap *this) </pre></td>
		<td colspan="3"> Initializes an instance of the HashMap class.
 
<br></td>
	</tr>
	<tr>
		<td>183</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">HashMap *HashMap_create() </pre></td>
		<td colspan="3"> Creates an initialized instance of the HashMap class.
 
<br></td>
	</tr>
	<tr>
		<td>184</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMap_kill(HashMap *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the HashMap class.
 
<br></td>
	</tr>
	<tr>
		<td>185</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMap_resize(HashMap *this) </pre></td>
		<td colspan="3"> Resizes the hash map if the array starts to have too many collisions.
 Note that our hash can only grow in size. Resize here only accomodates us
    when we have *too much stuff*, and not too little (after removing a lot 
    of entries).
 
<br> PS I encountered some ferocious bugs trying to implement this routine.
 
<br></td>
	</tr>
	<tr>
		<td>186</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMap_add(
	HashMap *this,
	char *sKey,
	p_obj pObject
) </pre></td>
		<td colspan="3"> Adds a new entry into the hash map.
 
<br></td>
	</tr>
	<tr>
		<td>187</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">p_obj HashMap_get(
	HashMap *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Since we're abstracting how this function works, we return the actual object
    stored by the hash map at a certain location.
 This function returns NULL when the key is currently not in the hashmap.
 
<br></td>
	</tr>
	<tr>
		<td>188</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMap_set(
	HashMap *this,
	char *sKey,
	p_obj pObject
) </pre></td>
		<td colspan="3"> This function changes what object the entry with a certain key points to.
 Note that the original object must be freed first; otherwise, a memory leak
    will occur.
 
<br></td>
	</tr>
	<tr>
		<td>189</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMap_del(
	HashMap *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Removes an entry from the hashmap.
 Note that this also frees the object associated with the entry.
 
<br></td>
	</tr>
	<tr>
		<td>190</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void HashMap_getKeys(
	HashMap *this,
	char *sKeyArray[]
) </pre></td>
		<td colspan="3"> Returns all the keys in the hashmap.
 It is not advisable to call this function a lot, unless necessary (such as deleting all elements
    in the hashmap during clean up); this function defeats the purpose of using a hashmap because
    it iterates through all elements.
 This function assumes the target array is big enough to hold all keys.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.io.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.math.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>191</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Math_hash(
	char *sKey,
	int dMax
) </pre></td>
		<td colspan="3"> This is a hash function that extends one of the ones given here: 
    http://www.cse.yorku.ca/~oz/hash.html
 
<br></td>
	</tr>
	<tr>
		<td>192</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">float Math_lerp(
	float fStart,
	float fEnd,
	float fAmount
) </pre></td>
		<td colspan="3"> Linear interpolation function.
 
<br></td>
	</tr>
	<tr>
		<td>193</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">float Math_easeOut(
	float fValue,
	float fTarget,
	float fSpeed
) </pre></td>
		<td colspan="3"> An easing function used to make a value approach another value smoothly.
 We use a logarithmic speed system (since the rate of change here is proportional to 1/x,
    and the integral of that happens to be ln(x)).
 
<br></td>
	</tr>
	<tr>
		<td>194</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">float Math_easeIn(
	float fValue,
	float fTarget,
	float fSpeed
) </pre></td>
		<td colspan="3"> An easing function used to make a value approach another value smoothly.
 Here, we use a reciprocal slider for the speed variable.
 
<br></td>
	</tr>
	<tr>
		<td>195</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">float Math_dist1d(
	float a,
	float b
) </pre></td>
		<td colspan="3"> Computes the 1d distance between two points.
 Basically just the absolute value of their difference.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.page.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>196</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Page *Page_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the Page class.
 
<br></td>
	</tr>
	<tr>
		<td>197</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Page *Page_init(
	Page *this,
	AssetManager *pSharedAssetManager,
	EventStore *pSharedEventStore,
	ThemeManager *pSharedThemeManager,
	f_page_handler fHandler
) </pre></td>
		<td colspan="3"> Initializes an instance of the Page class.
 
<br></td>
	</tr>
	<tr>
		<td>198</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Page *Page_create(
	AssetManager *pSharedAssetManager,
	EventStore *pSharedEventStore,
	ThemeManager *pSharedThemeManager,
	f_page_handler fHandler
) </pre></td>
		<td colspan="3"> Creates an initialized instance of the Page class.
 
<br></td>
	</tr>
	<tr>
		<td>199</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_kill(Page *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the Page class.
 
<br></td>
	</tr>
	<tr>
		<td>200</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_render(Page *this) </pre></td>
		<td colspan="3"> Actually place things into the buffer
 
<br></td>
	</tr>
	<tr>
		<td>201</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setUserState(
	Page *this,
	char *sStateKey,
	char cData
) </pre></td>
		<td colspan="3"> Sets a specific user-defined state to the value provided.
 Note that user states can only store char data.
 
<br></td>
	</tr>
	<tr>
		<td>202</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char Page_getUserState(
	Page *this,
	char *sStateKey
) </pre></td>
		<td colspan="3"> Gets a specific user-defined state.
 Note that user states can only store char data.
 
<br></td>
	</tr>
	<tr>
		<td>203</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Page_update(Page *this) </pre></td>
		<td colspan="3"> Performs a single frame update of our page instance.
 Returns a boolean that indicates whether or not the page was able to update.
 
<br></td>
	</tr>
	<tr>
		<td>204</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_addComponent(
	Page *this,
	char *sKey,
	char *sParentKey,
	int x,
	int y,
	int w,
	int h,
	int dAssetHeight,
	char **aAsset,
	char *sColorFGKey,
	char *sColorBGKey
) </pre></td>
		<td colspan="3"> Adds a new component to the page.
 
<br></td>
	</tr>
	<tr>
		<td>205</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_addComponentAsset(
	Page *this,
	char *sKey,
	char *sParentKey,
	int x,
	int y,
	char *sColorFGKey,
	char *sColorBGKey,
	char *sAssetKey
) </pre></td>
		<td colspan="3"> Adds a component with the asset of a given key.
 Note that the width and height of the component are automatically determined by the asset.
 
<br></td>
	</tr>
	<tr>
		<td>206</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_addComponentText(
	Page *this,
	char *sKey,
	char *sParentKey,
	int x,
	int y,
	char *sColorFGKey,
	char *sColorBGKey,
	char *sText
) </pre></td>
		<td colspan="3"> Makes it easier to insert plain text into the page without having to convert the text into an asset.
 
<br></td>
	</tr>
	<tr>
		<td>207</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_addComponentContainer(
	Page *this,
	char *sKey,
	char *sParentKey,
	int x,
	int y
) </pre></td>
		<td colspan="3"> Adds a component with the no asset and no colors.
 Note that the width and height of the component may be determined by its children,
    depending on its alignment type.
 
<br></td>
	</tr>
	<tr>
		<td>208</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_addComponentContext(
	Page *this,
	char *sKey,
	char *sParentKey,
	int x,
	int y,
	int w,
	int h,
	char *sColorFGKey,
	char *sColorBGKey
) </pre></td>
		<td colspan="3"> Adds a component with the no asset and just colors.
 Note that the width and height of the component may be determined by its children,
    depending on its alignment type.
 
<br></td>
	</tr>
	<tr>
		<td>209</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_addComponentPopup(
	Page *this,
	char *sKey,
	int x,
	int y,
	int w,
	int h,
	char *sColorFGKey,
	char *sColorBGKey,
	char *sBodyText,
	char *sOption1,
	char *sOption2
) </pre></td>
		<td colspan="3"> Creates a popup component.
 Appends the component to the root element by default.
 The component is also screen centered by default.
 
<br></td>
	</tr>
	<tr>
		<td>210</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setComponentPos(
	Page *this,
	char *sKey,
	int x,
	int y
) </pre></td>
		<td colspan="3"> Changes the position of the component.
 
<br></td>
	</tr>
	<tr>
		<td>211</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setComponentSize(
	Page *this,
	char *sKey,
	int w,
	int h
) </pre></td>
		<td colspan="3"> Changes the size of the component.
 
<br></td>
	</tr>
	<tr>
		<td>212</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setComponentColor(
	Page *this,
	char *sKey,
	char *sColorFGKey,
	char *sColorBGKey
) </pre></td>
		<td colspan="3"> Changes the color of a component.
 
<br></td>
	</tr>
	<tr>
		<td>213</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setComponentText(
	Page *this,
	char *sKey,
	char *sText
) </pre></td>
		<td colspan="3"> Changes the text stored by a component.
 
<br></td>
	</tr>
	<tr>
		<td>214</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setComponentPopupText(
	Page *this,
	char *sKey,
	char *sText
) </pre></td>
		<td colspan="3"> Changes the text stored by a popup.
 
<br></td>
	</tr>
	<tr>
		<td>215</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setComponentPopupOptions(
	Page *this,
	char *sKey,
	char *sOption1,
	char *sOption2,
	char *sColorFGKey,
	char *sColorBGKey
) </pre></td>
		<td colspan="3"> Changes the text stored by a popup.
 
<br></td>
	</tr>
	<tr>
		<td>216</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_resetComponents(Page *this) </pre></td>
		<td colspan="3"> Resets the component tree of the page.
 
<br></td>
	</tr>
	<tr>
		<td>217</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_setNext(
	Page *this,
	char *sNext
) </pre></td>
		<td colspan="3"> Sets what page will be rendered next after the current page finishes running.
 
<br></td>
	</tr>
	<tr>
		<td>218</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_enableComponentPopup(
	Page *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Enables a popup.
 
<br></td>
	</tr>
	<tr>
		<td>219</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_disableComponentPopup(
	Page *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Disables a popup.
 Also saves the response of the user in the page state.
 
<br></td>
	</tr>
	<tr>
		<td>220</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_toggleComponentPopup(
	Page *this,
	char *sKey,
	char *sFGColorKey,
	char *sBGColorKey
) </pre></td>
		<td colspan="3"> Toggles a popup option.
 
<br></td>
	</tr>
	<tr>
		<td>221</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Page_readComponentPopup(
	Page *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Returns the response of the user to the popup.
 In other words, which option they selected.
 
<br></td>
	</tr>
	<tr>
		<td>222</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_idle(Page *this) </pre></td>
		<td colspan="3"> Sets the page status to PAGE_ACTIVE_IDLE.
 
<br></td>
	</tr>
	<tr>
		<td>223</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_activate(Page *this) </pre></td>
		<td colspan="3"> Sets the page status to PAGE_ACTIVE.
 It also resets the dT value of the page so animations can start over.
 
<br></td>
	</tr>
	<tr>
		<td>224</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_deactivate(Page *this) </pre></td>
		<td colspan="3"> Sets the page status to PAGE_INACTIVE.
 
<br></td>
	</tr>
	<tr>
		<td>225</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Page_nextStage(Page *this) </pre></td>
		<td colspan="3"> Increments the stage counter of the page.
 
<br></td>
	</tr>
	<tr>
		<td>226</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageManager_init(
	PageManager *this,
	AssetManager *pSharedAssetManager,
	EventStore *pSharedEventStore,
	ThemeManager *pSharedThemeManager
) </pre></td>
		<td colspan="3"> Initializes the page manager.
 
<br></td>
	</tr>
	<tr>
		<td>227</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageManager_exit(PageManager *this) </pre></td>
		<td colspan="3"> Exits the page manager.
 
<br></td>
	</tr>
	<tr>
		<td>228</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageManager_createPage(
	PageManager *this,
	char *sPageKey,
	f_page_handler fHandler
) </pre></td>
		<td colspan="3"> Creates a new page instance and stores it in the hashmap.
 
<br></td>
	</tr>
	<tr>
		<td>229</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int PageManager_getActiveState(PageManager *this) </pre></td>
		<td colspan="3"> Returns the state of the active page.
 
<br></td>
	</tr>
	<tr>
		<td>230</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageManager_setActive(
	PageManager *this,
	char *sPageKey
) </pre></td>
		<td colspan="3"> Sets the active page.
 
<br></td>
	</tr>
	<tr>
		<td>231</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageManager_update(PageManager *this) </pre></td>
		<td colspan="3"> Updates the active page.
 
<br></td>
	</tr>
	<tr>
		<td>232</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void PageManager_givePage(
	PageManager *this,
	char *sPageKey,
	p_obj pSharedObject
) </pre></td>
		<td colspan="3"> Gives a page a shared object.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.queue.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>233</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">QueueEntry *QueueEntry_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the QueueEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>234</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">QueueEntry *QueueEntry_init(
	QueueEntry *this,
	p_obj pObject
) </pre></td>
		<td colspan="3"> Initializes an instance of the QueueEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>235</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">QueueEntry *QueueEntry_create(p_obj pObject) </pre></td>
		<td colspan="3"> Creates an initialized instance of the QueueEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>236</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void QueueEntry_kill(QueueEntry *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the QueueEntry class.
 
<br></td>
	</tr>
	<tr>
		<td>237</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void QueueEntry_chain(
	QueueEntry *this,
	QueueEntry *pNext
) </pre></td>
		<td colspan="3"> Chains another entry unto the specified entry.
 
<br></td>
	</tr>
	<tr>
		<td>238</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Queue *Queue_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the Queue class.
 
<br></td>
	</tr>
	<tr>
		<td>239</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Queue *Queue_init(Queue *this) </pre></td>
		<td colspan="3"> Initializes an instance of the Queue class.
 
<br></td>
	</tr>
	<tr>
		<td>240</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Queue *Queue_create() </pre></td>
		<td colspan="3"> Creates an initialized instance of the Queue class.
 
<br></td>
	</tr>
	<tr>
		<td>241</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Queue_kill(Queue *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the Queue class.
 
<br></td>
	</tr>
	<tr>
		<td>242</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">p_obj Queue_getHead(Queue *this) </pre></td>
		<td colspan="3"> Returns the object stored at the head of the queue.
 
<br></td>
	</tr>
	<tr>
		<td>243</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Queue_push(
	Queue *this,
	p_obj pObject
) </pre></td>
		<td colspan="3"> Pushes an entry to the end of the queue.
 
<br></td>
	</tr>
	<tr>
		<td>244</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Queue_pop(Queue *this) </pre></td>
		<td colspan="3"> Removes an entry from the head of the queue.
 Note that this also frees the instance from memory, BUT 
    it DOESN'T free the pObject member of the entry.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.string.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>245</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_create(char *sString) </pre></td>
		<td colspan="3"> Allocates a piece of memory for a string.
 
<br></td>
	</tr>
	<tr>
		<td>246</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_alloc(int dLength) </pre></td>
		<td colspan="3"> Allocates a piece of memory for a string GIVEN the size.
 
<br></td>
	</tr>
	<tr>
		<td>247</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_clear(char *string) </pre></td>
		<td colspan="3"> Clears a string (sets everything to 0).
 
<br></td>
	</tr>
	<tr>
		<td>248</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_kill(char *sString) </pre></td>
		<td colspan="3"> Deallocates a string.
 This is here more for code readability.
 
<br></td>
	</tr>
	<tr>
		<td>249</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int String_isStartChar(char c) </pre></td>
		<td colspan="3"> Checks whether or not the character represents the start of a "compound" character (We refer to a character as 
    compound if it needs more than one char instances to be represented, eg UTF-8 characters).
 
<br></td>
	</tr>
	<tr>
		<td>250</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int String_isChar(char c) </pre></td>
		<td colspan="3"> Checks whether or not the character is part of a longer character encoding.
 
<br></td>
	</tr>
	<tr>
		<td>251</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int String_charCount(char *string) </pre></td>
		<td colspan="3"> Gets the number of characters in a string, including multi-byte characters.
 
<br></td>
	</tr>
	<tr>
		<td>252</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char String_getLast(char *string) </pre></td>
		<td colspan="3"> Returns the last character in a string.
 
<br></td>
	</tr>
	<tr>
		<td>253</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_keyAndId(
	char *sKey,
	char *sKeyName,
	int sKeyId
) </pre></td>
		<td colspan="3"> Creates a key with the following format: <key_name>-<key_id>.
 
<br></td>
	</tr>
	<tr>
		<td>254</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_keyAndChar(
	char *sKey,
	char *sKeyName,
	char sKeyChar
) </pre></td>
		<td colspan="3"> Creates a key with the following format: <key_name>-<key_char>.
 
<br></td>
	</tr>
	<tr>
		<td>255</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_keyAndStr(
	char *sKey,
	char *sKeyName,
	char *sKeyStr
) </pre></td>
		<td colspan="3"> Creates a key with the following format: <key_name>-<key_str>.
 
<br></td>
	</tr>
	<tr>
		<td>256</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_join(
	char *sDelimeter,
	char *sTerminator,
	int dWrapLength,
	...
) </pre></td>
		<td colspan="3"> Joins multiple strings together with the specified sequence.
 This function always assumes that the last argument is equal to the terminator.
 
<br></td>
	</tr>
	<tr>
		<td>257</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_repeat(
	char *sUnit,
	int dLength
) </pre></td>
		<td colspan="3"> Repeat a certain string pattern before a certain length is reached.
 
<br></td>
	</tr>
	<tr>
		<td>258</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_renderEscChar(char c) </pre></td>
		<td colspan="3"> Converts an escape character into an escaped sequence of characters.
 If the character is not an escape character, the function returns the original char.
 
<br></td>
	</tr>
	<tr>
		<td>259</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int String_isValidFilename(char *sFilename) </pre></td>
		<td colspan="3"> Checks if a string has only valid characters. 
 
<br></td>
	</tr>
	<tr>
		<td>260</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int String_isValidChar(char c) </pre></td>
		<td colspan="3"> Returns whether or not a character is not an escape char.
 
<br></td>
	</tr>
	<tr>
		<td>261</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_replace(
	char *string,
	char cOld,
	char cNew
) </pre></td>
		<td colspan="3"> Leaves the original string untouched.
 Replaces every instance of a character with another character.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.theme.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>262</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Theme *Theme_new() </pre></td>
		<td colspan="3"> Allocates memory for an instance of the Theme class.
 
<br></td>
	</tr>
	<tr>
		<td>263</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Theme *Theme_init(Theme *this) </pre></td>
		<td colspan="3"> Initializes an instance of the Theme class.
 
<br></td>
	</tr>
	<tr>
		<td>264</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Theme *Theme_create() </pre></td>
		<td colspan="3"> Creates an initialized instance of the Theme class.
 
<br></td>
	</tr>
	<tr>
		<td>265</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Theme_kill(Theme *this) </pre></td>
		<td colspan="3"> Deallocates the memory of an instance of the Theme class.
 
<br></td>
	</tr>
	<tr>
		<td>266</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Theme_addColor(
	Theme* this,
	char *sKey,
	color c
) </pre></td>
		<td colspan="3"> Adds a new color to the theme given the provided key.
 
<br></td>
	</tr>
	<tr>
		<td>267</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">color Theme_getDarker(
	Theme *this,
	char *sKey,
	float fAmount
) </pre></td>
		<td colspan="3"> Gets a darker version of a specific color from the current theme.
 The degree of darkening is also provided, where
    0.0 represents no darkening at all.
    0.5 is a 50-50 combination of the selected color and black.
    1.0 represnts total black.
 
<br></td>
	</tr>
	<tr>
		<td>268</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">color Theme_getLighter(
	Theme *this,
	char *sKey,
	float fAmount
) </pre></td>
		<td colspan="3"> Gets a lighter version of a specific color from the current theme.
 The degree of lightening is also provided, where
    0.0 represents no lightening at all.
    0.5 is a 50-50 combination of the selected color and white.
    1.0 represnts total white.
 
<br></td>
	</tr>
	<tr>
		<td>269</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">color Theme_getColor(
	Theme *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Simply returns the color referred to by the given key.
</td>
	</tr>
	<tr>
		<td>270</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThemeManager_init(ThemeManager *this) </pre></td>
		<td colspan="3"> Creates a default theme which the program uses.
 
<br></td>
	</tr>
	<tr>
		<td>271</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThemeManager_exit(ThemeManager *this) </pre></td>
		<td colspan="3"> Exits the theme manager.
 
<br></td>
	</tr>
	<tr>
		<td>272</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThemeManager_setActive(
	ThemeManager *this,
	char *sKey
) </pre></td>
		<td colspan="3"> Changes the current active theme.
 
<br></td>
	</tr>
	<tr>
		<td>273</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">color ThemeManager_getActive(
	ThemeManager* this,
	char *sKey
) </pre></td>
		<td colspan="3"> Gets a color from the active theme referred to by the provided key. 
 
<br></td>
	</tr>
	<tr>
		<td>274</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThemeManager_readThemeFile(
	ThemeManager *this,
	char *sFilepath
) </pre></td>
		<td colspan="3"> Reads and parses the themes contained in a themes file.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.thread.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>275</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">ThreadManager *ThreadManager_init(ThreadManager *this) </pre></td>
		<td colspan="3"> Initializes the thread manager variables.
 
<br></td>
	</tr>
	<tr>
		<td>276</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadManager_exit(ThreadManager *this) </pre></td>
		<td colspan="3"> Cleans up the state of the thread manager.
 
<br></td>
	</tr>
	<tr>
		<td>277</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadManager_createThread(
	ThreadManager *this,
	char *sThreadKey,
	char *sMutexKey,
	f_void_callback fCallee,
	p_obj pArgs_ANY,
	int tArg_ANY
) </pre></td>
		<td colspan="3"> Creates a new thread object instance and adds it to the hashmap.
 
<br></td>
	</tr>
	<tr>
		<td>278</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadManager_createMutex(
	ThreadManager *this,
	char *sMutexKey
) </pre></td>
		<td colspan="3"> Creates a new mutex object instance and adds it to the hashmap.
 Note that once a mutex has been created, it cannot be destroyed unless we wish to destroy
    all the mutexes. This is a safety feature to prevent any undefined behaviour. (We don't
    have a function for the ThreadManager struct that deletes a single Mutex).
 
<br></td>
	</tr>
	<tr>
		<td>279</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadManager_killThread(
	ThreadManager *this,
	char *sThreadKey
) </pre></td>
		<td colspan="3"> Terminates the thread with the given index in the hashmap.
 Also deallocates the memory associated with its object.
 
<br> Note that what happens here is the following:
    (1) The function releases the state mutex associated with the thread.
    (2) The pointer to the thread is then deleted within the array (although the instance is still in memory).
    (3) The thread, upon realizing that its state mutex is free, cleans up after itself and deletes its instance.
          It does this by using the Thread_kill() function, which it calls thereafter.
 
<br></td>
	</tr>
	<tr>
		<td>280</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadManager_lockMutex(
	ThreadManager *this,
	char *sMutexKey
) </pre></td>
		<td colspan="3"> Locks the mutex with a given key.
 Note that this function does not terminate until it gets a handle to the mutex.
 
<br></td>
	</tr>
	<tr>
		<td>281</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadManager_unlockMutex(
	ThreadManager *this,
	char *sMutexKey
) </pre></td>
		<td colspan="3"> Unlocks the data mutex of the thread with a given index.
 This function returns 1 on success, and 0 on failure.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.types.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.io.unix.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>282</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_init(struct IO *this) </pre></td>
		<td colspan="3"> Sets up some stuff for IO handling.
 Overrides default terminal settings so I can replicate getch behaviour on Unix-based OS's.
 
<br></td>
	</tr>
	<tr>
		<td>283</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int IO_getWidth() </pre></td>
		<td colspan="3"> Helper function that returns the width of the console.
 Note that this function is responsive to resizing.
 
<br></td>
	</tr>
	<tr>
		<td>284</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int IO_getHeight() </pre></td>
		<td colspan="3"> Helper function that returns the height of the console.
 Note that this function is responsive to resizing.
 
<br></td>
	</tr>
	<tr>
		<td>285</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int IO_setSize(
	int dWidth,
	int dHeight
) </pre></td>
		<td colspan="3"> A helper function that resizes the console window.
 Unfortunately, I could not find a POSIX-compliant implementation.
 This is just here as a dummy function.
 
<br></td>
	</tr>
	<tr>
		<td>286</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_setBuffer(int dSize) </pre></td>
		<td colspan="3"> Set the buffer size of the output stream.
 
<br></td>
	</tr>
	<tr>
		<td>287</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_resetCursor() </pre></td>
		<td colspan="3"> Resets the cursor position to the start of the terminal.
</td>
	</tr>
	<tr>
		<td>288</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_clear() </pre></td>
		<td colspan="3"> Helper function that clears the console.
</td>
	</tr>
	<tr>
		<td>289</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_flushBuffer() </pre></td>
		<td colspan="3"> Flush the current output buffer, if ever there's still stuff there.
</td>
	</tr>
	<tr>
		<td>290</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char IO_readChar() </pre></td>
		<td colspan="3"> Helper function that gets a single character without return key.
 
<br></td>
	</tr>
	<tr>
		<td>291</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_exit(struct IO *this) </pre></td>
		<td colspan="3"> Clean up the stuff I used.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.string.unix.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>292</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_print(char *string) </pre></td>
		<td colspan="3"> Prints a string.
 
<br></td>
	</tr>
	<tr>
		<td>293</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_toUpper(char *string) </pre></td>
		<td colspan="3"> Converts a string to upper case.
 This thing leaks memory...
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.thread.unix.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>294</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Mutex *Mutex_new() </pre></td>
		<td colspan="3"> Allocates memory for a new instance of the mutex class.
 
<br></td>
	</tr>
	<tr>
		<td>295</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Mutex *Mutex_init(
	Mutex *this,
	char *sName
) </pre></td>
		<td colspan="3"> Initializes the instance of the mutex class we pass to the function.
 
<br></td>
	</tr>
	<tr>
		<td>296</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Mutex *Mutex_create(char *sName) </pre></td>
		<td colspan="3"> Creates an initialized mutex instance.
 
<br></td>
	</tr>
	<tr>
		<td>297</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Mutex_kill(Mutex *this) </pre></td>
		<td colspan="3"> Frees the memory to an instance of the mutex class.
 
<br></td>
	</tr>
	<tr>
		<td>298</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Mutex_lock(Mutex *this) </pre></td>
		<td colspan="3"> Locks a mutex.
 Note that this function will wait indefinitely until it is able to lock the mutex.
 
<br></td>
	</tr>
	<tr>
		<td>299</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Mutex_lockTimed(
	Mutex *this,
	int dMillis
) </pre></td>
		<td colspan="3"> Locks a mutex unless a timeout is reached.
 Note that this function will wait only until the specified amount of time.
 
<br></td>
	</tr>
	<tr>
		<td>300</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Mutex_unlock(Mutex *this) </pre></td>
		<td colspan="3"> Frees a mutex and makes it available for other threads.
 Assumes that the caller is the one who currently holds the mutex.
 
<br></td>
	</tr>
	<tr>
		<td>301</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Thread *Thread_new() </pre></td>
		<td colspan="3"> Allocates memory for a new thread object instance.
 Note that this does not allocate memory for a thread but rather a *thread object*.
    The thread object refers to the struct above, which stores information about
    the thread, not the actual memory needed by the thread.
 The function returns NULL when the allocation fails.
 
<br></td>
	</tr>
	<tr>
		<td>302</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Thread *Thread_init(
	Thread *this,
	char *sName,
	Mutex *pStateMutex,
	Mutex *pDataMutex,
	f_void_callback fCallee,
	p_obj pArgs_ANY,
	int tArg_ANY
) </pre></td>
		<td colspan="3"> Initializes an instance of the thread class.
 Returns the initialized instance.
 
<br></td>
	</tr>
	<tr>
		<td>303</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Thread *Thread_create(
	char *sName,
	Mutex *pStateMutex,
	Mutex *pDataMutex,
	f_void_callback fCallee,
	p_obj pArgs_ANY,
	int tArg_ANY
) </pre></td>
		<td colspan="3"> Creates a new thread object with initialized parameters.
 Returns the initialized instance.
 
<br></td>
	</tr>
	<tr>
		<td>304</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Thread_kill(Thread *this) </pre></td>
		<td colspan="3"> Terminates a thread then destroys a Thread object instance and frees the memory of the object.
</td>
	</tr>
	<tr>
		<td>305</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void *ThreadHandler(void *pThread) </pre></td>
		<td colspan="3"> Executes the callback function assigned to the thread.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.io.win.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>306</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_init(struct IO *this) </pre></td>
		<td colspan="3"> Stuff to set up for Windows.
 In this case, we want the Windows console to understand ANSI escape sequences.
 
<br></td>
	</tr>
	<tr>
		<td>307</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int IO_getWidth() </pre></td>
		<td colspan="3"> Helper function that returns the width of the console.
 Note that this function is responsive to resizing.
 
<br></td>
	</tr>
	<tr>
		<td>308</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int IO_getHeight() </pre></td>
		<td colspan="3"> Helper function that returns the height of the console.
 Note that this function is responsive to resizing.
 
<br></td>
	</tr>
	<tr>
		<td>309</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int IO_setSize(
	int dWidth,
	int dHeight
) </pre></td>
		<td colspan="3"> A helper function that resizes the console window.
 This function only works on Windows (I could not find an implementation for Unix users).
 
<br> Note that the function is implemented this way BECAUSE: 
    (1) the buffer size apparently cannot be smaller than the console size AND
    (2) the console size cannot be bigger than the screen buffer.
 
<br> By shrinking the window size to the absolute minimum, we spare ourselves from "crushing" the buffer size into the window size when shrinking.
 It also prevents the window size from "crashing" into the buffer when making it bigger.
 When I tried using a rudimentary implementation that did without the minWIndowSize step, some nasty scrollbars appeared on the side.
 
<br></td>
	</tr>
	<tr>
		<td>310</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_setBuffer(int dSize) </pre></td>
		<td colspan="3"> Set the buffer size of the output stream.
 
<br></td>
	</tr>
	<tr>
		<td>311</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_resetCursor() </pre></td>
		<td colspan="3"> Resets the cursor position to the start of the terminal.
</td>
	</tr>
	<tr>
		<td>312</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_clear() </pre></td>
		<td colspan="3"> Helper function that clears the console.
</td>
	</tr>
	<tr>
		<td>313</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_flushBuffer() </pre></td>
		<td colspan="3"> Flush the current output buffer, if ever there's still stuff there.
</td>
	</tr>
	<tr>
		<td>314</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char IO_readChar() </pre></td>
		<td colspan="3"> Helper function that gets a single character without return key.
 
<br></td>
	</tr>
	<tr>
		<td>315</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void IO_exit(struct IO *this) </pre></td>
		<td colspan="3"> This only exists mainly because I need to do some housekeeping for Unix-based OS's.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.string.win.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>316</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void String_print(char *string) </pre></td>
		<td colspan="3"> Prints a string.
 
<br></td>
	</tr>
	<tr>
		<td>317</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">char *String_toUpper(char *string) </pre></td>
		<td colspan="3"> Converts a string to upper case.
 THIS MUTATES THE ORIGINAL STRING.
 
<br></td>
	</tr>
</table>

<table>
	<tr>
		<th> # </th>
		<th colspan="2"> Functions in <code>utils.thread.win.h</code> </th>
		<th colspan="4"> Description </th>
	</tr>
	<tr>
		<td>318</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Mutex *Mutex_new() </pre></td>
		<td colspan="3"> Allocates memory for a new instance of the mutex class.
 
<br></td>
	</tr>
	<tr>
		<td>319</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Mutex *Mutex_init(
	Mutex *this,
	char *sName
) </pre></td>
		<td colspan="3"> Initializes the instance of the mutex class we pass to the function.
 
<br></td>
	</tr>
	<tr>
		<td>320</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Mutex *Mutex_create(char *sName) </pre></td>
		<td colspan="3"> Creates an initialized mutex instance.
 
<br></td>
	</tr>
	<tr>
		<td>321</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Mutex_kill(Mutex *this) </pre></td>
		<td colspan="3"> Frees the memory to an instance of the mutex class.
 
<br></td>
	</tr>
	<tr>
		<td>322</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Mutex_lock(Mutex *this) </pre></td>
		<td colspan="3"> Locks a mutex.
 Note that this function will wait indefinitely until it is able to lock the mutex.
 
<br></td>
	</tr>
	<tr>
		<td>323</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">int Mutex_lockTimed(
	Mutex *this,
	int dMillis
) </pre></td>
		<td colspan="3"> Locks a mutex unless a timeout is reached.
 Note that this function will wait only until the specified amount of time.
 
<br></td>
	</tr>
	<tr>
		<td>324</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Mutex_unlock(Mutex *this) </pre></td>
		<td colspan="3"> Frees a mutex and makes it available for other threads.
 Assumes that the caller is the one who currently holds the mutex.
 
<br></td>
	</tr>
	<tr>
		<td>325</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Thread *Thread_new() </pre></td>
		<td colspan="3"> Allocates memory for a new thread object instance.
 Note that this does not allocate memory for a thread but rather a *thread object*.
    The thread object refers to the struct above, which stores information about
    the thread, not the actual memory needed by the thread.
 The function returns NULL when the allocation fails.
 
<br></td>
	</tr>
	<tr>
		<td>326</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Thread *Thread_init(
	Thread *this,
	char *sName,
	Mutex *pStateMutex,
	Mutex *pDataMutex,
	f_void_callback fCallee,
	p_obj pArgs_ANY,
	int tArg_ANY
) </pre></td>
		<td colspan="3"> Initializes an instance of the thread class.
 Returns the initialized instance.
 
<br></td>
	</tr>
	<tr>
		<td>327</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">Thread *Thread_create(
	char *sName,
	Mutex *pStateMutex,
	Mutex *pDataMutex,
	f_void_callback fCallee,
	p_obj pArgs_ANY,
	int tArg_ANY
) </pre></td>
		<td colspan="3"> Creates a new thread object with initialized parameters.
 Returns the initialized instance.
 
<br></td>
	</tr>
	<tr>
		<td>328</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void Thread_kill(Thread *this) </pre></td>
		<td colspan="3"> Terminates a thread then destroys a Thread object instance and frees the memory of the object.
</td>
	</tr>
	<tr>
		<td>329</td>
		<td colspan="3"><pre style="background: 0; white-space: pre-wrap;">void ThreadHandler(void *pThread) </pre></td>
		<td colspan="3"> Executes the callback function assigned to the thread.
 
<br></td>
	</tr>
</table>

## 5 Test Script

## 6 About the Authors 
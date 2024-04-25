Tyler Penn - c2027879

https://github.com/pennt04/Level5_ProjectLua

My Changes:
1) I added the mothership sprite to Lua
This means you can easily change the player's sprite for the entire program in 1 place

2) I added the mothership position vector to Lua
This means you can easily change the player's spawn location wihtout having to look for the specific code (potentially in multiple places)

3) I added the lasers sprite to Lua
This means you can easily change all of the lasers' sprites for the entire program in 1 place

4) I added the ufos sprite to Lua
This means you can easily change all of the ufo sprites for the entire program in 1 place

5) I added the laser spawn offet to the player's lasers to Lua
This means you can easily align the spawn location of the laser relative to the player's sprite

6) I added the laser spawn offset to the ufo's lasers to Lua
This means you can easily align the spawn location of the laser relative to the ufo sprite

7) I added player "move left" function to Lua
This means you can now access both player movement functions from Lua for safer, centralized changes
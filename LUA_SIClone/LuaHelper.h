#pragma once

//Inclusions
#include <string>
#include <functional>
#include<map>

//Lua specific inclusions++
extern "C"
{
#include "../lua-5.4.4/include/lua.h"
#include "../lua-5.4.4/include/lauxlib.h"
#include "../lua-5.4.4/include/lualib.h"
}

//add lua library to dependency list
#ifdef _WIN32
#pragma comment(lib, "../lua-5.4.4/liblua54.a")
#endif

//function for error checking
bool LuaOK(lua_State* L, int id);


////functions for variable retrieval 

//get int from lua
int LuaGetInt(lua_State* L, const std::string& name);

//get string from lua
std::string LuaGetString(lua_State* L, const std::string& name);

//get bool from lua
bool LuaGetBool(lua_State* L, const std::string& name);

//get float from lua
float LuaGetFloat(lua_State* L, const std::string& name);

//get double from lua
double LuaGetDouble(lua_State* L, const std::string& name);


//function for vector2
struct Vector2
{
	int x, y;

	void LuaGet(lua_State* L, const std::string& name);
};



////functions
int CallRandomNumber(lua_State* L, const std::string& name);

void CallMoveRight(lua_State* L, const std::string& name, float& x_val, float& frame_val);






void CallVoidVoidCFunc(lua_State* L, const std::string& name);
//Inclusions
#include <assert.h>
#include <iostream> //for cout, endl
using namespace std; //for LUA

//Header inclusion
#include "LuaHelper.h"


//function for error checking
bool LuaOK(lua_State* L, int id)
{
	if (id != LUA_OK) //if lua incounters an error
	{
		cout << lua_tostring(L, -1) << endl; //print out the error
		return false;
	}
	return true;
}


////functions for variable retrieval 

//get int from lua
int LuaGetInt(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable + its name from lua
	if (!lua_isinteger(L, -1)) //error checking
		assert(false);
	return (int)lua_tointeger(L, -1); //return value as int
}

//get string from lua
std::string LuaGetString(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable + its name from lua
	if (!lua_isstring(L, -1)) //error checking
		assert(false);
	return lua_tostring(L, -1); //return value as string
}

//get bool from lua
bool LuaGetBool(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable + its name from lua
	if (!lua_isboolean(L, -1)) //error checking
		assert(false);
	return (bool)lua_toboolean(L, -1); //return value as bool
}

//get float from lua
float LuaGetFloat(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable + its name from lua
	if (!lua_isnumber(L, -1)) //error checking
		assert(false);
	return (float)lua_tonumber(L, -1); //return value as float
}

//get double from lua
double LuaGetDouble(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable + its name from lua
	if (!lua_isnumber(L, -1)) //error checking
		assert(false);
	return (double)lua_tonumber(L, -1); //return value as double
}



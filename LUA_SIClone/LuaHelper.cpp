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
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isinteger(L, -1)) //error checking
		assert(false);
	return (int)lua_tointeger(L, -1); //return value as int
}

//get string from lua
std::string LuaGetString(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isstring(L, -1)) //error checking
		assert(false);
	return lua_tostring(L, -1); //return value as string
}

//get bool from lua
bool LuaGetBool(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isboolean(L, -1)) //error checking
		assert(false);
	return (bool)lua_toboolean(L, -1); //return value as bool
}

//get float from lua
float LuaGetFloat(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isnumber(L, -1)) //error checking
		assert(false);
	return (float)lua_tonumber(L, -1); //return value as float
}

//get double from lua
double LuaGetDouble(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isnumber(L, -1)) //error checking
		assert(false);
	return (double)lua_tonumber(L, -1); //return value as double
}




void Vector2::LuaGet(lua_State* L, const std::string& name) 
{
	lua_getglobal(L, name.c_str());//get variable + its name from lua
	if (!lua_istable(L, -1))//error checking
		assert(false);

	////return values as integers (into variables)
	lua_pushstring(L, "x"); //push the variable name
	lua_gettable(L, -2); //pops the variable name off and replaces it with the value
	x = (int)lua_tointeger(L, -1); //set the value to the struct's variable
	lua_pop(L, 1); //pop for cleanup#

	lua_pushstring(L, "y"); //push the variable name
	lua_gettable(L, -2); //pops the variable name off and replaces it with the value
	y = (int)lua_tointeger(L, -1); //set the value to the struct's variable
	lua_pop(L, 1); //pop for cleanup
}




////functions

int CallRandomNumber(lua_State* L, const std::string& name) 
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isfunction(L, -1)) //error checking
		assert(false);

	if (!LuaOK(L, lua_pcall(L, 0, 1, 0))) //calls a function in protected mode 
		assert(false);		//(State, num of values into function, num of values out of function, value for error code)

	int result = (int)lua_tointeger(L, -1); //return value as int

	lua_pop(L, 1); //pop for cleanup

	return result;
}

void CallMoveRight(lua_State* L, const std::string& name, float& x_val, float& frame_val)
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua
	if (!lua_isfunction(L, -1)) //error checking
		assert(false);

	//push the return values to lua
	lua_pushnumber(L, x_val);
	lua_pushnumber(L, frame_val);

	if (!LuaOK(L, lua_pcall(L, 2, 2, 0))) //calls a function in protected mode 
		assert(false);		//(State, num of values into function, num of values out of function, value for error code)

	x_val = (float)lua_tonumber(L, -2); //return value as float
	frame_val = (float)lua_tonumber(L, -1); //return value as float

	lua_pop(L, 2); //pop for cleanup
}




void CallVoidVoidCFunc(lua_State* L, const std::string& name)
{
	lua_getglobal(L, name.c_str()); //get variable by its name from lua

	if (!lua_isfunction(L, -1)) //error checking
		assert(false);

	if (!LuaOK(L, lua_pcall(L, 0, 0, 0))) //calls a function in protected mode 
		assert(false);		//(State, num of values into function, num of values out of function, value for error code)
}





//create a variable the same type as the library, and link it to the static library
std::map<string, Dispatcher::Command> Dispatcher::library;

int Dispatcher::LuaCall(lua_State* L)// LuaCall iterates through the library of registered functions by name
{
	string name = lua_tostring(L, 1);

	std::map<string, Command>::iterator it = library.find(name);
	assert(it != library.end());

	Command& cmd = (*it).second;

	if (cmd.voidintfunct)
	{
		int param = lua_tointeger(L, 2);
		cmd.voidintfunct(param); // and executes the function when found

		lua_pop(L, 1);
	}
	else // add any more cases here
		assert(false);

	return 1; //sacrificial int passing
}
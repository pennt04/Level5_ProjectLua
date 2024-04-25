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
void CallMoveLeft(lua_State* L, const std::string& name, float& x_val, float& frame_val);






void CallVoidVoidCFunc(lua_State* L, const std::string& name);






//a middle man between c++ and lua.
//Register class member functions so your lua script can then call them
class Dispatcher 
{
public:
	//capture your game functions here
	struct Command
	{
		typedef std::function<void(int)> voidintfunc;//a function that returns nothing and takes in an int
		voidintfunc voidintfunct;
		//add any other function signatures here:

	};


private:
	static std::map<std::string, Command> library; //this is where the game's functions are stored
	// static means there can only be one
public:

	//call once at start
	void Init(lua_State* L)
	{
		lua_register(L, "CDispatcher", LuaCall);
	}

	//register game functions
	void Register(const std::string& name, Command cmd)
	{
		assert(library.find(name) == library.end());
			library[name] = cmd;
	}

	//lua calls this then the data gets dispatched to the named function
	//lua cannot call class member functions without help
	static int LuaCall(lua_State* L);



};
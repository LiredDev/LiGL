#include <string>
#include <iostream>
#include <Wrappers/RenderWindowWrapper.hpp>

extern "C" {
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
}

#include <LuaBridge/LuaBridge.h>

using namespace sf;
using namespace luabridge;

lua_State* L;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Missing file path" << std::endl;
        return 1;
    }

	L = luaL_newstate();

	luaL_openlibs(L);

    getGlobalNamespace(L)
    .beginClass<RenderWindowWrapper>("RenderWindow")
        .addConstructor<void(*)(int, int, const std::string&)>()
        .addFunction("isOpen", &RenderWindowWrapper::isOpen)
        .addFunction("close", &RenderWindowWrapper::close)
        .addFunction("display", &RenderWindowWrapper::display)
        .addFunction("clear", &RenderWindowWrapper::clear)
		.addFunction("clearColor", &RenderWindowWrapper::clearColor)
        .addFunction("pollEvent", &RenderWindowWrapper::pollEvent)
        .addFunction("drawPoint", &RenderWindowWrapper::drawPoint)
    .endClass();

	getGlobalNamespace(L)
    .beginClass<EventWrapper>("Event")
        .addConstructor<void(*)()>()
        .addFunction("compareState", &EventWrapper::compareState)
    .endClass();
	
	luaL_dofile(L, argv[1]);

	lua_close(L);

	return 0;
}
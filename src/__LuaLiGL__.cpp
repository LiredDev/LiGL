#include <string>
#include <iostream>
#include <LiGL/LiGL.h>

extern "C" {
	#include "lua/lua.h"
	#include "lua/lualib.h"
	#include "lua/lauxlib.h"
}

#include <LuaBridge/LuaBridge.h>

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
    .beginClass<Window>("Window")
        .addConstructor<void(*)(int, int, std::string, bool, bool)>()
        .addFunction("Active", &Window::Active)
        .addFunction("Close", &Window::Close)
        .addFunction("Display", &Window::Display)
        .addFunction("Clear", &Window::Clear)
        .addFunction("pollEvent", &Window::luaPollEvent)
        .addFunction("drawPoint", &Window::DrawPoint)
        .addFunction("updateView", &Window::updateView)
        .addFunction("GetPressedKey", &Window::luaGetPressedKey)
        .addFunction("GetMouseX", &Window::luaGetMouseX)
        .addFunction("GetMouseY", &Window::luaGetMouseY)
        .addFunction("GetEventWidth", &Window::luaGetEventWidth)
        .addFunction("GetEventHeight", &Window::luaGetEventHeight)
    .endClass();

	getGlobalNamespace(L)
    .beginClass<Event>("Event")
        .addConstructor<void(*)()>().addConstructor<void(*)()>()
        .addProperty("width", &Event::width)
        .addProperty("height", &Event::height)
        .addProperty("key", &Event::key)
        .addProperty("type", &Event::type)
        .addProperty("Name", &Event::Name)
        .addProperty("Mouse_X", &Event::Mouse_X)
        .addProperty("Mouse_Y", &Event::Mouse_Y)
        .addFunction("compareState", &Event::compareState)
    .endClass();
    
    getGlobalNamespace(L)
    .beginClass<luaKeyboard>("Keyboard")
        .addConstructor<void(*)()>()
        .addProperty("KEY_A", &luaKeyboard::KEY_A, false)
        .addProperty("KEY_B", &luaKeyboard::KEY_B, false)
        .addProperty("KEY_C", &luaKeyboard::KEY_C, false)
        .addProperty("KEY_D", &luaKeyboard::KEY_D, false)
        .addProperty("KEY_E", &luaKeyboard::KEY_E, false)
        .addProperty("KEY_F", &luaKeyboard::KEY_F, false)
        .addProperty("KEY_G", &luaKeyboard::KEY_G, false)
        .addProperty("KEY_H", &luaKeyboard::KEY_H, false)
        .addProperty("KEY_I", &luaKeyboard::KEY_I, false)
        .addProperty("KEY_J", &luaKeyboard::KEY_J, false)
        .addProperty("KEY_K", &luaKeyboard::KEY_K, false)
        .addProperty("KEY_L", &luaKeyboard::KEY_L, false)
        .addProperty("KEY_M", &luaKeyboard::KEY_M, false)
        .addProperty("KEY_N", &luaKeyboard::KEY_N, false)
        .addProperty("KEY_O", &luaKeyboard::KEY_O, false)
        .addProperty("KEY_P", &luaKeyboard::KEY_P, false)
        .addProperty("KEY_Q", &luaKeyboard::KEY_Q, false)
        .addProperty("KEY_R", &luaKeyboard::KEY_R, false)
        .addProperty("KEY_S", &luaKeyboard::KEY_S, false)
        .addProperty("KEY_T", &luaKeyboard::KEY_T, false)
        .addProperty("KEY_U", &luaKeyboard::KEY_U, false)
        .addProperty("KEY_V", &luaKeyboard::KEY_V, false)
        .addProperty("KEY_W", &luaKeyboard::KEY_W, false)
        .addProperty("KEY_X", &luaKeyboard::KEY_X, false)
        .addProperty("KEY_Y", &luaKeyboard::KEY_Y, false)
        .addProperty("KEY_Z", &luaKeyboard::KEY_Z, false)
        .addProperty("KEY_ESCAPE", &luaKeyboard::KEY_ESCAPE, false)
        .addProperty("KEY_TAB", &luaKeyboard::KEY_TAB, false)
        .addProperty("KEY_CAPS_LOCK", &luaKeyboard::KEY_CAPS_LOCK, false)
        .addProperty("KEY_LEFT_SHIFT", &luaKeyboard::KEY_LEFT_SHIFT, false)
        .addProperty("KEY_RIGHT_SHIFT", &luaKeyboard::KEY_RIGHT_SHIFT, false)
        .addProperty("KEY_LEFT_CONTROL", &luaKeyboard::KEY_LEFT_CONTROL, false)
        .addProperty("KEY_RIGHT_CONTROL", &luaKeyboard::KEY_RIGHT_CONTROL, false)
        .addProperty("KEY_LEFT_ALT", &luaKeyboard::KEY_LEFT_ALT, false)
        .addProperty("KEY_RIGHT_ALT", &luaKeyboard::KEY_RIGHT_ALT, false)
        .addProperty("KEY_SPACE", &luaKeyboard::KEY_SPACE, false)
        .addProperty("KEY_ENTER", &luaKeyboard::KEY_ENTER, false)
        .addProperty("KEY_BACKSPACE", &luaKeyboard::KEY_BACKSPACE, false)
        .addProperty("KEY_INSERT", &luaKeyboard::KEY_INSERT, false)
        .addProperty("KEY_DELETE", &luaKeyboard::KEY_DELETE, false)
        .addProperty("KEY_HOME", &luaKeyboard::KEY_HOME, false)
        .addProperty("KEY_END", &luaKeyboard::KEY_END, false)
        .addProperty("KEY_PAGE_UP", &luaKeyboard::KEY_PAGE_UP, false)
        .addProperty("KEY_PAGE_DOWN", &luaKeyboard::KEY_PAGE_DOWN, false)
        .addProperty("KEY_ARROW_UP", &luaKeyboard::KEY_ARROW_UP, false)
        .addProperty("KEY_ARROW_DOWN", &luaKeyboard::KEY_ARROW_DOWN, false)
        .addProperty("KEY_ARROW_LEFT", &luaKeyboard::KEY_ARROW_LEFT, false)
        .addProperty("KEY_ARROW_RIGHT", &luaKeyboard::KEY_ARROW_RIGHT, false)
        .addProperty("KEY_NUMPAD_0", &luaKeyboard::KEY_NUMPAD_0, false)
        .addProperty("KEY_NUMPAD_1", &luaKeyboard::KEY_NUMPAD_1, false)
        .addProperty("KEY_NUMPAD_2", &luaKeyboard::KEY_NUMPAD_2, false)
        .addProperty("KEY_NUMPAD_3", &luaKeyboard::KEY_NUMPAD_3, false)
        .addProperty("KEY_NUMPAD_4", &luaKeyboard::KEY_NUMPAD_4, false)
        .addProperty("KEY_NUMPAD_5", &luaKeyboard::KEY_NUMPAD_5, false)
        .addProperty("KEY_NUMPAD_6", &luaKeyboard::KEY_NUMPAD_6, false)
        .addProperty("KEY_NUMPAD_7", &luaKeyboard::KEY_NUMPAD_7, false)
        .addProperty("KEY_NUMPAD_8", &luaKeyboard::KEY_NUMPAD_8, false)
        .addProperty("KEY_NUMPAD_9", &luaKeyboard::KEY_NUMPAD_9, false)
        .addProperty("KEY_NUMPAD_LOCK", &luaKeyboard::KEY_NUMPAD_LOCK, false)
        .addProperty("KEY_NUMPAD_PLUS", &luaKeyboard::KEY_NUMPAD_PLUS, false)
        .addProperty("KEY_NUMPAD_MINUS", &luaKeyboard::KEY_NUMPAD_MINUS, false)
        .addProperty("KEY_NUMPAD_ASTERISK", &luaKeyboard::KEY_NUMPAD_ASTERISK, false)
        .addProperty("KEY_NUMPAD_SLASH", &luaKeyboard::KEY_NUMPAD_SLASH, false)
        .addProperty("KEY_NUMPAD_PERIOD", &luaKeyboard::KEY_NUMPAD_PERIOD, false)
        .addProperty("KEY_F1", &luaKeyboard::KEY_F1, false) 
        .addProperty("KEY_F2", &luaKeyboard::KEY_F2, false) 
        .addProperty("KEY_F3", &luaKeyboard::KEY_F3, false) 
        .addProperty("KEY_F4", &luaKeyboard::KEY_F4, false) 
        .addProperty("KEY_F5", &luaKeyboard::KEY_F5, false) 
        .addProperty("KEY_F6", &luaKeyboard::KEY_F6, false) 
        .addProperty("KEY_F7", &luaKeyboard::KEY_F7, false) 
        .addProperty("KEY_F8", &luaKeyboard::KEY_F8, false) 
        .addProperty("KEY_F9", &luaKeyboard::KEY_F9, false) 
        .addProperty("KEY_F10", &luaKeyboard::KEY_F10, false) 
        .addProperty("KEY_F11", &luaKeyboard::KEY_F11, false) 
        .addProperty("KEY_F12", &luaKeyboard::KEY_F12, false)
    .endClass();
	
	if (luaL_dofile(L, argv[1]) != LUA_OK) {
        std::cout << lua_tostring(L,-1);
    }

	lua_close(L);

	return 0;
}

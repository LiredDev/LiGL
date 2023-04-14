all: CompileLiGL runLiGL
allLua: CompileLuaLiGL runLuaLiGL

CompileLiGL:
	g++ -I include -c src/__LiGL__.cpp
	g++ __LiGL__.o -o LiGL -lgdi32 -lopengl32
	move LiGL.exe "build/LiGL"
	del __LiGL__.o

runLiGL:
	"E:\Projects\LiGL - Lired Graphics Library (C++ & Lua)\build\LiGL\LiGL.exe"

CompileLuaLiGL:
	g++ -I include -c src/__LuaLiGL__.cpp -fpermissive
	g++ __LuaLiGL__.o -o LuaLiGL -L lib -l gdi32 -l opengl32 -l lua
	del __LuaLiGL__.o
	move LuaLiGL.exe "build/LuaLiGL"

runLuaLiGL:
	"E:\Projects\LiGL - Lired Graphics Library (C++ & Lua)\build\LuaLiGL\LuaLiGL.exe" Example.lua
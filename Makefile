all: CompileLiGL runLiGL
allLua: CompileLuaLiGL runLuaLiGL

CompileLiGL:
	g++ -I include -c src/__LiREX__.cpp
	g++ __LiREX__.o -o LiREX -lgdi32 -lopengl32
	move LiREX.exe "build/LiREX"
	del __LiREX__.o

runLiGL:
	"E:\Projects\LiGL - Lired Graphics Library (C++ & Lua)\build\LiREX\LiREX.exe"

CompileLuaLiGL:
	g++ -I include -c src/__LuaLiGL__.cpp -fpermissive
	g++ __LuaLiGL__.o -o LuaLiGL -L lib -l gdi32 -l opengl32 -l lua
	del __LuaLiGL__.o
	move LuaLiGL.exe "build/LuaLiGL"

runLuaLiGL:
	"E:\Projects\LiGL - Lired Graphics Library (C++ & Lua)\build\LuaLiGL\LuaLiGL.exe" Example.lua
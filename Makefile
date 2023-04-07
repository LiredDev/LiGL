all: Compile Run

Compile:
	g++ -I include -c src/main.cpp -fpermissive
	g++ main.o -o glua54 -L lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio -l lua
	del main.o
	del "E:\Projects\Lua Graphics Library\build\glua54.exe"
	move glua54.exe build/

Run:
	.\build\glua54.exe Example.lua
Sure, here's a README.md file for your LiGL project:
 # LiGL - Lired Graphics Library
 LiGL is a library for creating windows and drawing graphics on them. It is similar to SFML, but the key feature of LiGL is that it also supports Lua. This means that you can use Lua to create windows, draw graphics on them, and handle events.
 ## Features
 - Easy-to-use API for creating windows and drawing graphics
- Supports Lua scripting for creating windows and handling events
 ## Installation
 To use LiGL in your project, you need to download the source code and compile it. The library is written in C++, so you need a C++ compiler installed on your system.
 Once you have downloaded the source code, you can compile it using the following commands:

Run this to compile the c++ version, the ouput will be in the build folder.
```
make Compile
```
For mingw run the following:
```
mingw32-make Compile
```
This will create a  `libLiGL.a` file in the  `build`  directory, which you can link to your project.

to Compile the test file you can run the following:
```
make
```
for mingw:
```
mingw32-make
```

Run this to compile the Lua version, the ouput will be in the build folder.
```
make allLua
```
For mingw run the following:
```
mingw32-make allLua
```
This will create a  `LuaLiGL.exe` file in the  `build/LuaLiGL`  directory, which is the lua interpreter that has all the features in the c++ version.

to run the test file you can run the following:
```
make runLuaLiGL
```
for mingw:
```
mingw32-make runLuaLiGL
```
 ## Usage
 To use LiGL in your project, you need to include the  `LiGL.h`  header file and link to the  `libLiGL.a`  library. Here's an example program that creates a window and draws a red circle in the center:
```cpp
#include <LiGL/RenderWindow.h>
#include <iostream>
#include <LiGL/Keyboard.h>

#pragma comment(lib, "opengl32.lib")

int main()
{
    Window mainWindow(800, 600, "My Rendering Engine", true, true); // create a window with a width and height of 800x600 and a title. the bool values are for enabling console and active window border

    int pos = 50;
    while (mainWindow.Active())
    {
        Event event;
        mainWindow.pollEvent(event); // self explanatory, stores current happening events in the event class
        switch (event.type) { // Check for the event type
            case Event::Closed:
                mainWindow.Close(); // close the window
                break;
            case Event::Resized:
                mainWindow.updateView(event.width, event.height); // update the view whenever the window is resized
                break;
            case Event::KeyPressed: // Check for key presses
                std::cout << event.key << std::endl;
                if (event.key == Keyboard::KEY_D) {
                    pos++;
                }
                break;
            case Event::KeyReleased: // Check for key releases
                std::cout << event.key << std::endl;
                break;
            case Event::MouseMoved: // Check for mouse movement
                std::cout << event.Mouse_X << ", " << event.Mouse_Y << "\n";
            // Add cases for other event types you want to handle
        }

        // This is your main loop, where you can call Clear(), Draw(), and Display() functions
        mainWindow.Clear(0.0f, 0.0f, 0.4f, 1.0f);
        // mainWindow.Draw(someShape); // TODO: implement ability to create shapes and draw them
        for (int y = 0; y < 30; y++) {
            for (int x = 0; x < 30; x++) {
                mainWindow.DrawPoint(pos + x, pos + y, 1.0f, 1.0f, 1.0f); // draw a point on the screen
            }
        }
        mainWindow.Display(); // display everything
    }

    return 0;
}
```
This program creates a window using the  `Window`  class, draws a red square using the  `DrawPoint`  function, and displays the window using the  `Display`  method. The program then enters a loop that waits for the window to close, and calls the  `pollEvents`  method to handle events.
 You can also use Lua to create windows and handle events. Here's an example Lua script that creates a window and displays a message when the window is closed:
```lua
-- Create a window with a width of 800 pixels and a height of 600 pixels
local window = Window(800, 600, "Window Title", false, true)

-- Main loop
local event = Event()
local keyboard = Keyboard()

local width = 5
local height = 5
local i = 0
local j = 0

while window:Active() do
    event.Name = window:pollEvent()
    if event.Name == "Closed" then
        window:Close()
        break
    end
    if event.Name == "Resized" then
        window:updateView(window:GetEventWidth(), window:GetEventHeight())
    end
    if event.Name == "KeyPressed" then
        local key = window:GetPressedKey()
        print(key, keyboard.KEY_A)
        if key == keyboard.KEY_A then
            i = i - 1 
        end
        if key == keyboard.KEY_D then
            i = i + 1 
        end
        if key == keyboard.KEY_W then
            j = j - 1 
        end
        if key == keyboard.KEY_S then
            j = j + 1 
        end
    end

    window:Clear(0, 0, 0, 0)
    for y = 0, height, 1 do
        for x = 0, width, 1 do
            window:drawPoint(i + x, j + y, 255, 0, 0)
        end
    end

    if event.Name == "MouseMoved" then
        print(window:GetMouseX() , window:GetMouseY())
        for y = 0, 10, 1 do
            for x = 0, 10, 1 do
                window:drawPoint(window:GetMouseX() + x, window:GetMouseY() + y, 255, 255, 255)
            end
        end
    end
    window:Display()
end
```
This is a lua script similar to the c++ version, it draws a square on the screen using `drawPoint` and also draws another square at the mouse position.
 ## Contributors
 - LiredDev - Creator and maintainer
 ## Open-Source
  you can download the source and modify it however you like. You could also suggest features or fixes i would appreciate that.

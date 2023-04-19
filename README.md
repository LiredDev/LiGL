 # LiGL - Lired Graphics Library
 LiGL is a library for creating windows and drawing graphics on them. It is similar to SFML, but the key feature of LiGL is that it also supports Lua. This means that you can use Lua to create windows, draw graphics on them, and handle events.
 ## Update logs
 - Added Threads (because mingw doesn't support them by default)
 - Set window transparency
 - Remove window border (the last bool value removes the border when set to true)`Window mainWindow(800, 600, "LiGL - Test", false, false);`
 ## Note
 - The code currently is a mess but i promise to organize it later
 ## Features
 - Easy-to-use API for creating windows and drawing graphics
- Supports Lua scripting for creating windows and handling events
 ## Installation
 You can directly use the header files no need for to compile the source. However you can compile the example provided just run the follwing commands:
to Compile the test file you can run the following:
```bash
make
```
for mingw:
```bash
mingw32-make
```
This will create a  `LiGL.exe` file in the  `build/LiGL`  directory. After it is compiled it will automatically run the program.

Run this to compile the Lua version, the ouput will be in the build folder.
```bash
make allLua
```
For mingw run the following:
```bash
mingw32-make allLua
```
This will create a  `LuaLiGL.exe` file in the  `build/LuaLiGL`  directory, which is the lua interpreter that has all the features in the c++ version. After it is compiled it will automatically run the test file.

 ## Usage
 To use LiGL in your project, you need to include the  `LiGL.h`  header file. Here's an example program that creates a window and draws a red circle in the center:
```cpp
#include <LiGL/LiGL.h>               // Include LiGL library
#include <iostream>                  // Include iostream library
#include <chrono>                    // Include chrono library
#include <LiGL/Shape.h>              // Include Shape library
#include <LiGL/Thread.h>             // Include Thread library
#pragma comment(lib, "opengl32.lib") // Link opengl library

// Function to play audio
void playAudio()
{
    PlaySound(TEXT("Inst.wav"), NULL, SND_SYNC);
}
// Class to create a thread
class MyThread : public Thread
{
public:
    // Override run function
    virtual void run()
    {
        playAudio();
    }
};
int main()
{
    // Create a window with 800 width, 600 height, title "LiGL - Test", with console disabled and border enabled
    Window mainWindow(800, 600, "LiGL - Test", false, false);
    // Get the last time
    auto last_time = std::chrono::high_resolution_clock::now();
    // Delta time
    float delta_time = 0.0f;
    // X and Y coordinates
    float X = 50;
    float Y = 50;
    // Speed of the point
    float speed = 500;
    // Create a thread
    MyThread t;
    t.start();
    // Main loop
    while (mainWindow.Active())
    {
        // Get current time
        auto current_time = std::chrono::high_resolution_clock::now();
        // Calculate elapsed time
        std::chrono::duration<float> elapsed_time = current_time - last_time;
        // Set last time to current time
        last_time = current_time;
        // Set delta time
        delta_time = elapsed_time.count();
        // Create an event
        Event event;
        // Poll the event
        mainWindow.pollEvent(event);
        // Switch statement for event type
        switch (event.type)
        {
        case Event::Closed:
            // Close the window
            mainWindow.Close();
            break;
        case Event::Resized:
            // Update view
            mainWindow.updateView(event.width, event.height);
            break;
        case Event::KeyPressed:
            // Print key pressed
            std::cout << event.key << std::endl;
            // Move the point based on key pressed
            if (event.key == Keyboard::KEY_D)
            {
                X += speed * delta_time;
            }
            if (event.key == Keyboard::KEY_A)
            {
                X -= speed * delta_time;
            }
            if (event.key == Keyboard::KEY_W)
            {
                Y -= speed * delta_time;
            }
            if (event.key == Keyboard::KEY_S)
            {
                Y += speed * delta_time;
            }
            break;
        case Event::KeyReleased:
            // Print key released
            std::cout << event.key << std::endl;
            break;
        case Event::MouseMoved:
            break;
        case Event::MouseLeft:
            // Print mouse left
            std::cout << "Mouse Left" << std::endl;
            break;
        }
        // Clear the window
        mainWindow.Clear(0.0f, 0.0f, 0.4f, 1.0f);
        // Draw a point at X and Y coordinates
        for (int y = 0; y < 30; y++)
        {
            for (int x = 0; x < 30; x++)
            {
                mainWindow.DrawPoint(X + x, Y + y, 1, 1, 1);
            }
        }
        // Display the window
        mainWindow.Display();
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
 ## Documentation
  i will work on creating a documentation once i feel like i added all the necessary features.

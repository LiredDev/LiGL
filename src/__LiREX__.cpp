#include <iostream>
#include <LiGL/LiGL.h>

#pragma comment(lib, "opengl32.lib")

int main()
{
    Window mainWindow(800, 600, "My Rendering Engine", true, true);

    int pos = 50;

    MSG msg = {0};
    while (mainWindow.Active())
    {
        Event event;
        mainWindow.pollEvent(event);
        switch (event.type) {
            case Event::Closed:
                mainWindow.Close();
                break;
            case Event::Resized:
                mainWindow.updateView(event.width, event.height);
                break;
            case Event::KeyPressed:
                std::cout << event.key << std::endl;
                if (event.key == Keyboard::KEY_D) {
                    pos++;
                }
                break;
            case Event::KeyReleased:
                std::cout << event.key << std::endl;
                break;
            case Event::MouseMoved:
                std::cout << event.Mouse_X << ", " << event.Mouse_Y << "\n";
            // Add cases for other event types you want to handle
        }

        // This is your main loop, where you can call Clear(), Draw(), and Display() functions
        mainWindow.Clear(0.0f, 0.0f, 0.4f, 1.0f);
        // mainWindow.Draw(someShape); // Draw your shape here
        for (int y = 0; y < 30; y++) {
            for (int x = 0; x < 30; x++) {
                mainWindow.DrawPoint(pos + x, pos + y, 1.0f, 1.0f, 1.0f);
            }
        }
        mainWindow.Display();
    }

    return 0;
}

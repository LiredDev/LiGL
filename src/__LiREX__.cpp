#include <LiGL/RenderWindow.h>
#include <iostream>
#include <LiGL/Keyboard.h>
#include <chrono>

#pragma comment(lib, "opengl32.lib")

int main()
{
    Window mainWindow(800, 600, "LiREX", false, false);

    auto last_time = std::chrono::high_resolution_clock::now();
    float delta_time = 0.0f;

    float X = 50;
    float Y = 50;
    float speed = 500;

    while (mainWindow.Active())
    {
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed_time = current_time - last_time;
        last_time = current_time;
        delta_time = elapsed_time.count();
        
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
                    X += speed * delta_time;
                }
                if (event.key == Keyboard::KEY_A) {
                    X -= speed * delta_time;
                }
                if (event.key == Keyboard::KEY_W) {
                    Y -= speed * delta_time;
                }
                if (event.key == Keyboard::KEY_S) {
                    Y += speed * delta_time;
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
        // mainWindow.Draw(someShape); // Draw your shape here // Draw is not implemented yet
        for (int y = 0; y < 30; y++) {
            for (int x = 0; x < 30; x++) {
                mainWindow.DrawPoint(X + x, Y + y, 1.0f, 1.0f, 1.0f);
            }
        }
        mainWindow.Display();
    }

    return 0;
}
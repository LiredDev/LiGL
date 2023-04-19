#include <LiGL/LiGL.h>               // Include LiGL library
#include <iostream>                  // Include iostream library
#include <chrono>                    // Include chrono library
#include <LiGL/Shape.h>              // Include Shape library
#include <LiGL/Audio.h>              // Include Audio library
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
    // Create a window with 800 width, 600 height, title "LiGL - Test", no fullscreen and no vsync
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
#include <SFML/Graphics.hpp>
#include <Wrappers/EventWrapper.hpp>
// Class to wrap the SFML RenderWindow
class RenderWindowWrapper
{
public:
    // Constructor
    RenderWindowWrapper(int width, int height, const std::string &title) : window(sf::VideoMode(width, height), title) {}
    // Check if window is open
    bool isOpen() { return window.isOpen(); }
    // Close window
    void close() { window.close(); }
    // Display window
    void display() { window.display(); }
    // Clear color of window
    void clearColor(int r, int g, int b)
    {
        sf::Color color;
        color.r = r;
        color.g = g;
        color.b = b;
        window.clear(color);
    }
    // Clear window
    void clear() { window.clear(); }
    // Draw point on window
    void drawPoint(float x, float y, int r, int g, int b)
    {
        sf::RectangleShape rect;
        sf::Color color;
        color.r = r;
        color.g = g;
        color.b = b;
        sf::Vector2f size(1, 1);
        sf::Vector2f position(x, y);
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(color);
        window.draw(rect);
    }
    // Poll event
    bool pollEvent() { return window.pollEvent(EVENTS::m_event); }

private:
    sf::RenderWindow window;
};
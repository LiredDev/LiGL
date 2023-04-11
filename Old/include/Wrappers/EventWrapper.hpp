#include <SFML/Graphics.hpp> // Include SFML library
#include <iostream>          // Include input/output stream library
#include <vector>            // Include vector library
#include <unordered_map>     // Include unordered map library
using namespace std;         // Use the standard namespace
using namespace sf;          // Use the SFML namespace
namespace EVENTS
{
    Event m_event;
} // Create a namespace for main event
  // Create an unordered map of strings and SFML event types
unordered_map<std::string, sf::Event::EventType> eventTypes = {
    {"Closed", sf::Event::Closed},
    {"Resized", sf::Event::Resized},
    {"LostFocus", sf::Event::LostFocus},
    {"GainedFocus", sf::Event::GainedFocus},
    {"TextEntered", sf::Event::TextEntered},
    {"KeyPressed", sf::Event::KeyPressed},
    {"KeyReleased", sf::Event::KeyReleased},
    {"MouseWheelMoved", sf::Event::MouseWheelMoved},
    {"MouseWheelScrolled", sf::Event::MouseWheelScrolled},
    {"MouseButtonPressed", sf::Event::MouseButtonPressed},
    {"MouseButtonReleased", sf::Event::MouseButtonReleased},
    {"MouseMoved", sf::Event::MouseMoved},
    {"MouseEntered", sf::Event::MouseEntered},
    {"MouseLeft", sf::Event::MouseLeft},
    {"JoystickButtonPressed", sf::Event::JoystickButtonPressed},
    {"JoystickButtonReleased", sf::Event::JoystickButtonReleased},
    {"JoystickMoved", sf::Event::JoystickMoved},
    {"JoystickConnected", sf::Event::JoystickConnected},
    {"JoystickDisconnected", sf::Event::JoystickDisconnected},
    {"TouchBegan", sf::Event::TouchBegan},
    {"TouchMoved", sf::Event::TouchMoved},
    {"TouchEnded", sf::Event::TouchEnded},
    {"SensorChanged", sf::Event::SensorChanged}};
// Create a class to wrap event class
class EventWrapper
{
public:
    // Constructor
    EventWrapper() {}
    // Destructor
    ~EventWrapper() {}
    // Compare the state of the event
    bool compareState(string State)
    {
        if (EVENTS::m_event.type == eventTypes[State])
        {
            return true;
        }
        return false;
    }
};
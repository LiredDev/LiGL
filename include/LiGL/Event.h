#include <unordered_map>
#include <iostream>

class Event {
public:
    Event() {};
    int type;
    int width;
    int height;
    int key;
    int Mouse_X;
    int Mouse_Y;
    std::string Name;

    bool compareState(std::string eventname) {
        if (this->type == eventTypes[eventname]) {
            return true;
        };
        return false;
    }

    enum EventType {
        MouseButtonReleased,
        MouseButtonPressed,
        MouseMoved,
        KeyPressed,
        KeyReleased,
        Closed,
        NoEvent,
        Resized,
        MouseLeft
    };
    private:
        std::unordered_map<std::string, Event::EventType> eventTypes = {
            {"Closed", Event::Closed},
            {"Resized", Event::Resized},
            {"KeyPressed", Event::KeyPressed},
            {"KeyReleased", Event::KeyReleased},
            {"MouseButtonPressed", Event::MouseButtonPressed},
            {"MouseButtonReleased", Event::MouseButtonReleased},
            {"NoEvent", Event::NoEvent},
            {"MouseMoved", Event::MouseMoved},
            {"MouseLeft", Event::MouseLeft}
        };
};
#include <vector>
#include <LiGL/Vectors.h>

class Shape {
public:
    Shape(std::vector<Vector2>& points, float width, float height, float x, float y, float r, float g, float b, float a) 
    { 
        m_points = points; 
        m_width = width; 
        m_height = height; 
        m_x = x; 
        m_y = y; 
        m_r = r; 
        m_g = g; 
        m_b = b; 
        m_a = a; 
    }
    setPosition(float x, float y) 
    { 
        m_x = x; 
        m_y = y; 
    } 
    move(float dx, float dy) 
    { 
        m_x += dx; 
        m_y += dy; 
    } 
    setColor(float r, float g, float b, float a) 
    { 
        m_r = r; 
        m_g = g; 
        m_b = b; 
        m_a = a; 
    }
private:
    std::vector<Vector2> m_points;
    float m_width;
    float m_height;
    float m_x;
    float m_y;
    float m_r;
    float m_g;
    float m_b;
    float m_a;
};
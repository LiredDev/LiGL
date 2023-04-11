#include <vector>
#include <LiGL/Vectors.h>

class Shape {
public:
    Shape(std::vector<Vector2>& points, float width, float height, float x, float y, float r, float g, float b, float a);
    void setPosition(float x, float y);
    void move(float dx, float dy);
    void setColor(float r, float g, float b, float a);
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
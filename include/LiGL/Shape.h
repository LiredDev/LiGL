#pragma once
#include <vector>
#include <LiGL/Vectors.h>

class Shape {
public:
    std::vector<Vector2f> m_pixels;
    Shape(std::vector<Vector2f> points, float width, float height, float x, float y, float r, float g, float b, float a) 
    { 
        m_pixels = points; 
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
    float m_width;
    float m_height;
    float m_x;
    float m_y;
    float m_r;
    float m_g;
    float m_b;
    float m_a;
};

class Rectangle : public Shape
{
public:
    Rectangle(float width, float height, float x, float y, float r, float g, float b, float a)
        : Shape(getPixels(width, height), width, height, x, y, r, g, b, a), m_width(width), m_height(height)
    {
    }
private:
    std::vector<Vector2f> getPixels(float width, float height)
    {
        std::vector<Vector2f> pixels;
        for (float x = -width / 2; x < width / 2; x++)
        {
            for (float y = -height / 2; y < height / 2; y++)
            {
                Vector2f pixel(x + 0.5f, y + 0.5f);
                pixels.push_back(pixel);
            }
        }
        return pixels;
    }
    float m_width;
    float m_height;
};
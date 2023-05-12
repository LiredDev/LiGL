#pragma once
#include <vector>
#include <LiGL/Vectors.h>

class Shape
{
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
    void setPosition(float x, float y)
    {
        m_x = x;
        m_y = y;
    }
    void move(float dx, float dy)
    {
        m_x += dx;
        m_y += dy;
    }
    void setColor(float r, float g, float b, float a)
    {
        m_r = r;
        m_g = g;
        m_b = b;
        m_a = a;
    }
    // Add scale function
    virtual void scale(float scaleFactor)
    {
        m_width *= scaleFactor;
        m_height *= scaleFactor;
        for (Vector2f &point : m_pixels)
        {
            point.X *= scaleFactor;
            point.Y *= scaleFactor;
        }
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

class RectangleShape : public Shape
{
public:
    RectangleShape(float width, float height, float x, float y, float r, float g, float b, float a)
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

class CircleShape : public Shape
{
public:
    CircleShape(float radius, float x, float y, float r, float g, float b, float a)
        : Shape(getPixels(radius), radius * 2, radius * 2, x, y, r, g, b, a), m_radius(radius)
    {
    }

private:
    std::vector<Vector2f> getPixels(float radius)
    {
        std::vector<Vector2f> pixels;
        for (float x = -radius; x <= radius; x++)
        {
            for (float y = -radius; y <= radius; y++)
            {
                if (x * x + y * y <= radius * radius)
                {
                    Vector2f pixel(x + radius + 0.5f, y + radius + 0.5f);
                    pixels.push_back(pixel);
                }
            }
        }
        return pixels;
    }
    float m_radius;
};

class TriangleShape : public Shape
{
public:
    TriangleShape(float base, float height, float x, float y, float r, float g, float b, float a)
        : Shape(getPixels(base, height), base, height, x, y, r, g, b, a), m_base(base), m_height(height)
    {
    }

private:
    std::vector<Vector2f> getPixels(float base, float height)
    {
        std::vector<Vector2f> pixels;
        // Calculate the half width of the base
        float half_base = base / 2;
        // Loop through each row from top to bottom
        for (int y = 0; y < height; y++)
        {
            // Calculate the left and right edges of the row
            float left_edge = half_base - (y / height) * half_base;
            float right_edge = half_base + (y / height) * half_base;
            // Round the edges to the nearest pixel
            int left_pixel = std::max(0, (int)(left_edge + 0.5f));
            int right_pixel = std::min((int)base - 1, (int)(right_edge + 0.5f));
            // Add the pixels in the row to the pixel list
            for (int x = left_pixel; x <= right_pixel; x++)
            {
                Vector2f pixel(x + 0.5f, y + 0.5f);
                pixels.push_back(pixel);
            }
        }
        return pixels;
    }
    float m_base;
    float m_height;
};
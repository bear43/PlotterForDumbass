//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_POINT_H
#define UNTITLED2_POINT_H

#include <vector>
#include <GL/gl.h>
#include "Color.h"

using namespace std;
template <typename T>
class Point
{
protected:
    Color& color = (Color&)(Color::whiteColor);
    float size = 1.0f;
public:

    Point() = default;

    explicit Point(Color& color) : color(color)
    {}

    virtual ~Point()
    {

    }

    virtual void render() = 0;

    virtual vector<T> getPoints() = 0;

    virtual void setPoints(vector<T> &points) = 0;

    virtual T operator[](int index) = 0;

    Color &getColor()
    {
        return color;
    }

    void setColor(Color &color)
    {
        Point::color = color;
    }

    float getSize() const
    {
        return size;
    }

    void setSize(float size)
    {
        Point::size = size;
    }
};


#endif //UNTITLED2_POINT_H

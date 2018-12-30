//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_BASEPOINT1_H
#define UNTITLED2_BASEPOINT1_H

#include "../../Interface/Point.h"
#include <GL/gl.h>

template <typename T>
class BasePoint1 : public Point<T>
{
protected:
    T point0;
public:
    explicit BasePoint1(T point0, Color& color) : point0(point0)
    {
        this->color = color;
    }

    explicit BasePoint1(T point0) : BasePoint1(point0, (Color&)Color::whiteColor)
    {}
    BasePoint1() : BasePoint1(0.0f)
    {}

    explicit BasePoint1(vector<T> points) : point0(points[0])
    {}

    T getPoint0() const
    {
        return point0;
    }

    void setPoint0(T point0)
    {
        BasePoint1::point0 = point0;
    }

    vector<T> getPoints() override
    {
        vector<T> points({point0});
        return points;
    }

    void setPoints(vector<T> &points) override
    {
        point0 = points[0];
    }

    void render()
    {
        glPointSize(this->size);
        glBegin(GL_POINTS);
        glColor3ub(this->color.getRed(), this->color.getGreen(), this->color.getBlue());
        glVertex2f(this->point0, 0.0f);
        glEnd();
    }

    T operator[](int index) override
    {
        return point0;
    }
};


#endif //UNTITLED2_BASEPOINT1_H

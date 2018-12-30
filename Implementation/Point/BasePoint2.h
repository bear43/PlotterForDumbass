//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_BASEPOINT2_H
#define UNTITLED2_BASEPOINT2_H

#include "BasePoint1.h"

template <typename T>
class BasePoint2 : public BasePoint1<T>
{
protected:
    T point1;
public:
    BasePoint2(T point0, T point1, Color& color) : BasePoint1<T>(point0), point1(point1)
    {
        this->color = color;
    }
    BasePoint2(T point0, T point1) : BasePoint2<T>(point0, point1, (Color&)Color::whiteColor)
    {}
    BasePoint2() : BasePoint2(0.0f, 0.0f)
    {}

    explicit BasePoint2(vector<T> points) : BasePoint2(points[0], points[1])
    {}

    virtual T getPoint1() const
    {

        return point1;
    }

    virtual void setPoint1(T point1)
    {
        BasePoint2::point1 = point1;
    }

    vector<T> getPoints() override
    {
        vector<T> points({this->point0, point1});
        return points;
    }

    void setPoints(vector<T> &points) override
    {
        this->point0 = points[0];
        point1 = points[1];
    }

    void render()
    {
        glPointSize(this->size);
        glBegin(GL_POINTS);
        glColor3ub(this->color.getRed(), this->color.getGreen(), this->color.getBlue());
        glVertex2f(this->point0, point1);
        glEnd();
    }

    T operator[](int index) override
    {
        switch(index)
        {
            case 0:
                return this->point0;
            case 1:
                return this->point1;
            default:
                return 0;
        }
    }
};


#endif //UNTITLED2_BASEPOINT2_H

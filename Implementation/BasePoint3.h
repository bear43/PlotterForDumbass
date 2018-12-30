//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_BASEPOINT3_H
#define UNTITLED2_BASEPOINT3_H

#include "BasePoint2.h"

template <typename T>
class BasePoint3 : public BasePoint2<T>
{
protected:
    T point2;
public:
    BasePoint3(T point0, T point1, T point2, Color& color) : BasePoint2<T>(point0, point1), point2(point2)
    {
        this->color = color;
    }
    BasePoint3(T point0, T point1, T point2) : BasePoint3<T>(point0, point1, point2, (Color&)Color::whiteColor)
    {}
    BasePoint3() : BasePoint3(0.0f, 0.0f, 0.0f)
    {}

    T getPoint2() const
    {
        return point2;
    }

    void setPoint2(T point2)
    {
        BasePoint3::point2 = point2;
    }

    vector<T> getPoints() override
    {
        vector<T> points({this->point0, this->point1, point2});
        return points;
    }

    void setPoints(vector<T> &points) override
    {
        this->point0 = points[0];
        this->point1 = points[1];
        point2 = points[2];
    }

    void render()
    {
        glPointSize(this->size);
        glBegin(GL_POINTS);
        glColor3ub(this->color.getRed(), this->color.getGreen(), this->color.getBlue());
        glVertex2f(this->point0, this->point1, point2);
        glEnd();
    }
};


#endif //UNTITLED2_BASEPOINT3_H

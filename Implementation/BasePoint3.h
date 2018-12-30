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
    BasePoint3(T point0, T point1, T point2) : BasePoint2(point0, point1), point2(point2)
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
        vector<T> points({point0, point1, point2});
        return points;
    }

    void setPoints(vector<T> &points) override
    {
        point0 = points[0];
        point1 = points[1];
        point2 = points[2];
    }

    void render()
    {
        glColor3ub(r, g, b);
        glVertex3f(point0, point1, point2);
    }
};


#endif //UNTITLED2_BASEPOINT3_H

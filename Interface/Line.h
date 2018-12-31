//
// Created by kostya on 30.12.18.
//

#ifndef UNTITLED2_LINE_H
#define UNTITLED2_LINE_H

#include "Point.h"

class Line : public Renderable
{
protected:
    Point<float> *startPoint;
    Point<float> *endPoint;
public:
    Line(Point<float> *startPoint, Point<float> *endPoint) : startPoint(startPoint), endPoint(endPoint)
    {}

    virtual ~Line()
    {
        delete startPoint;
        delete endPoint;
    }
};


#endif //UNTITLED2_LINE_H

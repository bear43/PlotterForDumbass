//
// Created by kostya on 30.12.18.
//

#ifndef UNTITLED2_LINE2_H
#define UNTITLED2_LINE2_H

#include "../../Interface/Line.h"

class Line2 : public Line
{
public:
    Line2(Point<float> *startPoint, Point<float> *endPoint) : Line(startPoint, endPoint)
    {}

    void render() override
    {
        glBegin(GL_LINES);
        glColor4ub(startPoint->getColor()[0],
                startPoint->getColor()[1],
                startPoint->getColor()[2],
                startPoint->getColor()[3]);
        glVertex2f((*startPoint)[0], (*startPoint)[1]);
        glColor4ub(endPoint->getColor()[0],
                   endPoint->getColor()[1],
                   endPoint->getColor()[2],
                   endPoint->getColor()[3]);
        glVertex2f((*endPoint)[0], (*endPoint)[1]);
        glEnd();
    }
};


#endif //UNTITLED2_LINE2_H

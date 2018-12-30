//
// Created by kostya on 30.12.18.
//

#ifndef UNTITLED2_LINE3_H
#define UNTITLED2_LINE3_H


#include "../../Interface/Line.h"

class Line3 : Line
{
    Line3(Point<float> *startPoint, Point<float> *endPoint) : Line(startPoint, endPoint)
    {}

    void render() override
    {
        glBegin(GL_LINES);
        glColor4ub(startPoint->getColor()[0],
                   startPoint->getColor()[1],
                   startPoint->getColor()[2],
                   startPoint->getColor()[3]);
        glVertex3f((*startPoint)[0], (*startPoint)[1], (*startPoint)[3]);
        glColor4ub(endPoint->getColor()[0],
                   endPoint->getColor()[1],
                   endPoint->getColor()[2],
                   endPoint->getColor()[3]);
        glVertex3f((*endPoint)[0], (*endPoint)[1], (*endPoint)[3]);
        glEnd();
    }
};


#endif //UNTITLED2_LINE3_H

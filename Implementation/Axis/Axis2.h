#include <utility>

//
// Created by kostya on 31.12.18.
//

#ifndef UNTITLED2_AXIS2_H
#define UNTITLED2_AXIS2_H


#include "../../Interface/Axis.h"
#include "../../Interface/Text.h"
#include <cfloat>

class Axis2 : public Axis
{
private:
    int maxEndIndex = -1;
    BasePoint2<float> textEndPoint;
public:
    Axis2(Point<float> *startPoint, Point<float> *endPoint, const string &title) : Axis(startPoint, endPoint, title)
    {
        float maxEndValue = FLT_MIN;
        float currentValue;
        for(int i = 0; i < 2; i++)
        {
            currentValue = (*endPoint)[i];
            if(currentValue > maxEndValue)
            {
                maxEndValue = currentValue;
                maxEndIndex = i;
            }
        }
        textEndPoint = *(BasePoint2<float>*)(endPoint);
        textEndPoint[maxEndIndex] -= 0.1f;
        textEndPoint[1-maxEndIndex] += 0.03f;
    }

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
        Text::out(this->title,
                  textEndPoint[0],
                  textEndPoint[1],
                  textEndPoint[2],
                  textEndPoint.getColor()[0],
                  textEndPoint.getColor()[1],
                  textEndPoint.getColor()[2],
                  textEndPoint.getColor()[3],
                  2);
    }
};


#endif //UNTITLED2_AXIS2_H

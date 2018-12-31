#include <utility>

//
// Created by kostya on 31.12.18.
//

#ifndef UNTITLED2_AXIS_H
#define UNTITLED2_AXIS_H


#include "Line.h"
#include <string>

using namespace std;

class Axis : public Line
{
protected:
    string title;
public:
    Axis(Point<float> *startPoint, Point<float> *endPoint, string& title) : Line(startPoint, endPoint), title(title)
    {}

    Axis(Point<float> *startPoint, Point<float> *endPoint, string title) : Line(startPoint, endPoint), title(
            std::move(title))
    {}

};


#endif //UNTITLED2_AXIS_H

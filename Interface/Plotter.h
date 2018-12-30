//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_PLOTTER_H
#define UNTITLED2_PLOTTER_H

#include <set>
#include <algorithm>
#include "Point.h"
#include "Drawer.h"
#include "Line.h"

class Plotter
{
protected:
    Drawer& drawer;
    set<Point<float>*> points;
    set<Line*> lines;
    virtual void generatePoints() = 0;
    virtual void generateLines() = 0;
public:
    explicit Plotter(Drawer& drawer) : drawer(drawer)
    {}
    Plotter() = default;
    void update()
    {
        if(points.empty()) generatePoints();
        if(lines.empty()) generateLines();
        set<Point<float>*> &refPoint = drawer.getPoints();
        set<Line*> &refLine = drawer.getLines();
        std::copy(points.begin(), points.end(), std::inserter(refPoint, refPoint.end()));
        std::copy(lines.begin(), lines.end(), std::inserter(refLine, refLine.end()));
        //refPoint.insert(refPoint.end(), points.begin(), points.end());
        //refLine.insert(refLine.end(), lines.begin(), lines.end());
    }
};

#endif //UNTITLED2_PLOTTER_H

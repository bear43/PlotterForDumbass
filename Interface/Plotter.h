//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_PLOTTER_H
#define UNTITLED2_PLOTTER_H

//#include <GL/gl.h>
#include "Point.h"
#include "Drawer.h"
#include "Line.h"

class Plotter
{
protected:
    Drawer& drawer;
    vector<Point<double>*> points;
    vector<Line*> lines;
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
        vector<Point<double>*> &refPoint = drawer.getPoints();
        vector<Line*> &refLine = drawer.getLines();
        refPoint.insert(refPoint.end(), points.begin(), points.end());
        refLine.insert(refLine.end(), lines.begin(), lines.end());
    }
};

#endif //UNTITLED2_PLOTTER_H

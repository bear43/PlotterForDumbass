//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_PLOTTER_H
#define UNTITLED2_PLOTTER_H

//#include <GL/gl.h>
#include "Point.h"
#include "Drawer.h"

class Plotter
{
protected:
    Drawer& drawer;
    vector<Point<double>*> points;
    vector<Point<double>*> lines;
    virtual void generatePoints() = 0;
    virtual void generateLines() = 0;
public:
    explicit Plotter(Drawer& drawer) : drawer(drawer)
    {}
    Plotter() = default;
    void update()
    {
        if(points.size() == 0) generatePoints();
        if(lines.size() == 0) generateLines();
        vector<Point<double>*> &refPoint = drawer.getPoints();
        vector<Point<double>*> &refLine = drawer.getLines();
        refPoint.insert(refPoint.end(), points.begin(), points.end());
        refLine.insert(refLine.end(), lines.begin(), lines.end());
    }
};

#endif //UNTITLED2_PLOTTER_H

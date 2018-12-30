//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_XYPLOTTER_H
#define UNTITLED2_XYPLOTTER_H

#include "BasePoint2.h"
#include "../Interface/Plotter.h"
#include "../Interface/Color.h"


class XYPlotter : public Plotter
{
private:
    Color& color;
    void generatePoints() override
    {

    }

    void generateLines() override
    {
        Point<double>* pPoint;
        pPoint = (Point<double>*)(new BasePoint2<float>(-1.0f, 0.0f, color));
        lines.push_back(pPoint);
        pPoint = (Point<double>*)(new BasePoint2<float>(1.0f, 0.0f, color));
        lines.push_back(pPoint);
        pPoint = (Point<double>*)(new BasePoint2<float>(0.0f, -1.0f, color));
        lines.push_back(pPoint);
        pPoint = (Point<double>*)(new BasePoint2<float>(0.0f, 1.0f, color));
        lines.push_back(pPoint);
    }

public:
    XYPlotter(Drawer& drawerInstance, Color& color) : Plotter(drawerInstance), color(color)
    {}

    explicit XYPlotter(Drawer& drawerInstance) : XYPlotter(drawerInstance, (Color&)Color::whiteColor)
    {}

    XYPlotter() = default;
};



#endif //UNTITLED2_XYPLOTTER_H

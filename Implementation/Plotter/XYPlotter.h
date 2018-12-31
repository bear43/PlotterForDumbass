//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_XYPLOTTER_H
#define UNTITLED2_XYPLOTTER_H

#include "../Point/BasePoint2.h"
#include "../../Interface/Plotter.h"
#include "../../Interface/Color.h"
#include "../Line/Line2.h"
#include "../Axis/Axis2.h"


class XYPlotter : public Plotter
{
private:
    Color& color;
    void generatePoints() override
    {

    }

    void generateLines() override
    {
        Line* pLine;
        pLine = new Axis2(new BasePoint2<float>(-1.0f, 0.0f), new BasePoint2<float>(1.0f, 0.0f), "X1");
        lines.insert(pLine);
        pLine = new Axis2(new BasePoint2<float>(0.0f, -1.0f), new BasePoint2<float>(0.0f, 1.0f), "X2");
        lines.insert(pLine);
    }

public:
    XYPlotter(Drawer& drawerInstance, Color& color) : Plotter(drawerInstance), color(color)
    {}

    explicit XYPlotter(Drawer& drawerInstance) : XYPlotter(drawerInstance, (Color&)Color::whiteColor)
    {}

    XYPlotter() = default;
};



#endif //UNTITLED2_XYPLOTTER_H

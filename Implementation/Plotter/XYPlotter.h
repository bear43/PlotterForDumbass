//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_XYPLOTTER_H
#define UNTITLED2_XYPLOTTER_H

#include "../Point/BasePoint2.h"
#include "../../Interface/Plotter.h"
#include "../../Interface/Color.h"
#include "../Line/Line2.h"


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
        Text* pText;
        pLine = new Line2(new BasePoint2<float>(-1.0f, 0.0f), new BasePoint2<float>(1.0f, 0.0f));
        lines.insert(pLine);
        pText = new Text("X1", new BasePoint2<float>(0.9f, 0.02f, (Color&)Color::whiteColor), 2);
        texts.insert(pText);
        pLine = new Line2(new BasePoint2<float>(0.0f, -1.0f), new BasePoint2<float>(0.0f, 1.0f));
        lines.insert(pLine);
        pText = new Text("X2", new BasePoint2<float>(0.02f, 0.9f, (Color&)Color::whiteColor), 2);
        texts.insert(pText);
    }

public:
    XYPlotter(Drawer& drawerInstance, Color& color) : Plotter(drawerInstance), color(color)
    {}

    explicit XYPlotter(Drawer& drawerInstance) : XYPlotter(drawerInstance, (Color&)Color::whiteColor)
    {}

    XYPlotter() = default;
};



#endif //UNTITLED2_XYPLOTTER_H

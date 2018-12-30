//
// Created by bear on 30.12.18.
//

#ifndef UNTITLED2_XYPLOTTER_H
#define UNTITLED2_XYPLOTTER_H

#include "BasePoint2.h"
#include "../Interface/Plotter.h"


class XYPlotter : public Plotter
{
private:
    unsigned char lineColor[3];
    void generatePoints() override
    {

    }

    void generateLines() override
    {
        Point<double>* pPoint;
        pPoint = (Point<double>*)(new BasePoint2<float>(-1.0f, 0.0f));
        pPoint->setRGB(lineColor[0], lineColor[1], lineColor[2]);
        lines.push_back(pPoint);
        pPoint = (Point<double>*)(new BasePoint2<float>(1.0f, 0.0f));
        pPoint->setRGB(lineColor[0], lineColor[1], lineColor[2]);
        lines.push_back(pPoint);
        pPoint = (Point<double>*)(new BasePoint2<float>(0.0f, -1.0f));
        pPoint->setRGB(lineColor[0], lineColor[1], lineColor[2]);
        lines.push_back(pPoint);
        pPoint = (Point<double>*)(new BasePoint2<float>(0.0f, 1.0f));
        pPoint->setRGB(lineColor[0], lineColor[1], lineColor[2]);
        lines.push_back(pPoint);
    }

public:
    XYPlotter(Drawer& drawerInstance, const unsigned char lineColor[3]) : Plotter(drawerInstance)
    {
        this->lineColor[0] = lineColor[0];
        this->lineColor[1] = lineColor[1];
        this->lineColor[2] = lineColor[2];
    }

    explicit XYPlotter(Drawer& drawerInstance) : XYPlotter(drawerInstance, initializer_list<unsigned char>({ 255, 255, 255 }).begin())
    {}

    XYPlotter() = default;
};



#endif //UNTITLED2_XYPLOTTER_H

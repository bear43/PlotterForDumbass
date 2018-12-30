#include <iostream>
#include <vector>
#include "Implementation/Drawer/BaseDrawer.h"
#include "Implementation/Plotter/XYPlotter.h"

void f_x2(set<Point<float>*> &refPoints)
{
    float normalizedValue;
    BasePoint2<float>* pPoint;
    for(float x = -20; x <= 20; x+= 0.1f)
    {
        normalizedValue = x/20.0f;
        pPoint = new BasePoint2<float>(normalizedValue, normalizedValue*normalizedValue);
        pPoint->setSize(2.0f);
        refPoints.insert(pPoint);
    }
}

void f_x(set<Point<float>*> &refPoints)
{
    float normalizedValue;
    BasePoint2<float>* pPoint;
    for(float x = -20; x <= 20; x+= 0.1f)
    {
        normalizedValue = x/20.0f;
        pPoint = new BasePoint2<float>(normalizedValue, normalizedValue);
        pPoint->setSize(2.0f);
        refPoints.insert(pPoint);
    }
}

int main()
{
    /*thread th([]() -> void {
        BaseDrawer bs;
        XYPlotter xp(bs);
        xp.update();
        bs.init();
    });
    th.join();*/
    BaseDrawer bs;
    XYPlotter xp(bs);
    xp.update();
    set<Point<float>*> &refPoints = bs.getPoints();
    f_x(refPoints);
    BaseDrawer::init();
    return 0;
}
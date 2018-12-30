#include <iostream>
//#include <thread>
#include <vector>
#include "Implementation/BaseDrawer.h"
#include "Implementation/XYPlotter.h"

void f_x2(vector<Point<double>*> &refPoints)
{
    double normalizedValue;
    BasePoint2<double>* pPoint;
    for(double x = -20; x <= 20; x+= 0.1)
    {
        normalizedValue = x/20.0;
        pPoint = new BasePoint2<double>(normalizedValue, normalizedValue*normalizedValue);
        pPoint->setRGB(128, 32, 0);
        pPoint->setSize(2.0f);
        refPoints.push_back(pPoint);
    }
}

void f_x(vector<Point<double>*> &refPoints)
{
    double normalizedValue;
    BasePoint2<double>* pPoint;
    for(double x = -20; x <= 20; x+= 0.1)
    {
        normalizedValue = x/20.0;
        pPoint = new BasePoint2<double>(normalizedValue, normalizedValue);
        pPoint->setRGB(128, 32, 0);
        pPoint->setSize(2.0f);
        refPoints.push_back(pPoint);
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
    vector<Point<double>*> &refPoints = bs.getPoints();
    f_x(refPoints);
    bs.init();
    return 0;
}
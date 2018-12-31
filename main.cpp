#include <iostream>
#include <vector>
#include "Implementation/Drawer/BaseDrawer.h"
#include "Implementation/Plotter/XYPlotter.h"
#include "Implementation/Line/LineSeries2.h"

void f_x2(set<LineSeries*> &refLineSeries)
{
    float normalizedValue;
    BasePoint2<float> *pPoint, *pPoint2;
    auto series = new LineSeries2();
    for(float x = -20; x <= 20;)
    {
        normalizedValue = x/20.0f;
        pPoint = new BasePoint2<float>(normalizedValue, normalizedValue*normalizedValue);
        pPoint->setSize(2.0f);
        x ++;
        normalizedValue = x/20.0f;
        pPoint2 = new BasePoint2<float>(normalizedValue, normalizedValue*normalizedValue);
        pPoint2->setSize(2.0f);
        series->addLine(new Line2(pPoint, pPoint2));
    }
    refLineSeries.insert(series);
}

void f_x(set<LineSeries*> &refLineSeries)
{
    float normalizedValue;
    BasePoint2<float> *pPoint, *pPoint2;
    auto series = new LineSeries2();
    for(float x = -20; x <= 20;)
    {
        normalizedValue = x/20.0f;
        pPoint = new BasePoint2<float>(normalizedValue, normalizedValue);
        pPoint->setSize(2.0f);
        x ++;
        normalizedValue = x/20.0f;
        pPoint2 = new BasePoint2<float>(normalizedValue, normalizedValue);
        pPoint2->setSize(2.0f);
        series->addLine(new Line2(pPoint, pPoint2));
    }
    refLineSeries.insert(series);
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
    auto &refPoints = (set<LineSeries*> &)bs.getLineSeries();
    f_x2(refPoints);
    bs.setScale(1.0f);
    BaseDrawer::init();
    return 0;
}
//
// Created by kostya on 31.12.18.
//

#ifndef UNTITLED2_LINESERIES_H
#define UNTITLED2_LINESERIES_H


#include "Renderable.h"
#include "Line.h"
#include <set>

class LineSeries : public Renderable
{
public:
    virtual set<Line*>& getLinesSet() = 0;
    virtual void setLinesSet(set<Line*> &lines) = 0;
    virtual void addLine(Line* line) = 0;
    virtual bool removeLine(Line* line) = 0;
};


#endif //UNTITLED2_LINESERIES_H

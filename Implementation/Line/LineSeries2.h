#include <utility>

//
// Created by kostya on 31.12.18.
//

#ifndef UNTITLED2_LINESERIES2_H
#define UNTITLED2_LINESERIES2_H


#include "../../Interface/LineSeries.h"
#include <set>
#include <algorithm>

class LineSeries2 : public LineSeries
{
protected:
    set<Line*> lines;
public:
    explicit LineSeries2(set<Line*> lines) : lines(std::move(lines))
    {}

    LineSeries2() = default;

    ~LineSeries2()
    {
        for(Line* pLine : lines)
            delete pLine;
    }

    set<Line *> &getLinesSet() override
    {
        return reinterpret_cast<set<Line *> &>(lines);
    }

    void setLinesSet(set<Line *> &lines) override
    {
        lines.clear();
        lines = lines;
    }

    void addLine(Line *line) override
    {
        lines.insert(line);
    }

    bool removeLine(Line *line) override
    {
        auto it = find(lines.begin(), lines.end(), line);
        if(it == lines.end()) return false;
        lines.erase(it);
        return true;
    }

    void render() override
    {
        for(Line* pLine : lines)
            pLine->render();
    }
};


#endif //UNTITLED2_LINESERIES2_H

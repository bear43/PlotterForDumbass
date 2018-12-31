//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_BASEDRAWER_H
#define UNTITLED2_BASEDRAWER_H

#include "../../Interface/Drawer.h"
#include "../../Interface/Point.h"
#include "../../Interface/Text.h"
#include "../../Interface/LineSeries.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

class BaseDrawer : public Drawer
{
private:
    set<Point<float>*> points;
    set<Line*> lines;
    set<Text*> texts;
    set<LineSeries*> lineSeries;
    float scale = 1.0f;
public:
    void render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glScalef(scale, scale, scale);
        for(Point<float>* p : points)
            p->render();
        for(Line* p : lines)
            p->render();
        for(Text* p : texts)
            p->out();
        for(LineSeries* p : lineSeries)
            p->render();
        Text::out("test", 0.5f, 0.5f, 0.0f, 255, 127, 0, 255, 5);
        glPopMatrix();
        glFlush();
        glutSwapBuffers();
        glutPostRedisplay();
    }

    void resize(int x, int y) override
    {
        glViewport(0, 0, x, y);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glutPostRedisplay();
    }

    BaseDrawer()
    {
        drawerInstances.push_back(this);
    }

    set<Point<float>*> &getPoints()
    {
        return points;
    }

    void setPoints(set<Point<float>*> &points)
    {
        BaseDrawer::points = points;
    }

    set<Line*> &getLines()
    {
        return lines;
    }

    void setLines(set<Line*> &lines)
    {
        BaseDrawer::lines = lines;
    }

    set<Text*> &getTexts()
    {
        return texts;
    }

    void setTexts(set<Text *> &texts)
    {
        BaseDrawer::texts = texts;
    }

    void addText(Text *text) override
    {
        texts.insert(text);
    }

    bool removeText(Text *text) override
    {
        auto it = find(texts.begin(), texts.end(), text);
        if(it == texts.end()) return false;
        texts.erase(it);
        return true;
    }

    void addPoint(Point<float> *point) override
    {
        points.insert(point);
    }

    bool removePoint(Point<float> *point) override
    {
        auto it = find(points.begin(), points.end(), point);
        if(it == points.end()) return false;
        points.erase(it);
        return true;
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

    float getScale() const
    {
        return scale;
    }

    void setScale(float scale)
    {
        BaseDrawer::scale = scale;
    }

    const set<LineSeries *> &getLineSeries() const
    {
        return lineSeries;
    }

    void setLineSeries(const set<LineSeries *> &lineSeries)
    {
        BaseDrawer::lineSeries = lineSeries;
    }

    void addLineSeries(LineSeries* series)
    {
        lineSeries.insert(series);
    }
};


#endif //UNTITLED2_BASEDRAWER_H

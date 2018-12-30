//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_BASEDRAWER_H
#define UNTITLED2_BASEDRAWER_H

#include "../../Interface/Drawer.h"
#include "../../Interface/Point.h"
#include <iostream>
#include <cmath>

class BaseDrawer : public Drawer
{
private:
    vector<Point<double>*> points;
    vector<Line*> lines;
public:
    void render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        for(Point<double>* p : points)
            p->render();
        for(Line* p : lines)
            p->render();
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

    vector<Point<double>*> &getPoints()
    {
        return points;
    }

    void setPoints(vector<Point<double>*> &points)
    {
        BaseDrawer::points = points;
    }

    vector<Line*> &getLines()
    {
        return lines;
    }

    void setLines(vector<Line*> &lines)
    {
        BaseDrawer::lines = lines;
    }
};


#endif //UNTITLED2_BASEDRAWER_H

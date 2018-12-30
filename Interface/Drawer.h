//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_DRAWER_H
#define UNTITLED2_DRAWER_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "Point.h"

#define DEFAULT_WIDTH 640
#define DEFAULT_HEIGHT 480
#define DEFAULT_TITLE "PSUTI is in a pocket. Putin is in a rocket. session? I fucked it!"

using namespace std;

class Drawer
{
protected:
    static int width;
    static int height;
    static string title;
    static vector<Drawer*> drawerInstances;
    static void generalRender()
    {
        for(Drawer* instance : drawerInstances)
            instance->render();
    }
    static void generalResize(int x, int y)
    {
        for(Drawer* instance : drawerInstances)
            instance->resize(x, y);
    }
    static bool inited;
public:
    Drawer() = default;
    ~Drawer()
    {
        for(Drawer* dr : drawerInstances)
        {
            for(Point<double>* pPoint : dr->getPoints())
                delete pPoint;
            for(Point<double>* pLine : dr->getLines())
                delete pLine;
        }
        drawerInstances.erase(find(drawerInstances.begin(), drawerInstances.end(), this));
    }
    virtual void render() = 0;

    virtual void resize(int x, int y) = 0;

    static void init()
    {
        if(!inited)
        {
            cout << "Initializing GLUT library..." << endl;
            int argc = 0;
            char** argv;
            glutInit(&argc, argv);
            glutInitWindowSize(width, height);
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
            glutCreateWindow(title.c_str());
            glutDisplayFunc(generalRender);
            glutReshapeFunc(generalResize);
            cout << "GLUT is ready! Entering main loop..." << endl;
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            inited = true;
            glutMainLoop();
        }
    }

    static int getWidth();

    static void setWidth(int width);

    static int getHeight();

    static void setHeight(int height);

    static const string &getTitle();

    static void setTitle(const string &title);

    virtual vector<Point<double>*> &getPoints() = 0;

    virtual void setPoints(vector<Point<double>*> &points) = 0;

    virtual vector<Point<double>*> &getLines() = 0;

    virtual void setLines(vector<Point<double>*> &lines) = 0;
};

vector<Drawer*> Drawer::drawerInstances;
bool Drawer::inited = false;
int Drawer::width = DEFAULT_WIDTH;
int Drawer::height = DEFAULT_HEIGHT;
string Drawer::title = DEFAULT_TITLE;

int Drawer::getWidth()
{
    return width;
}

void Drawer::setWidth(int width)
{
    Drawer::width = width;
}

int Drawer::getHeight()
{
    return height;
}

void Drawer::setHeight(int height)
{
    Drawer::height = height;
}

const string &Drawer::getTitle()
{
    return title;
}

void Drawer::setTitle(const string &title)
{
    Drawer::title = title;
}

#endif //UNTITLED2_DRAWER_H
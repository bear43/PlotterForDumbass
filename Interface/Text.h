#include <utility>

//
// Created by kostya on 30.12.18.
//

#ifndef UNTITLED2_TEXT_H
#define UNTITLED2_TEXT_H

#include <string>
#include <cstring>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "Point.h"

using namespace std;

class Text
{
private:
    string str;
    Point<float> *p;
    unsigned char size;

public:

    Text() = default;

    Text(string &str, Point<float>* point, unsigned char size) : str(str), p(point), size(size)
    {}

    Text(string str, Point<float>* point, unsigned char size) : str(std::move(str)), p(point), size(size)
    {}

    ~Text()
    {
        delete p;
    }

    static void out(const unsigned char* c_str, float x, float y, float z, unsigned char red, unsigned char green, unsigned char blue,
                    unsigned char alpha, unsigned char size)
    {
        glPushMatrix();
        float s = size/3000.0f;
        glTranslatef(x, y, z);
        glScalef(s, s, s);
        glColor4ub(red, green, blue, alpha);
        glutStrokeString(GLUT_STROKE_ROMAN, c_str);
        glPopMatrix();
    }
    static void out(string str, float x, float y, float z, unsigned char red, unsigned char green, unsigned char blue,
                    unsigned char alpha, unsigned char size)
    {
        out((const unsigned char*)str.c_str(), x, y, z, red, green, blue, alpha, size);
    }
    void out()
    {
        out(str, (*p)[0], (*p)[1], (*p)[2], p->getColor()[0], p->getColor()[1], p->getColor()[2], p->getColor()[3], size);
    }
};


#endif //UNTITLED2_TEXT_H

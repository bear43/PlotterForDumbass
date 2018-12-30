//
// Created by bear on 29.12.18.
//

#ifndef UNTITLED2_POINT_H
#define UNTITLED2_POINT_H

#include <vector>
#include <GL/gl.h>

using namespace std;
template <typename T>
class Point
{
protected:
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    float size = 1.0f;
public:
    //virtual explicit Point(vector<T> points) = 0;

    Point() = default;

    virtual void render() = 0;

    virtual vector<T> getPoints() = 0;

    virtual void setPoints(vector<T> &points) = 0;

    unsigned char getR() const
    {
        return r;
    }

    void setR(unsigned char r)
    {
        Point::r = r;
    }

    unsigned char getG() const
    {
        return g;
    }

    void setG(unsigned char g)
    {
        Point::g = g;
    }

    unsigned char getB() const
    {
        return b;
    }

    void setB(unsigned char b)
    {
        Point::b = b;
    }

    void setRGB(unsigned char r, unsigned char g, unsigned char b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    float getSize() const
    {
        return size;
    }

    void setSize(float size)
    {
        Point::size = size;
    }
};


#endif //UNTITLED2_POINT_H

//
// Created by kostya on 30.12.18.
//

#ifndef UNTITLED2_COLOR_H
#define UNTITLED2_COLOR_H

#include <algorithm>

using namespace std;

class Color final
{
protected:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
public:
    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : red(red), green(green),
                                                                                             blue(blue), alpha(alpha)
    {}

    Color(unsigned char red, unsigned char green, unsigned char blue) : Color(red, green, blue, 255)
    {}

    Color() : Color(0, 0, 0)
    {}

    unsigned char getRed() const
    {
        return red;
    }

    void setRed(unsigned char red)
    {
        Color::red = red;
    }

    unsigned char getGreen() const
    {
        return green;
    }

    void setGreen(unsigned char green)
    {
        Color::green = green;
    }

    unsigned char getBlue() const
    {
        return blue;
    }

    void setBlue(unsigned char blue)
    {
        Color::blue = blue;
    }

    unsigned char getAlpha() const
    {
        return alpha;
    }

    void setAlpha(unsigned char alpha)
    {
        Color::alpha = alpha;
    }

    /**
     *
     * @return Color in u_byte format: { red, green, blue }
     */
    const unsigned char* getUnsignedByteArray3c()
    {
        return initializer_list<unsigned char>({ red, green, blue }).begin();
    }

    /**
     *
     * @return Color in u_byte format: { red, green, blue, alpha }
     */
    const unsigned char* getUnsignedByteArray4c()
    {
        return initializer_list<unsigned char>({ red, green, blue, alpha }).begin();
    }

    /**
     *
     * @return Color in float format: { red, green, blue }
     */
    const float* getFloatArray3c()
    {
        float red = (float)(this->red)/255.0f;
        float green = (float)(this->green)/255.0f;
        float blue = (float)(this->blue)/255.0f;
        return initializer_list<float>({ red, green, blue }).begin();
    }

    /**
     *
     * @return Color in float format: { red, green, blue, alpha }
     */
    const float* getFloatArray4c()
    {
        float red = (float)(this->red)/255.0f;
        float green = (float)(this->green)/255.0f;
        float blue = (float)(this->blue)/255.0f;
        float alpha = (float)(this->alpha)/255.0f;
        return initializer_list<float>({ red, green, blue, alpha }).begin();
    }

    static const Color redColor;
    static const Color greenColor;
    static const Color blueColor;
    static const Color whiteColor;
    static const Color blackColor;

    unsigned char operator[](int index)
    {
        switch (index)
        {
            case 0:
                return red;
            case 1:
                return green;
            case 2:
                return blue;
            case 3:
                return alpha;
            default:
                return 0;
        }
    }
};

/**
 * Usual colors to use
 */
const Color Color::redColor(255, 0, 0);
const Color Color::greenColor(0, 255, 0);
const Color Color::blueColor(0, 0, 255);
const Color Color::whiteColor(255, 255, 255);
const Color Color::blackColor(0, 0, 0);


#endif //UNTITLED2_COLOR_H

#ifndef PIXEL_H
#define PIXEL_H

//
// Created by Jad Zeineddine on 11/24/16.
//

#include <cmath>
#include <iostream>
#include <stdlib.h>
#pragma once

class Pixel {

private:

    int red=0;
    int green;
    int blue;

public:


Pixel colorConverter(int hexValue);
    //sets the red value
    void setRed(int x){
        red=x;
    }
    
    //sets the green value
    void setGreen(int x){
        green=x;
    }
    //sets the blue value
    void setBlue(int x){
        blue=x;
    }
    //tests if pixel is almost or is black 
    bool isPrettyBlack();
    
    //tests if pixel is a scelera pixel (more red)
    bool isPrettySclera();
    
    //tests if pixel is actually black
    bool isActuallyBlack();
    
    //tests if pixel is almost or is white
    bool isPrettyWhite();
    
    //makes a pixel blacl
    void makeBlack();
    
    //makes a pixel white
    void makeWhite();
    
    //gets the red value from a pixel
    int getRed();

    //gets the blue value from a pixel
    int getBlue();

    //gets the green value from a pixel
    int getGreen();

    //gets the average value of the rgb pixel, or brightness
    int getBrightness();

    //brightens the pixel by a factor
    void brighten(Pixel &x, double factor);

    //construct a pixel of rgb
    Pixel(int r, int g, int b);
    
    //defualt constructor
    Pixel();

};

#endif

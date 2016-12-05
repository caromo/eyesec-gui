

#include "Pixel.h"

using namespace std;
/*
create constructor with member functions
*/
Pixel Pixel::colorConverter(int hexValue)
{
    Pixel trenton;//create an object for each pixel in the inputted image

    trenton.red = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
    trenton.green = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG bytez
    trenton.blue = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

    return trenton;
}

//the following are getters for each color; these are used in a variety of other program methods

int Pixel::getRed(){
    //cout<< "returned red" << endl;
return red;
}

int Pixel::getBlue(){
return blue;
}

int Pixel::getGreen(){
return green;
}

//if the Pixel is nearly black but not entirely
bool Pixel::isPrettyBlack(){
    int variance = 20;//this is the threshold ratio set, it is used in the if else statement
    
    Pixel p=*this;
    /*
    compares the level of black to a threshold (int variance) to determine how close to black the color is
    */
    if (    abs(  p.getGreen() - p.getBlue()  )<variance    &&   abs(  p.getBlue() - p.getRed()  )<variance  &&  abs(  p.getGreen() - p.getRed()  )<variance   && ( p.getBrightness()<45 )    ) {
    return true;
    }
    else
        return false;
}


//if the pixel is entirely black
bool Pixel::isActuallyBlack(){
    //Pixel p = *this;
    if(getBrightness()<3){
        //cout<< "works"<< endl;
    
    return true;
    }
    
    else {
        return false;
    }
}

bool Pixel::isPrettyWhite(){//similar to the pretty black function, but for white
    int variance = 50;//this is the threshold used
    
    Pixel p=*this;
    //the following compares the colors in the pixel object to see if it is under a certain threshold (int variance)
    if (    abs(  p.getGreen() - p.getBlue()  )<variance    &&   abs(  p.getBlue() - p.getRed()  )<variance  &&  abs(  p.getGreen() - p.getRed()  )<variance   && ( p.getBrightness()>70)    ) {
        return true;//the pixel is close to white
    }
    else
        return false;//the pixel is not considered close to white
}

bool Pixel::isPrettySclera(){//this will find if the pixel lies close to the edge of the eye, or the sclera
    int variance = 5;//theshold used
    
    Pixel p=*this;
    if (    (p.getRed()-p.getGreen())> variance && (p.getRed()-p.getBlue()) >variance && ( p.getBrightness()>65)    ) {
        return true;
    }
    else
        return false;
}

void Pixel::makeBlack(){//if the prettyBlack function returns true, the pixel is set to complete black
    Pixel p=*this;
    p.setBlue(0);
    p.setGreen(0);
    p.setBlue(0);
}

void Pixel::makeWhite(){//if the prettyWhite function returns true, the pixel is set to completely white
    
    this->red=255;
    this->blue=255;
    this->green=255;
}


void Pixel::brighten(Pixel &x, double factor){//this will brighten the pixel for color comparison purposes
    //the following will increase the brightness of the passed-in pixel by a passed-in factor
    factor = 1/factor;
    x.red=(int)((double)x.red*factor);
    x.blue=(int)((double)x.blue*factor);
    x.green= (int)((double)x.green*factor);
    
    return;
}

int Pixel::getBrightness(){//returns an int of the pixel's brightness level
    int i = (int)(((double)getRed()+(double)getGreen()+(double)getBlue())/3);
    return i;
}

Pixel::Pixel(int r, int g, int b) {//a pixel constructor with the color member variables
    red=r;
    green=g;
    blue=b;
}


Pixel::Pixel() {//a pixel constructor with colors set to 0

    red= 0;
    green= 0;
    blue=0;

}

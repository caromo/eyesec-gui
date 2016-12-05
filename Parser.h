#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <iostream>

#include "Pixel.h"

using namespace std;
class Parser {

private:
    
    
    void makePupilBW();
    //gets center coordinates of pupil
    vector<int> findPupil();
    //gets weighted center of black cirlce
    vector<int> getWeightedCenter(vector<vector<int> >, int bound);
    //global variables
    int largestPupilRadius = 0;
    int minRadius;
    int varianceInRadius;
    //these are methods for getting the radius from a black pixel to the edge of pupil
    int getUpRadius(int i , int j );
    int getDownRadius(int i , int j);
    int getLeftRadius(int i, int j);
    int getRightRadius(int i , int j);
    
    //these check to see if the radii meet the requirements for a pupil size
    bool isLargestRadius(vector<int> radii);
    bool isCircularEnough(vector<int> radii);
    bool isLargeEnough(vector<int> radii);
    //gets the average radius size of a vector of radii
    int getAvg(vector<int> radii);
    //center of pupil global variables
    int pupilI=0;
    int pupilJ=0;
    //gets the radiusvector at a certain point
    vector<int> getRadiusVector(int i, int j);
    //stores the left edge coordinate of the pupil
    int getLeftEdgeCoordinates();

public:
    //picture and bw array are for parsing through the 2d Pixel vector, they are public for displaying purposes
    vector<vector<Pixel> > picture;
    vector<vector <Pixel> > BWArray;
    //constructor that takes in a picture
    Parser(vector <vector<Pixel> > pic);
    //gets the iris array of a picture
    vector <Pixel> getIrisArray();
};

#endif

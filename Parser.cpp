#include "Parser.h"
using namespace std;

//constructor for Parser, you must pass in a 2dvector of Pixel to Parser
Parser::Parser(vector <vector<Pixel> > pic) {
    picture=pic;
    //BWArrau is resized to the correct widght and height
    BWArray.resize(pic.size(),vector<Pixel>(pic[0].size(),Pixel()));
    //then it is correctly made into a grayscale with this function
    makePupilBW();

}

//this will make the BWarray black and white in order to find the center of the pupil
void Parser::makePupilBW(){
    
    //2d for loop to go through the 2d picture
    for (int i = 0; i< picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
        
            //if the pixel at picture pixel is almost black, make it completely black
            if(picture[i][j].isPrettyBlack()){
                BWArray[i][j].makeBlack();
            }
            //else make it white
            else{
                BWArray[i][j].makeWhite();
            }
        
        
        }
        
    }
    
}



//will find the center of the pupil and return it as a x,y coordinates in 1d vector
vector<int> Parser::findPupil() {
    vector<int> coordinates;
    //weighted center vector, may not need to do this
    vector<vector<int> > a;
    //change this for pupil circularity
    double varianceInRadiusValue=.04;
    //change this for pupil size
    double varianceInSize = .05;
    //minumim circularity
    varianceInRadius = varianceInRadiusValue*BWArray.size();
    //minimum size of pupil
    minRadius = (int) ((double)varianceInSize*((double)BWArray.size()/2));
    //set global variables
    int saveI = 0;
    int saveJ = 0;
    
    
    //cout<< "finding pupil" << endl;
    
    vector <int> radii;
    
    //2d vector to go thorugh and look to see if their is a valid pupil
    //a valid pupil is large enough, and is circular.
    for (int i = 0; i < BWArray.size(); i++) {
        for (int j = 0; j < BWArray[0].size(); j++) {
            //if a pixel in the BWarray is black, then check for a valid pupil
            if (BWArray[i][j].isActuallyBlack()) {
                //this gets a vector of the size of the radius from 3 sides
                radii = getRadiusVector(i, j);
                //cout<< "is circular " << isCircularEnough(radii) << "  is it largest? " << isLargestRadius(radii) <<  "   and is it large enough ? " << isLargeEnough(radii) << endl;
                //this if looks to see if conditions are met for valid pupil given the radii surrounding that pixel
                if(isCircularEnough(radii)  && isLargestRadius(radii) && isLargeEnough(radii)){
                    //if they do meet, then set the global variables as that coordinate
                    saveI=i;
                    saveJ=j;
                    
                }
            }
        }
    }
    
    cout<< "min radius is " << minRadius<< endl;
    cout<< "largestPupilRadius is " << largestPupilRadius<< endl;
    
    cout<< "I is " << saveI << endl;
    cout<< "J is " << saveJ << endl;
    
    //if we dont have a pupil size that is big enough then throw error
    if (largestPupilRadius<minRadius) {
        cout<< "error Pupil not large enough"<< endl;
    }
    
    //add the pupil coordinates to both the coordinates vector and global coordinates pupilJ and pupilI
    coordinates.push_back(saveI);
    coordinates.push_back(saveJ);
    pupilJ=saveJ;
    pupilI=saveI;
    
    return coordinates;

}


//Gets the amount of black pixels above the pixel coordinates passed
int Parser::getUpRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack()  && i > 0; i--) {
        radCounter++;
        //cout<< "radcounter = "<<radCounter<< endl;
    }
    
    return radCounter;
}
//Gets the amount of black pixels bellow the pixel coordinates passed
int Parser::getDownRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack(); i++) {
        radCounter++;
    }
    
    return radCounter;
}

//Gets the amount of black pixels to the right of the pixel coordinates passed
int Parser::getRightRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack(); j++) {
        radCounter++;
    }
    
    return radCounter;
}



//Gets the amount of black pixels to the left of the pixel coordinates passed
int Parser::getLeftRadius(int i, int j){
    int radCounter=0;
    for (; BWArray[i][j].isActuallyBlack(); j--) {
        radCounter++;
    }
    
    return radCounter;
}


//puts the number of black pixels above, below, left right, in a single vector
vector<int> Parser::getRadiusVector(int i, int j){
    
    vector<int> a;
    
    //you dont have to use RightRadiusm
    //add the differnt radii to one vector
    int radiusToAdd = getUpRadius(i, j);
    a.push_back(radiusToAdd);
    radiusToAdd = getDownRadius(i, j);
    a.push_back(radiusToAdd);
    radiusToAdd = getLeftRadius(i, j);
    a.push_back(radiusToAdd);
    radiusToAdd = getRightRadius(i, j);
    a.push_back(radiusToAdd);

    
    return a;
}


 //rgest Radius returns if the value is the largest radius
bool Parser::isLargestRadius(vector<int> radii){
    int r = getAvg(radii);
    if( r >= largestPupilRadius){
        
        largestPupilRadius = r;
        return true;
    }
    
    return false;
}





 //checks if all the radii are more than the minimum pupil size
bool Parser::isLargeEnough(vector<int> radii){
    for (int i = 0; i<radii.size(); i++) {
        if( i > minRadius)
            return false;
    }
    
    return true;
}

//checks if the pupil is circular enough based on the radii passed
//basically checks that the radii passed are similar in size
bool Parser::isCircularEnough(vector<int> radii){
    
    for (int i = 0; i+1 < radii.size() ; i++) {
        if(abs(radii[i]-radii[i+1]) > varianceInRadius)
            return false;
    }
    
    return true;
    
}

//gets the average radius size from a vector of radii
int Parser::getAvg(vector<int> radii){
    int sum=0;
    int i=0;
    for(; i < radii.size(); i++){
        sum+=radii[i];
    }
    //return with arithmetic precision
    return (int)(((double)sum/(double)i));
}

//gets weighted center, this funciton is for modularity more than for practical use
vector<int> Parser::getWeightedCenter(vector<vector<int> > b, int bound){
    //error catch more than inner vector of 3 length
    //inner vector should be <number of blacks, j>
    int heightCenter = 0;
    int widthCenter=0;
     //follow algorithm on boogie board
    int topSum = 0;
    int bottomSum = 0;
    //using the physics equation for center of mass
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            //multiply number of blacks in a row by position
            topSum +=( b[i][0] * b[i][1] );
            //add the positons
            bottomSum+= b[i][0];
        }
    }
    //divide
    heightCenter= (int) (((double)topSum) / ((double)bottomSum));
    
    //get the weighted average
    widthCenter= b[heightCenter][0]/2+bound;
    
    
    

    
    //return as a coordinate vector
    vector<int> a;
    a[0]=heightCenter;
    a[1]=widthCenter;
    
    
    
    
    return a;
}
//this finds the left edge of the pupil and returns that column value
int Parser::getLeftEdgeCoordinates(){
    
    int j = pupilJ;
    //go through until the j value is at the edge
    for(; BWArray[pupilI][j].isActuallyBlack(); j--){
        
    }
    
    //cout<< "left edge j = " << j<< endl;
    //return that edge value
    return j;
}

//gets the iris array slit in a 1d vector of pixels
vector<Pixel> Parser::getIrisArray() {
    //Add a method to this that adjusts brightness based on pupil and iris size (while loop until correct iris size);
    //in the future
    vector<Pixel> array;
    //get the x,y coordinates
    findPupil();
    //find the left edge coordinates of the pupil
    cout<< " getLeftEdgeCoordinates is " << getLeftEdgeCoordinates() << endl;
    //go from the left edge coordinates until you the sclera, that strip is the iris array
    for(int i = getLeftEdgeCoordinates(); !picture[pupilI][i].isPrettySclera(); i--){
        array.push_back(picture[pupilI][i]);
    }
    
    //return that strip
    return array;

}

#ifndef COMPARE_H
#define COMPARE_H

#include <vector>
#include <iostream>


#include "Pixel.h"

class Compare {
private:
	//the two slits of colored eye obtained by parser
	std::vector<Pixel>  iris1;
	std::vector<Pixel>  iris2;
	
	//the vector of color differences between the two eyes
	std::vector<int>  color_differences;
	
	//the percentage color difference between the eyes
	double percent_color_difference;
	
	//whether or not the eyes are the same
	bool is_same;
	
	//methods described in the cpp file
	void equalize_Arrays();
	void correct_Brightness_Differences();
	std::vector<int> find_Pattern_Differences();
	void find_Percent_Similarity();
public:
	//constructor
	Compare(std::vector<Pixel> iris1, std::vector<Pixel> iris2);
	
	//method called to determine if the people are the same
    	bool is_same_person();

};

#endif

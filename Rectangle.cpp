#include "Rectangle.hpp"

#include <algorithm>
#include <iostream>

Rectangle::Rectangle(long* arr):x1(arr[0]),y1(arr[1]),x2(arr[2]),y2(arr[3]){} //Constructor to be used to create the rectangle objects, assign parameters using initializer list

bool Rectangle::is_overlapping(Rectangle* other) const //Method to check if this rectangle is overlapping with another one or not
{

    //Get the sides of the first rectangle
    long r1_left = std::min(this->x1, this->x2);
    long r1_right = std::max(this->x1, this->x2);
    long r1_bottom = std::min(this->y1, this->y2);
    long r1_top = std::max(this->y1, this->y2);

    //Get the sides of the second rectangle
    long r2_left = std::min(other->x1, other->x2);
    long r2_right = std::max(other->x1, other->x2);
    long r2_bottom = std::min(other->y1, other->y2);
    long r2_top = std::max(other->y1, other->y2);
    
    // Check for non-overlap conditions and return false if not overlapping
    if((r1_left >= r2_right) || (r2_left >= r1_right) || (r1_bottom >= r2_top) || (r2_bottom >= r1_top)) 
        return false;
    

    // return true otherwise
    return true;
}

void Rectangle::DisplayRectangle() const //Method to Display rectangle corners coordinates for debugging
{
    std::cout<<"-------------------"<<std::endl;
    std::cout<<"X1: "<<x1<<" Y1: "<<y1<<std::endl;
    std::cout<<"X2: "<<x2<<" Y2: "<<y2<<std::endl;
    std::cout<<"-------------------"<<std::endl;
}

std::string Rectangle::GetRectangle() const //Method returns rectangle corners coordinates as string to be parsed in an output file in format (X1 Y1 X2 Y2)
{
    return (std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(x2) + " " + std::to_string(y2));
}
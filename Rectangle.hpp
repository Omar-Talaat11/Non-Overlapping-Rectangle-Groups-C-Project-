#ifndef RECTANGLE
#define RECTANGLE
#include <string>

class Rectangle //Class Responisble for holding Rectangle object
{
    private:
    long x1,y1,x2,y2; //Coordinates of Rectangle corners

    public:
    Rectangle() = delete; //Delete default constructor to avoid creating empty rectangle objects
    Rectangle(long* arr); //Constructor to be used to create the rectangle objects, assign parameters using initializer list
  
    bool is_overlapping(Rectangle* other) const; //Method to check if this rectangle is overlapping with another one or not
    

    void DisplayRectangle() const; //Method to Display rectangle corners coordinates for debugging

    
    std::string GetRectangle() const; //Method returns rectangle corners coordinates as string to be parsed in an output file in format (X1 Y1 X2 Y2)

};

#endif
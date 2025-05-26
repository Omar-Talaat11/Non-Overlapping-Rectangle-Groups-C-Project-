#ifndef RECTANGLEGROUPS
#define RECTANGLEGROUPS

#include <vector>
#include "Rectangle.hpp"


class RectangleGroups //Class Responisble for holding non-overlapping rectangle groups object
{
    private:
    std::vector<std::vector<Rectangle>*> groups; //2D vector where each raw is a group of non-overlapping rectangle objects
    // std::mutex mtx;

    public:
    RectangleGroups();// Default constructor


    ~RectangleGroups(); // Destructor


    void fillGroups(std::vector<Rectangle>& Rectangles); // Method that takes a vector containing all rectangles and assign them to a non-overlapping group
    
    void GetLastGroup(std::vector<Rectangle>& group);  //Method that moves the last group of the groups vector to passed vector

    
    int GetNumberOfGroups() const; //method that gets the number of groups created

};

#endif
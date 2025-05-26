#include "RectangleGroups.hpp"

#include <algorithm>
#include <iostream>

RectangleGroups::RectangleGroups()// Default constructor
{
    //Create an initial empty group and push it in our 2D vector

    std::vector<Rectangle>* group = new std::vector<Rectangle>;
    groups.push_back(group);
}

RectangleGroups::~RectangleGroups() // Destructor
{
    //loops over groups in our 2D vector and delete them if not equal nullptr
    for(std::vector<Rectangle>*group:groups)
    {
        if(group!=nullptr)delete group;
    }
}

void RectangleGroups::fillGroups(std::vector<Rectangle>& Rectangles) // Method that takes a vector containing all rectangles and assign them to a non-overlapping group
{

    // std::lock_guard<std::mutex> lock(mtx);
    
    //variable to store number of rectangles not processed yet
    long num_of_rectangles;
    if(groups[0]->size()==0) //check if no rectangle is added to the first group and add the first one if so
    {
        groups[0]->push_back(Rectangles.back()); //add the last rectangle in Rectangles vector to the first rectangle group vector
        Rectangles.pop_back(); //remove the rectangle from Rectangles vector
    }

    while(!Rectangles.empty()) //loop until all rectangles are processed
    {
        //Log remaining rectangles and number of groups created every (10,000) Rectangle
        if(Rectangles.size()%10000==0)std::cout<<"remaining: "<<Rectangles.size()<<" ,Number of groups: "<<groups.size()<<std::endl;
        

        num_of_rectangles = Rectangles.size(); //save number of rectangles before looping on the groups

        for(std::vector<Rectangle>*group:groups) //loop over all groups to check if this rectangle is can be added to one of them
        {
            bool overlap = false; //set boolean overlap to false initially
            
            //loop over all elements of the group to check whether the rectangle is overlapping with any of them or not
            std::for_each(group->begin(),group->end(),[&](Rectangle& thisRectangle)
            {
                if(thisRectangle.is_overlapping(&Rectangles.back()))overlap=true; //set boolean overlap to true if it is overlapping
            });

            if(!overlap)//check if the rectangle is not overlapping with any element of the group
            {

                group->push_back(Rectangles.back()); //add this rectangle to this group
                Rectangles.pop_back(); //remove the rectangle from the rectangles vector
                break; //break from the loop
            }
        }

        //check if the size of rectangles is the same, which means the rectangle is not added to any of the groups
        if( num_of_rectangles == Rectangles.size() ) 
        {
            std::vector<Rectangle>* group = new std::vector<Rectangle>; //create a new group
            group->push_back(Rectangles.back()); //add the rectangle to this group
            Rectangles.pop_back(); //remove the rectangle from the rectangles vector
            groups.push_back(group); //add the group to the groups vector
        }
    }
}

void RectangleGroups::GetLastGroup(std::vector<Rectangle>& group)  //Method that moves the last group of the groups vector to passed vector
{
    // std::lock_guard<std::mutex> lock(mtx);
    
    group = std::move(*(groups.back())); //move the group to the passed vector instead of copying
    delete groups.back(); //delete this group from the vector
    groups.pop_back();  //remove the pointer from the vector
}

int RectangleGroups::GetNumberOfGroups() const //method that gets the number of groups created
{
    return groups.size();
}
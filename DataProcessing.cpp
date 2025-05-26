#include "DataProcessing.hpp"

#include <sstream>
#include <algorithm>
#include <iostream>

DataProcessing::DataProcessing(const std::string&fname) //Constructor to be used to create the object and fill the vector of rectangles
{
    if(!openFile(fname)) //check if file is not opened and return if not
    {
        throw std::invalid_argument("Input file failed to open\n");
        return;
    }

    if(fs.tellg() == 0) //check if no input is given
    { 
        throw std::invalid_argument("Empty file given, please check the input file\n"); 
        return;
    }
    else
    {
        fs.clear();                  // Clear any EOF or fail bits
        fs.seekg(0, std::ios::beg);  // Move the get pointer to the beginning
    }
    
    std::string line; //Create a string to hold the line being processed
    long arr[4]; //Create an array with 4 elements representing x1 y1 x2 y2
    long r = 1; //long variable to hold number of rectangles processed
    std::string leftover; //variable to hold if there are leftovers each line
    while(std::getline(fs,line)) //loop and read each line until all rectangles in the txt file are finished
    {
        std::istringstream ss(line); //create an input string stream object from this line
        for (int i = 0; i < 4; i++) // Extract numbers directly into the array
        {
            if(!(ss >> arr[i])){throw std::invalid_argument("inputs with wrong format, less than 4 elements\n");return; } //check if the line doesn't contain less than 4 elements
        } 
        if(ss>>leftover) {throw std::invalid_argument("inputs with wrong format, more than 4 elements\n");return; } //check if there are leftovers in the line after 4 elements

        Rectangle R(arr); //Create a rectangle object using this array
        Rectangles.push_back(R); //add this rectangle to the rectangles vector

        if(!(r%100000)) std::cout<<"Read Rectangle: "<<r<<std::endl; //log number of read rectangles every (100,000) rectangle
        r++;
    }
    
}

DataProcessing::~DataProcessing() //Destructor
{
    if(fs.is_open())fs.close(); //check if the file is still opened and close it if so

    //loop on all the output files and close them if still opened
    std::for_each(ofiles.begin(),ofiles.end(),[](std::fstream&file)
    {
        if(file.is_open())file.close();
    });
}

bool DataProcessing::openFile(const std::string& fname) //Method to open the given file
{
    fs = std::fstream(fname,std::ios::in | std::ios::ate);
    return fs.is_open(); //return true if file opened successfully
}

void DataProcessing::Display_Rectangles() const //Method to print rectangles in the rectangle vector for logging or debugging
{
    int i = 0;
    for(Rectangle Rec:Rectangles) //loop on the rectangles and call DisplayRectangle() method for each one
    {
        std::cout<<"Rectangle "<<++i<<" : "<<std::endl; 
        Rec.DisplayRectangle();
    }
}

bool DataProcessing::WriteResults(RectangleGroups &groups) const //Method to write results in the output files
{
    int i = 1;
    std::vector<Rectangle> group;
    while(groups.GetNumberOfGroups()) //loop untill all groups are processed
    {
        std::string filename = OUTPUT_PATH + std::to_string(i++) +".txt"; //create output file name
        std::fstream file(filename,std::ios::out); //open the file

        if(!file.is_open()) //check if it failed to open
        {
            throw std::invalid_argument("Output directory failed to open\n");
            return false;
        }
        groups.GetLastGroup(group); //get the last group in the groups vector

        for(Rectangle rec:group) //read each rectangle in this group and write it in the file
        {
            file<<rec.GetRectangle()<<std::endl;
        }

    }

    return true; //return true if it wrote all groups successfully
}

std::vector<Rectangle>& DataProcessing::Get_Rectangles() //Method to get the filled rectangle vector 
{
    return Rectangles;
}

void DataProcessing::BatchData(std::vector<std::vector<Rectangle>>& rectangles_batches) const //Method to batch the data into smaller batches if needed
{
    long data_size = Rectangles.size();
    int num_batches = rectangles_batches.size();
    int batch_size = data_size / num_batches;

    auto it = Rectangles.begin();
    for(int i = 0 ; i < num_batches ; ++i)
    {
        auto start = it;
        auto end = (i==num_batches-1)?Rectangles.end():start+batch_size;

        rectangles_batches[i] = std::vector<Rectangle>(std::make_move_iterator(start),std::make_move_iterator(end));

        it = end;
    }
}

#ifndef DATAPROCESSING
#define DATAPROCESSING

#include <fstream>
#include <vector>

#include "RectangleGroups.hpp"
#include "Config.hpp"

class DataProcessing //Class Responisble for parsing the rectangle corners coordinates from the input files and the groups to the output files
{
    private:
    std::vector<Rectangle> Rectangles; //Vector of Rectangles to be filled from the input file
    std::fstream fs; //file stream obect of the input file
    std::vector<std::fstream> ofiles; //vector of filestream object of the output files

    
    public:
    DataProcessing() = delete; //Delete default constructor to avoid creating empty object
    DataProcessing(const std::string&fname); //Constructor to be used to create the object and fill the vector of rectangles
        
    ~DataProcessing(); //Destructor
    

    bool openFile(const std::string& fname); //Method to open the given file

    void Display_Rectangles() const; //Method to print rectangles in the rectangle vector for logging or debugging
    
    bool WriteResults(RectangleGroups &groups) const; //Method to write results in the output files
    
    std::vector<Rectangle> &Get_Rectangles(); //Method to get the filled rectangle vector 

    void BatchData(std::vector<std::vector<Rectangle>>& rectangles_batches) const; //Method to batch the data into smaller batches if needed

};

#endif
#include <iostream>
#include <memory>  

// #include <thread>
// #include <mutex>
// #include <chrono>

#include <vector>

#include "Config.hpp"
#include "DataProcessing.hpp"





int main()
{       
    try
    {
        /* 1 - Create DataProccessing object using input file path */
        std::unique_ptr<DataProcessing> Data = std::make_unique<DataProcessing>(INPUT_FILE);

        /* 2 - Create rectangles vector using Get_Rectangles() method from DataProcessing object */
        std::vector<Rectangle> dataRectangles(Data->Get_Rectangles());
        
        /* 3 - Create RectangleGroups object to hold the groups to be created */
        RectangleGroups myGroups;

        /* 4 - fill the RectangleGroups object with rectangles vector */
        myGroups.fillGroups(dataRectangles);

        /* 5 - Write results to output files using WriteResults() method from DataProcessing object  */
        Data->WriteResults(myGroups);

    }
    catch(std::exception const&e)
    {
        std::cerr<<e.what();
    }
}
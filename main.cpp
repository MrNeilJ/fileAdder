/************************************************************
** Author: Neil Johnson
**
** Date: 1.20.2017
**
** Description: This program will prompt the user for the
** name of a file that has numbers saved in it and tries to
** open the file.  If it is open-able it will read through
** the integers in the file, add them all up, and then
** return the sum to another file named "sum.txt"
************************************************************/

#include <iostream>
#include <fstream>


int main() {
    // Variables needed for the program
    std::string userFilename;

    int totalSum = 0,
            currentNum;

    // Ask the user for the name of the file
    std::cout << "Type in the file you are looking to add up (include extension)" << std::endl;
    std::cin >> userFilename;

    std::ifstream inputFile(userFilename);

    // Make sure the file opened properly
    if (inputFile)
    {
        while (inputFile >> currentNum)
        {
            totalSum += currentNum;
        }
    }
    else
    {
        std::cout << "Could not access file" << std::endl;
        return 1;
    }

    // Close the current open file
    inputFile.close();

    // Open Sum file for writing
    std::ofstream outputFile("sum.txt");

    // Ensure the the file opens properly
    if (outputFile)
    {

        // Write Sum to the file
        outputFile << totalSum;

        // Let the user know that the output was successful
        std::cout << "Output complete! Go see the results in the file sum.txt" << std::endl;
    }
    else
    {
        std::cout << "Could not access file" << std::endl;
        return 1;
    }
    outputFile.close();

    return 0;
}
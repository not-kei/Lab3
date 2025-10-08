/*
	Olivia Dodds
	C++ FA2025
	Due: Oct 14th, 2025
	Lab 3 User and File I/O
	Using values from both the user and the file inMeanStd, calculates the Mean and Population Standard Deviation, then outputs the files
	on the screen to the user as well as to the file outMeanStd
*/

#include <iostream>
#include <fstream>
#include <cmath>

//function prototypes
float calculateMean(float value1, float value2, float value3, float value4);
float calculateStandardDeviation(float value1, float value2, float value3, float value4, float curMeanValue);

int main()
{
	//variables
	int inputValue1;
	int inputValue2;
	int inputValue3;
	int inputValue4;

	//inserting values to the variables
	std::cout << "Please enter in some values. (Must be 4 values)" << std::endl;
	std::cin >> inputValue1;
	std::cin >> inputValue2;
	std::cin >> inputValue3;
	std::cin >> inputValue4;

	//calculate the user inputted values
	float curMeanValue = calculateMean(inputValue1, inputValue2, inputValue3, inputValue4);
	std::cout << "The Mean value using user inserted values is: " << curMeanValue << std::endl;
	std::cout << "The Standard Deviation using user inserted values is: " << calculateStandardDeviation(inputValue1, inputValue2, inputValue3, inputValue4, curMeanValue) << std::endl;

	//putting values into file
	std::ofstream outFile;
	outFile.open("outMeanStd.dat");
	outFile << "Mean value for user inputted values is: " << curMeanValue << std::endl;
	outFile << "Standard Deviation for user inputted values is: " << calculateStandardDeviation(inputValue1, inputValue2, inputValue3, inputValue4, curMeanValue) << std::endl;


	//opening the file inMeanStd.dat and changing variables to file's values
	std::ifstream inFile;
	inFile.open("inMeanStd.dat");
	inFile >> inputValue1;
	inFile >> inputValue2;
	inFile >> inputValue3;
	inFile >> inputValue4;
	inFile.close(); //closing the file

	//calculate the file inputted values
	curMeanValue = calculateMean(inputValue1, inputValue2, inputValue3, inputValue4);
	std::cout << "The Mean value using values from the file is: " << curMeanValue << std::endl;
	std::cout << "The Standard Deviation using values from the file is: " << calculateStandardDeviation(inputValue1, inputValue2, inputValue3, inputValue4, curMeanValue) << std::endl;

	//putting values into file
	outFile << "Mean value for file inputted values is: " << curMeanValue << std::endl;
	outFile << "Standard Deviation for file inputted values is: " << calculateStandardDeviation(inputValue1, inputValue2, inputValue3, inputValue4, curMeanValue) << std::endl;

	//closing file
	outFile.close();

	return 0;
}

//calculates the Mean value using values from both the user and the file
float calculateMean(float value1_, float value2_, float value3_, float value4_)
{
	return (value1_ * value2_ * value3_ * value4_) / 4;
}

//calculates the StandardDeviation value using values from both the user and the file
float calculateStandardDeviation(float value1_, float value2_, float value3_, float value4_, float curMeanValue_)
{
	return std::sqrt((pow(value1_ - curMeanValue_, 2) + pow(value2_ - curMeanValue_, 2) + pow(value3_ - curMeanValue_, 2) +
		pow(value4_ - curMeanValue_, 2)) / 4);
}
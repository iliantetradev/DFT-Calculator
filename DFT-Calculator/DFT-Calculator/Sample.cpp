#include "Sample.h"
using namespace std;

Sample::Sample()
{
}

Sample::~Sample()
{
}

void Sample::getValueFromFile(string inputFileName, int degr)
{
	double xtemp = 0, ytemp;  //variables to temprorary store values from text file
	int i = 0;
	ifstream inputFileStream(inputFileName);   //selecting the file to be read
	if (inputFileStream.is_open())
	{
		while (!inputFileStream.eof() && (i == 0))
		{
			inputFileStream >> xtemp;   //storing the values from first column - degrees

			inputFileStream >> ytemp;   //storing the values for the wave
			if (degr <= xtemp)
			{
				sampleValue = ytemp;   //returning value for set degree
				i++;
			}
		}
	}
	inputFileStream.close();
}

int Sample::checkTheFile(std::string inputFileName)
{
	cout << "--reading from " << inputFileName << " started--" << endl;
	ifstream infile(inputFileName);
	if (infile.is_open())
	{
		if (infile.good())
		{
			cout << "File " << inputFileName << " read successfully..." << endl;
			return 1;
		}
		else
		{
			cout << "Error in input file" << endl;
			return 0;
		}
	}
	else
	{
		cout << "Error opening input file, ";
		cout << "check if " << inputFileName << " exists in correct directory" << endl;
		infile.close();
		return 0;
	}

}

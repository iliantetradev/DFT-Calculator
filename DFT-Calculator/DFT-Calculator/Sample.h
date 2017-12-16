#include<string>
#include<iostream>
#include <fstream>

class Sample
{

private:

	//friend class Signal;

public:
	Sample();
	~Sample();

	double sampleValue;
	void getValueFromFile(std::string inputFileName, int degr); //reads the value at specified degree
	int checkTheFile(std::string inputFileName);
};
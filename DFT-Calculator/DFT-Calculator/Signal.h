#include<cmath>
#include<iostream>
#include<iomanip>
#include<string>
#include"Sample.h"
class Signal
{

private:
	double inputWave[361];
	double biasCosWave[8][361];
	double biasSinWave[8][361];
	double realProduct[361];
	double imagProduct[361];
	double realDFTCoeff[8];
	double imagDFTCoeff[8];
	const double pi = 3.14159265359;
	Sample example;

public:
	Signal();
	~Signal();


	void storeValue(Signal &waveValues, std::string fileName); //stores the values from getValue into array
	double getValuesForPrinting(int number, int option, int bin);//gets the values for printing the wave at console
																 //option 1 - input wave;2 - biasCosWave;3 - realProduct;4 - inputWave;5 - biasSinWave;6 - imagProduct
	void getDFTCoreCoeff();
	double returnDFTCoeff(int bin, std::string realOrImag);
	void checkFile(std::string &inputFileName);
};
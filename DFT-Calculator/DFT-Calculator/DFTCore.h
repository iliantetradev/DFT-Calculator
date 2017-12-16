#include"Signal.h"
#include<iomanip>
#include<iostream>
#include<string>

class DFTCore
{

private:
	double realDFTCoeff1;
	double imagDFTCoeff1;
	Signal signal1;
	std::string inputFileName1;

public:
	DFTCore();
	~DFTCore();

	void printDegScale(int prec);//prints the degrees to console
	void printWave(Signal &waveValues, int prec, int option, int bin);//prints the wave to th console
	void saveOutputToFile(Signal waveValues, std::string fileName, int prec, int option, int bin);
	void saveDegreeToFile(int prec, std::string fileName);
	void plotSelectedBin(DFTCore &dftObject);
	void storeDataFromFile();
	void name();
	void greet();
};
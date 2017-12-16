#include "Signal.h"


Signal::Signal()
{//stores sin and cos values with object creation
	for (int j = 0; j <= 7; j++)
		for (int i = 0; i <= 360; i++)
		{
			biasSinWave[j][i] = sin((i*pi * j) / 180);
			biasCosWave[j][i] = cos((i*pi * j) / 180);
		}
}

Signal::~Signal()
{
	example.~Sample();
}

void Signal::storeValue(Signal &waveValues, std::string fileName)
{
	for (int i = 0; i <= 360; i++)
	{
		example.getValueFromFile(fileName, i);
		waveValues.inputWave[i] = example.sampleValue;//store input wave data into array
	}
}

double Signal::getValuesForPrinting(int number, int option, int bin)
{
	switch (option)
	{
	case 1:
		return inputWave[number];

	case 2:
		if ((biasCosWave[bin][number] < 0.017452406437) && (biasCosWave[bin][number] > -0.017452406437))
		{
			biasCosWave[bin][number] = 0;
		}
		return biasCosWave[bin][number];

	case 3:
		if ((biasCosWave[bin][number] < 0.017452406437) && (biasCosWave[bin][number] > -0.017452406437))
		{
			biasCosWave[bin][number] = 0;
		}
		realProduct[number] = inputWave[number] * biasCosWave[bin][number];
		return realProduct[number];

	case 4:
		return inputWave[number];

	case 5:
		if ((biasSinWave[bin][number] < 0.017452406437) && (biasSinWave[bin][number] > -0.017452406437))
		{
			biasSinWave[bin][number] = 0;
		}
		return biasSinWave[bin][number];

	case 6:
		if ((biasSinWave[bin][number] < 0.017452406437) && (biasSinWave[bin][number] > -0.017452406437))
		{
			biasSinWave[bin][number] = 0;
		}
		imagProduct[number] = inputWave[number] * biasSinWave[bin][number];
		return imagProduct[number];

	default:
		return 0;
	}
}

void Signal::getDFTCoreCoeff()
{
	std::cout << "Calculation of DFT Coefficients (8 point DFT):" << std::endl;
	for (int j = 0; j <= 7; j++)
	{
		imagDFTCoeff[j] = 0;
		realDFTCoeff[j] = 0;
		for (int i = 0; i < 360; i++)
		{
			imagDFTCoeff[j] = imagDFTCoeff[j] + (inputWave[i] * biasSinWave[j][i]);
			realDFTCoeff[j] = realDFTCoeff[j] + (inputWave[i] * biasCosWave[j][i]);
		}
		std::cout << std::fixed << std::setprecision(3) << "The DFT[" << j << "] coefficients are : (" << realDFTCoeff[j] / 45 << ") - (" << imagDFTCoeff[j] / 45 << " i)" << std::endl;
	}
}

double Signal::returnDFTCoeff(int bin, std::string realOrImag)
{
	if (realOrImag == "real")
		return realDFTCoeff[bin] / 45;
	else if (realOrImag == "imag")
		return imagDFTCoeff[bin] / 45;
	else
		return 0;
}

void Signal::checkFile(std::string &inputFileName)
{
	//Checking if the file is there and if it is good
	std::cout << "Please enter the filename of the input wave to analyse:  ";
	std::cin >> inputFileName;
	while (example.checkTheFile(inputFileName) == 0)
	{
		std::cout << "Please enter the file name again:";
		std::cin >> inputFileName;
	}
	//end
}

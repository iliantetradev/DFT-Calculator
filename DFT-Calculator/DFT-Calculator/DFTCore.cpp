#include "DFTCore.h"

DFTCore::DFTCore()
{

}

DFTCore::~DFTCore()
{
	signal1.~Signal();

}

void DFTCore::printDegScale(int prec)
{
	std::cout << "      ";
	for (int i = 0; i <= prec; i++)
	{
		if ((i *(360 / prec)) / 100 == 0)
			std::cout << " ";
		else
			std::cout << (i *(360 / prec) / 100);
	}
	std::cout << std::endl << "      ";
	for (int i = 0; i <= prec; i++)
	{
		if (((i *(360 / prec)) % 100) / 10 == 0)
		{
			if (i * (360 / prec) < 100)
				std::cout << " ";
			else
				std::cout << 0 << "";
		}
		else
			std::cout << ((i * (360 / prec)) % 100) / 10 << "";
	}
	std::cout << std::endl << "      ";
	for (int i = 0; i <= prec; i++)
		std::cout << (i * (360 / prec)) % 10 << "";
	std::cout << std::endl;
	for (int i = 0; i <= 78; i++)
		std::cout << "=";
	std::cout << std::endl;
}

void DFTCore::printWave(Signal& waveValues, int prec, int option, int bin)
{
	int last = 0, line = 72;
	double step = 0.125, max = 1, min = -1;
	for (int i = 0; i <= 360; i++)
	{
		if (max < waveValues.getValuesForPrinting(i, 1, 1))
			max = waveValues.getValuesForPrinting(i, 1, 1);
		if (min > waveValues.getValuesForPrinting(i, 1, 1))
			min = waveValues.getValuesForPrinting(i, 1, 1);
	}
	step = max / 8;

	for (int c = 0; c <= prec; c++)
		if ((waveValues.getValuesForPrinting((c)*(360 / prec), option, bin) == 0))
		{
			line = 0;
		}

	for (int j = 9; j >= -9; j--)
	{
		std::cout << " ";
		if (j >= 0)
			std::cout << " ";
		std::cout << std::fixed << std::setprecision(2) << step*j;
		if (j == 0)
		{
			if ((waveValues.getValuesForPrinting(0, option, bin) != 0))
				std::cout << '-';
			for (int i = 0; i <= prec; i++)
			{
				if ((waveValues.getValuesForPrinting((i)*(360 / prec), option, bin) == 0))
				{
					std::cout << std::setfill('-');
					std::cout << std::setw(i - last) << '*';
					last = i;
					line = prec - last;
				}
			}
			if ((waveValues.getValuesForPrinting(360, option, bin) != 0))
			{
				std::cout << std::setfill('-');
				std::cout << std::setw(line) << '-';
			}
		}
		else if (j == 9)
		{
			if ((waveValues.getValuesForPrinting(0, option, bin) != max))
				std::cout << ' ';

			for (int i = 0; i <= prec; i++)
			{
				if ((waveValues.getValuesForPrinting((i)*(360 / prec), option, bin) == max))
				{
					std::cout << std::setfill(' ');
					std::cout << std::setw(i - last) << '*';
					last = i;
				}
			}
		}
		else if (j == -9)
		{
			if ((waveValues.getValuesForPrinting(0, option, bin) != min))
				std::cout << ' ';
			for (int i = 0; i <= prec; i++)
			{
				if ((waveValues.getValuesForPrinting((i)*(360 / prec), option, bin) == min))
				{
					std::cout << std::setfill(' ');
					std::cout << std::setw(i - last) << '*';
					last = i;
				}
			}
		}
		else if (j<0)
			for (int i = 1; i <= prec + 1; i++)
			{
				if ((waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) >= (j)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) < (j + 1)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != max) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != -max) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 0))
				{
					std::cout << std::setfill(' ');
					std::cout << std::setw(i - last) << '*';
					last = i;
				}
			}
		else
			for (int i = 1; i <= prec + 1; i++)
			{
				if ((waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) > (j - 1)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) < (j)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 1) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != -1) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 0))
				{
					std::cout << std::setfill(' ');
					std::cout << std::setw(i - last) << '*';
					last = i;
				}
			}
		last = 0;
		std::cout << std::endl;
	}
}

void DFTCore::saveOutputToFile(Signal waveValues, std::string fileName, int prec, int option, int bin)
{
	std::ofstream out_data(fileName, std::ios_base::app);
	int last = 0, line = 72;
	double step = 0.125;
	for (int c = 0; c <= prec; c++)
		if ((waveValues.getValuesForPrinting((c)*(360 / prec), option, bin) == 0))
		{
			line = 0;
		}
	for (int j = 9; j >= -9; j--)
	{
		out_data << " ";
		if (j >= 0)
			out_data << " ";
		out_data << std::fixed << std::setprecision(2) << step*j;
		if (j == 0)
		{
			if ((waveValues.getValuesForPrinting(0, option, bin) != 0))
				out_data << '-';
			for (int i = 0; i <= prec; i++)
			{
				if ((waveValues.getValuesForPrinting((i)*(360 / prec), option, bin) == 0))
				{
					out_data << std::setfill('-');
					out_data << std::setw(i - last) << '*';
					last = i;
					line = prec - last;
				}
			}
			if ((waveValues.getValuesForPrinting(360, option, bin) != 0))
			{
				out_data << std::setfill('-');
				out_data << std::setw(line) << '-';
			}
		}
		else if (j == 9)
		{
			if ((waveValues.getValuesForPrinting(0, option, bin) != 1))
				out_data << ' ';

			for (int i = 0; i <= prec; i++)
			{
				if ((waveValues.getValuesForPrinting((i)*(360 / prec), option, bin) == 1))
				{
					out_data << std::setfill(' ');
					out_data << std::setw(i - last) << '*';
					last = i;
				}
			}
		}
		else if (j == -9)
		{
			if ((waveValues.getValuesForPrinting(0, option, bin) != -1))
				out_data << ' ';
			for (int i = 0; i <= prec; i++)
			{
				if ((waveValues.getValuesForPrinting((i)*(360 / prec), option, bin) == -1))
				{
					out_data << std::setfill(' ');
					out_data << std::setw(i - last) << '*';
					last = i;
				}
			}
		}
		else if (j<0)
			for (int i = 1; i <= prec + 1; i++)
			{
				if ((waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) >= (j)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) < (j + 1)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 1) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != -1) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 0))
				{
					out_data << std::setfill(' ');
					out_data << std::setw(i - last) << '*';
					last = i;
				}
			}
		else
			for (int i = 1; i <= prec + 1; i++)
			{
				if ((waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) > (j - 1)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) < (j)*step) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 1) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != -1) && (waveValues.getValuesForPrinting((i - 1)*(360 / prec), option, bin) != 0))
				{
					out_data << std::setfill(' ');
					out_data << std::setw(i - last) << '*';
					last = i;
				}
			}
		last = 0;
		out_data << std::endl;
	}
}

void DFTCore::saveDegreeToFile(int prec, std::string fileName)
{
	std::ofstream out_data(fileName, std::ios_base::app);
	out_data << "      ";
	for (int i = 0; i <= prec; i++)
	{
		if ((i *(360 / prec)) / 100 == 0)
			out_data << " ";
		else
			out_data << (i *(360 / prec) / 100);
	}
	out_data << std::endl << "      ";
	for (int i = 0; i <= prec; i++)
	{
		if (((i *(360 / prec)) % 100) / 10 == 0)
		{
			if (i * (360 / prec) < 100)
				out_data << " ";
			else
				out_data << 0 << "";
		}
		else
			out_data << ((i * (360 / prec)) % 100) / 10 << "";
	}
	out_data << std::endl << "      ";
	for (int i = 0; i <= prec; i++)
		out_data << (i * (360 / prec)) % 10 << "";
	out_data << std::endl;
	for (int i = 0; i <= 78; i++)
		out_data << "=";
	out_data << std::endl;
}

void DFTCore::plotSelectedBin(DFTCore &dftObject)
{
	int stopper = 0, count = 0;
	std::string bin, save, outputFileName;
	char cBin;

	while (stopper == 0)
	{
		//Ploting the graphs for selected DFT bin
		std::cout << std::endl << "Please enter the DFT bin to plot between 0 to 7 or 'e' to end:  ";
		std::cin >> bin; //value for the bin user wants to be printed
						 //starts check if we have valid input
		if (bin.length() == 1)
		{
			cBin = bin[0];
			bin[0] = cBin;
			int a = bin[0];
			a = a - 48;
			if (((bin[0] == '0') || (bin[0] == '1') || (bin[0] == '2') || (bin[0] == '3') || (bin[0] == '4') || (bin[0] == '5') || (bin[0] == '6') || (bin[0] == '7')))
			{
				std::cout << std::endl << "DFT[" << a << "] plot: coefficients are : (" << signal1.returnDFTCoeff(a, "real") << ") - (" << signal1.returnDFTCoeff(a, "imag") << "i) :" << std::endl;
				for (int i = 1; i <= 6; i++)
				{
					switch (i)
					{
					case 1:
						std::cout << std::endl << "Input Wave Graph" << std::endl;
						break;
					case 2:
						std::cout << std::endl << "Cos Bias Graph" << std::endl;
						break;
					case 3:
						std::cout << std::endl << "Real Dot Product Graph" << std::endl;
						break;
					case 4:
						std::cout << std::endl << "Input Wave Graph" << std::endl;
						break;
					case 5:
						std::cout << std::endl << "Sin Bias Graph" << std::endl;
						break;
					case 6:
						std::cout << std::endl << "Imaginary Dot Product Graph" << std::endl;
						break;

					}

					dftObject.printDegScale(72); //prints the degrees
					dftObject.printWave(signal1, 72, i, a); //prints the waves
															// when i=1 it outputs Input Wave; 2 - Cosine Wave; 3 - Real Dot Product; 4 - Input File Wave; 
															//5 - Sine Wave; 6 - Imaginary Dot Product
				}
				//end check

				//asking if we want to save the output to file and saving it to the given file
				std::cout << std::endl << "Do you want to save the output to bin file?(Y/y) ";
				std::cin >> save;
				if ((save == "y") || (save == "Y"))
				{
					std::cout << std::endl << "Please enter file name for the output: ";
					std::cin >> outputFileName;
					for (int i = 1; i <= 6; i++)
					{
						dftObject.saveDegreeToFile(72, outputFileName);//same as above but it saves it to file instead of printing it
						dftObject.saveOutputToFile(signal1, outputFileName, 72, i, a);//same as above but it saves it to file instead of printing it
					}
					std::cout << "The DFT[" << bin << "] plot has been saved as " << outputFileName << std::endl;
				}
			}
			//end
			else if (cBin == 'e')
			{
				stopper = 1;
				break;
			}
			else
			{
				count++;
			}
		}

	}
}

void DFTCore::storeDataFromFile()
{
	signal1.checkFile(inputFileName1);
	signal1.storeValue(signal1, inputFileName1);
	signal1.getDFTCoreCoeff();
}

void DFTCore::name()
{
	std::cout << "Console application for calculating DFT Coefficients and ploting product waves." << std::endl << "Made by Ilian Tetradev SID:7219566 " << std::endl;
}

void DFTCore::greet()
{
	std::cout << "Thank you for using the DFT program... Goodbye!" << std::endl;
}

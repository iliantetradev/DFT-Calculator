#include<iostream>
#include"DFTCore.h"
using namespace std;

int main()
{
	DFTCore DFTobject;
	string save;
	int continueProgram = 0;
	DFTobject.name();
	do
	{
		DFTobject.storeDataFromFile();
		DFTobject.plotSelectedBin(DFTobject);

		cout << "Do you want to input another text file? (Y/y) ";
		cin >> save;
		if ((save == "y") || (save == "Y"))
		{
			DFTobject.~DFTCore();
		}
		else
			continueProgram = 1;
	} while (continueProgram == 0);
	DFTobject.greet();
	return 0;
}
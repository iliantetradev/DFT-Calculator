#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

class InputData
{

private:
	vector <vector <string> > data;
	vector <string> tempp;

public:
	InputData();
	~InputData();

	void readFile(string fileName);
	void outputData();
	void sortData();
};

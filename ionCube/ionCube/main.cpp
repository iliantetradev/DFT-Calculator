#include"InputData.h"
#include<iostream>
using namespace std;

int main()
{
	InputData InputObject;

	InputObject.readFile("orderdata");
	InputObject.sortData();
	InputObject.outputData();

	return 0;
}

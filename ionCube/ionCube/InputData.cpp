#include"InputData.h"

InputData::InputData()
{
}

InputData::~InputData()
{
}

void InputData::readFile(string fileName)
{
	vector<char> record;		//vector used to store the current input of a row
	vector<char> emailDomain;	//vector used to add 5th column for domain names
	int j = 0;
	ifstream input(fileName);	//open the file provided with function called
	//loop reading the file line by line and storing it in the line string
	for (std::string line; getline(input, line); )
	{
		line.erase(remove_if(line.begin(), line.end(), isspace), line.end()); //remove and erase any spaces in the string line
		//check if line is not a comment of empty line, continue only if an actual data line
		if (line[0] != '#'&& line[0] != '	'&& line[0] != ' ' && !line.empty())
		{
			//read each line char by char
			for (int i=0; i<line.length(); i++ )
			{
				//look for ':' , if not reached store each symbol in char vector
				if (line[i] != ':')
				{
					//check if it is the last symbol in the line
					if (i + 1 == line.length())
					{
						record.push_back(line[i]);
						string str(record.begin(), record.end());	//convert char vector into string
						tempp.push_back(str);		//save row item into the temporary vector for the rows
						//reset counter and vector
						j++;
						record.clear();
					}
					//find and store the domain name in emainDomain vector
					if (line[i] == '@')
					{
						int t = i+1;
						while (line[t] != ':')
						{
							emailDomain.push_back(line[t]);
							t++;
						}
					}
					record.push_back(line[i]);	//save each char into the vector while ':' not reached
				}
				else		//if ':' reached push back the row item
				{
					string str(record.begin(), record.end());	//convert char vector into string
					tempp.push_back(str);		//save row item into the temporary vector for the rows
					//reset counter and vector
					j++;
					record.clear();
				}
			}
			//when the line is read and sorted save it in the data vector
			string str1(emailDomain.begin(), emailDomain.end());
			tempp.push_back(str1);
			data.push_back(tempp);
			//reset counter and vectors for storing information
			j = 0;
			tempp.clear();
			record.clear();
			emailDomain.clear();
		}
	}
}

void InputData::outputData()
{
	string temp;		//variable for storing the domain name
	temp = data[0][4];	//store the first domain name
	//print message indication which domain the following orders come from
	std::cout << "Orders from " << temp << " :" << endl;
	std::cout << "========================================" << endl;

	for (std::vector<std::vector<string>>::size_type i = 0; i < data.size(); i++)
	{
		if (temp != data[i][4])		//check if the domain is still the same as previous entry
		{
			//if not store the new domain and print according message 
			temp = data[i][4];
			std::cout << endl << "Orders from " << temp << " :" << endl;
			std::cout << "========================================" << endl;
		}
		for (std::vector<string>::size_type j = 1; j < data[i].size()-1; j++)
		{
			std::cout << data[i][j] << '\t';	//output the data
			//format the output roughly(long emails not formatted properly)
			if (data[i][j].length() < 16 && j<2)
				std::cout << '\t';
		}
		std::cout << endl;
	}
}

void InputData::sortData()
{
	//sort the 2D vector alphabetically by email domain
	sort(data.begin(), data.end(),
		[](const vector<string> &a, const vector<string> &b)
			{
				return a[4] < b[4];
			}
		);

	unsigned int p = 0,q=0;	//counters for storing the beginning and ending of each domain group
	for (std::vector<std::vector<string>>::size_type i = 1; i < data.size(); i++)
	{
		{
			if (data[i][4] == data[i - 1][4] && i <data.size()-1)
				p++;	//increment p for each twin domain
			else
			{
				if (!(i < data.size() - 1))	//account for the last item of the list
					p++;
				//sort alphabetically by the email column starting from the beginning of one domain till its end
				sort(data.begin() + q, data.begin() +(q + p+1),
					[](const vector<string> &a, const vector<string> &b)
				{
					return a[1] < b[1];		//0 - sort by order number, 1 - sort by email, 3 - sort by number of orders, 4 - sort by total value
				}
				);
				//store new value for q(the next element from the last sorted element) and reset p
				q = q+p+1;
				p = 0;
			}
		}
	}
}


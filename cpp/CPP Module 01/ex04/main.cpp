#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using std::string;
using std::cout;
using std::endl;
using std::find;

string rewriteString(string s1, string s2, string inFileLine)
{
	string	returnString;
	size_t	foundPos = 0;
	size_t	startWritePos = 0;

	foundPos = inFileLine.find(s1, 0); //find str to be replaced (s1)
	while(foundPos != string::npos) //while not end of string
	{
		returnString.append(inFileLine.substr(startWritePos, (foundPos - startWritePos))); //append all char until s1
		returnString.append(s2); //append new str (s2) instead of s1
		startWritePos = foundPos + s1.length(); //position adjusted
		foundPos = inFileLine.find(s1, (foundPos + 1)); //continue finding s1
	}
	returnString.append(inFileLine.substr(startWritePos, inFileLine.length())); //append remainder char in line of which theres no s1 left
	return (returnString);
}

int main(int argc, char **argv)
{
	if (argc != 4) //command example: ./main test.txt yu YU
	{
		cout << "Usage: ./main <filename> <string to replace> <string to replace with>" << endl;
		return (0);
	}

	std::ifstream	inFile;
	std::ofstream	outFile;
	string			outFileName = argv[1];
	string 			s1 = argv[2];
	string 			s2 = argv[3];
	string			inFileLine;

	inFile.open(argv[1]); //open file from input
	if (!inFile.is_open())
	{
		cout << "Unable to open file" << endl;
		return (-1);
	}

	outFileName.append(".replace"); // create name for output file
	outFile.open(outFileName.c_str()); //open output file

	while (1)
	{
		getline(inFile, inFileLine); //store line in inFileLine
		outFile << rewriteString(s1, s2, inFileLine);
		if (inFile.eof())
			break ;
		outFile << "\n";
	}

	inFile.close();
	outFile.close(); //close both files

	return (0);
}

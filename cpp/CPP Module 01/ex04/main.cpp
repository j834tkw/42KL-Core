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
	
	foundPos = inFileLine.find(s1, 0);
	while(foundPos != string::npos)
	{
		returnString.append(inFileLine.substr(startWritePos, (foundPos - startWritePos)));
		returnString.append(s2);
		startWritePos = foundPos + s1.length();
		foundPos = inFileLine.find(s1, (foundPos + 1));
	}
	returnString.append(inFileLine.substr(startWritePos, inFileLine.length()));
	return (returnString);
}

int main(int argc, char **argv)
{
	if (argc != 4)
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

	inFile.open(argv[1]);
	if (!inFile.is_open())
	{
		cout << "Unable to open file" << endl;
		return (-1);
	}

	outFileName.append(".replace");
	outFile.open(outFileName.c_str());

	while (1)
	{
		getline(inFile, inFileLine);
		outFile << rewriteString(s1, s2, inFileLine);
		if (inFile.eof())
			break ;
		outFile << "\n";
	}

	inFile.close();
	outFile.close();

	return (0);
}

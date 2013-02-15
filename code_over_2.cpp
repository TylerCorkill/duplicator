#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	string lineStr;
	fstream source, newSrc;
	newSrc.open("code_over.cpp");
	source.open("code_over_2.cpp");
	// Count ====== 1
	for (int line = 0; line < 77; ++line)
	{
		if (line == 11)
		{
			getline(source, lineStr);
			if (lineStr == "\tnewSrc.open(\"code_over.cpp\");")
			{
				newSrc << "\tnewSrc.open(\"code_over_2.cpp\");\n";
			}
			else
			{
				newSrc << "\tnewSrc.open(\"code_over.cpp\");\n";
			}
			lineStr = "";
		}
		else if (line == 12)
		{
			getline(source, lineStr);
			if (lineStr == "\tsource.open(\"code_over.cpp\");")
			{
				newSrc << "\tsource.open(\"code_over_2.cpp\");\n";
			}
			else
			{
				newSrc << "\tsource.open(\"code_over.cpp\");\n";
			}
			lineStr = "";
		}
		else if (line == 13)
		{
			int count;
			int location = source.tellg();
			source.seekg(location + 17);
			getline(source, lineStr);
			stringstream lineSS(lineStr);
			lineSS >> count;
			newSrc << "\t// Count ====== " << (count + 1) << "\n";
		}
		else if (line == 74)
		{
			getline(source, lineStr);
			if (lineStr == "\tsystem(\"g++ code_over.cpp -o main\");")
			{
				newSrc << "\tsystem(\"g++ code_over_2.cpp -o main\");\n";
			}
			else
			{
				newSrc << "\tsystem(\"g++ code_over.cpp -o main\");\n";
			}
			lineStr = "";
		}
		else
		{
			getline(source, lineStr);
			newSrc << lineStr << "\n";
			lineStr = "";
		}
	}
	newSrc.close();
	source.close();
	system("g++ code_over.cpp -o main");
	return 0;
}

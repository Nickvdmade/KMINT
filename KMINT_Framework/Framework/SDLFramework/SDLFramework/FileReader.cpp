#include "FileReader.h"
#include <fstream>
#include <iostream>

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

std::vector<std::string> FileReader::readFile(const std::string fileName) const
{
	std::ifstream file(fileName);
	std::vector<std::string> result;
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			result.push_back(line);
		}
		file.close();
	}
	return result;
}

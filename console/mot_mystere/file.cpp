#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>

#include <algorithm>
 
static void displayFileContent(std::ifstream& fileStream)
{
	std::string lineString{};
	while(fileStream.good())
	{
		std::getline(fileStream, lineString);
		std::cout << lineString << std::endl;
	}
}
std::size_t getFileLineTotal(std::ifstream& fileStream)
{
	std::string lineString{};
	std::size_t i {};
	while(fileStream.good())
	{
		std::getline(fileStream, lineString);
		i++;
 	}
 	return i;
} 

static std::string getFileLine(std::ifstream& fileStream, const std::size_t line)
{
	std::string lineString{};
	std::size_t i{};
 	while(fileStream.good())
	{
		std::getline(fileStream, lineString);
		if(i == line)
			return lineString;


		i++;
 	}

	return std::string{};
}

std::string generateWord(std::string fileName)
{
 	std::ifstream dictionary {fileName};
 	std::size_t max{getFileLineTotal(dictionary)-1};

 
  	dictionary.clear();
  	dictionary.seekg(0, std::ios::beg);

 	static auto const seed = std::time(nullptr);
 	static std::default_random_engine gnd{seed};
 	static std::uniform_int_distribution<std::size_t> dis{1, max};

 	return getFileLine(dictionary, dis(gnd));
}
std::string reverseWord(const std::string& word)
{
	std::string transformString{word};
  
 	std::reverse(transformString.begin(), transformString.end());

	return transformString;
}

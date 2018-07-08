#include <iostream>
#include <string>

bool gameReverse(const std::string& wordReversed, const std::string& wordHiden, bool gameOver)
{
    std::string proposition{};

	for(std::size_t i{}; i < 5 && !gameOver; i++)
	{
		std::cout << "[+] What is this word : " << wordReversed << std::endl;
		std::cout << "[+] Try " << i + 1 << " > ";
	    std::getline(std::cin, proposition);

		if(proposition == wordHiden)
	    {
			gameOver = true;
	        std::cout << std::endl;
			std::cout << "=============" << std::endl;
			std::cout << "[+] You Win !" << std::endl;
			std::cout << "=============" << std::endl;
	        std::cout << std::endl;
	    } 
	}
	return false;
}
bool gameHidden(const std::string& word, bool gameOver)
{
	std::string wordStar{};
	std::string proposition{};
	std::size_t index{};

	const int max {20}; 

	for(std::size_t i{}; i < word.length(); i++)
	{
		wordStar += "*";
	}

	for(std::size_t i{}; i < max && !gameOver; i++)
	{
		std::cout << wordStar << std::endl;
		std::cout << word << std::endl;
		std::cout << "[+] Try " << max - i << " What is the word : ";
		std::getline(std::cin, proposition);

		for(char c:word)
		{
			if(c == proposition.at(0))
			{
				wordStar.at(index) = proposition.at(0);
			}
			index++;
		}
		index = 0;

		for(char c:wordStar)
		{
			if(c == '*')
				index ++;
		}	
		index = 0;

		if(wordStar == word)
		{
			gameOver = true;

			std::cout << std::endl;
			std::cout << "=============" << std::endl;
			std::cout << "[+] You Win !" << std::endl;
			std::cout << "=============" << std::endl;
	        std::cout << std::endl;
		}


	}
	return false;
}

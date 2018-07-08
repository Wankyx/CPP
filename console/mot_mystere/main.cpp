#include <iostream>
#include <exception>
#include <string>

#include "game.hpp"
#include "menu.hpp"
#include "file.hpp"

int main()
{
    std::string data{};
    std::string wordHiden{};
    std::string wordReversed{};
 
    bool gameOver{false};
    while(!getConsoleState())
    {
        displayMainMenu();
        data = userInput("[+] Selection >> ");

        switch(stringToInteger(data))
        {
        case 1:
        	displayMethodMenu();

        	data = userInput("[+] Selection >> ");

        	switch(stringToInteger(data))
        	{
        	case 1:
        		wordHiden = generateWord("dictionary.txt");
	        	wordReversed = reverseWord(wordHiden);
	        	 
	        	gameOver = gameReverse(wordReversed, wordHiden, gameOver);
        		break;
        	case 2:
        		wordHiden = generateWord("dictionary.txt");
  				gameHidden(wordHiden, gameOver);
        		gameOver = false;
        		break;
        	}
            break;
        case 2:
            displayRulesMenu();
            break;
        case 3:
        	displayAboutMenu();
            break;
        case 4:
            setConsoleState(true);
            break;
        default:
             throw std::runtime_error("[!] Error : Uknow Choice");
             break;
        }
     }

    return  0;
}

#include <iostream>
#include <string>
#include <exception>
static bool quit = false;

void displayMainMenu()
{
    std::cout << "===========================================" << std::endl;
    std::cout << "=    C++ - Semaine 1 - Mot mystère plus   =" << std::endl;
    std::cout << "===========================================" << std::endl;

    std::cout << "[+] MAIN MENU SELECTION" << std::endl;
    std::cout << "\t\t 1 . New Game" << std::endl;
    std::cout << "\t\t 2 . Rules" << std::endl;
    std::cout << "\t\t 3 . About" << std::endl;
    std::cout << "\t\t 4 . Quit" << std::endl;
}
void displayRulesMenu()
{
    std::cout << std::endl;
    std::cout << "[+] RULES MENU" << std::endl;
    std::cout << "I will take in dictionary a word ." << std::endl;
    std::cout << "Your mission is to find this word with less try possible !" << std::endl;
    std::cout << std::endl;
}
void displayAboutMenu()
{
    std::cout << std::endl;
    std::cout << "[+] ABOUT MENU" << std::endl;
    std::cout << "Name : Wankyx" << std::endl;
    std::cout << "GitHub : https://github.com/Wankyx" << std::endl;
    std::cout << "YouTube : Wankyx Programming" << std::endl;
    std::cout << "Language : C++" << std::endl;
}
void displayMethodMenu()
{
    std::cout << std::endl;
    std::cout << "[+] METHOD MENU" << std::endl;
    std::cout << "1 . reverse word" << std::endl;
    std::cout << "2 . hiden word" << std::endl;
    std::cout << std::endl;
}



int stringToInteger(const std::string stringData)
{
    int data{};
    try
    {
        data = std::stoi(stringData);
    }
    catch(const std::exception& error)
    {
        std::cerr << __FILE__ << ":" << __LINE__ << " > " << error.what() << std::endl;
    }
    return data;
}
std::string& userInput(const std::string msg)
{
    static std::string data{};

    std::cout << msg;
    std::getline(std::cin, data);
    return data;
}
bool getConsoleState()
{
    return quit;
}
void setConsoleState(const bool state)
{
    quit = state;
}

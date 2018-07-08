#ifndef MENU_HPP
#define MENU_HPP

extern bool quit;


extern void displayMainMenu();
extern void displayRulesMenu();
extern void displayAboutMenu();
extern void displayMethodMenu();

extern std::string& userInput(const std::string msg);
extern int stringToInteger(const std::string stringData);
extern bool getConsoleState();
extern void setConsoleState(const bool state);


#endif // MENU_HPP

 
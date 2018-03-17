#ifndef __PROCESS__HPP__ 
#define __PROCESS__HPP__ 

#include <Windows.h>

class Process
{
public:
	// Constructeur 
	Process();
	Process(std::string windowName);

	// Destructeur 
	~Process();


	static bool error;

	// Encapsulasion 
	// Getteur 
	std::string getWindowTitle();
	std::string getProcessName();

	HWND getWindowHandle();
	DWORD getProcessId();
	HANDLE getProcessHandle();

	// Setteur 
	void setWindowTitle(std::string title);
	void setProcessName(std::string pName);

	void setWindowHandle(HWND hWindow);
	void setProcessId(DWORD processId);
	void setProcessHandle(HANDLE processHandle);
	void setModuleHandle(DWORD module);


	// Outils 
	void shownProcessInfo();
	DWORD attachModule(std::string moduleName); // Permet de recuperer l'addresse de certain module (via handle)
	void processRPM(DWORD address, DWORD* data);
	void processWPM(DWORD address, DWORD* data);


private:
	std::string windowTitle; // Titre de la fenetre 
	std::string processName; // Nom du processus 


	HWND hWnd; // Handle de la fenetre l'handle nous permetra de manipuler la fenêtre c'est l'outils de windows qui permet cela 
	DWORD pId; // l'id du processus créer cet a dire de la fenêtre une fois executer par le système d'exploitation 
	HANDLE pHandle; // L'Handle du processus qui nous permetra de manipuler le processus en lecture et écriture


};

#endif 
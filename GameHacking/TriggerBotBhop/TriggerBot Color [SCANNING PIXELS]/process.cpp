// Bibliothèque standard
#include <iostream> // Bibliothèque standard pour l'utilisation des flux d'entrée, sortie qu'offre la bibliothèque standard
#include <string> // Manipulation chaine de caractere de classe std::string
#include <list> // Manipulation de tableau liste doublement chainée  
#include <cstdlib> // Bibliothèque standard pour l'utilisation de fonction utilitaire en C++

// API 
#include <Windows.h> // API windows pour pouvoir faire de la programmation systeme sur windows 
#include <psapi.h>
#include <tchar.h>
#include <TlHelp32.h>
// Bibliothèque statique personnelle 
#include "process.hpp" // inclus ma class au moment du preprocesseur lors de la compilation 

/*********************************************************/

bool Process::error = false;

/* CONSTRUCTEUR */
Process::Process()
{
	/*
	std::string windowTitle;
	std::string processName;

	HWND windowHandle = nullptr;
	DWORD processId = 0;

	HANDLE hProcess = nullptr;


	TCHAR pName[256] = TEXT("?");

	HMODULE moduleHandle = nullptr;
	DWORD cbNeeded;

	std::cout << "[Process] Window title >> ";
	std::getline(std::cin, windowTitle);


	if ((windowHandle = FindWindow(nullptr, (LPCTSTR)(windowTitle.c_str()))) == nullptr) // Regarde si la fenetre est ouverte
	{
	std::cout << "[Process] Please run " << windowTitle << std::endl;
	error = true;
	}
	GetWindowThreadProcessId(windowHandle, &processId);

	if ((hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, processId)) == nullptr)
	{
	std::cout << "[Process] can't OpenProcess will all access" << std::endl;
	error = true;
	}
	else
	{
	EnumProcessModules(hProcess, &moduleHandle, sizeof(moduleHandle), &cbNeeded);
	GetModuleBaseName(hProcess, moduleHandle, pName, sizeof(pName) / sizeof(TCHAR));

	this->setProcessName(pName);
	this->setWindowTitle(windowTitle);
	this->setProcessId(processId);
	this->setWindowHandle(windowHandle);
	this->setProcessHandle(hProcess);
	}
	*/
}
Process::Process(std::string windowName)
{
	std::string windowTitle = windowName; // Titre de ma fenetre 
	std::string processName; // Nom du processus 

	HWND windowHandle = nullptr; // Handle de la fenetre 
	DWORD processId = 0; // id du processus 

	HANDLE hProcess = nullptr; // handle du processus pour ecrire et lire 


	TCHAR pName[256] = TEXT("?"); // nom du processus tableau a la C 

	HMODULE moduleHandle = nullptr; // handle d'un module 
	DWORD cbNeeded; // nombre de d'octet nécéssaire pour stocker le module 

	if ((windowHandle = FindWindow(nullptr, (LPCTSTR)(windowTitle.c_str()))) == nullptr) // Regarde si la fenetre est ouverte
	{
		std::cout << "[Process] Please run " << windowTitle << std::endl;
		error = true;
	}
	GetWindowThreadProcessId(windowHandle, &processId);

	if ((hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, processId)) == nullptr)
	{
		std::cout << "[Process] can't OpenProcess will all access" << std::endl;
		error = true;
	}
	else
	{
		EnumProcessModules(hProcess, &moduleHandle, sizeof(moduleHandle), &cbNeeded); // recuperere un handle de module en fonction du handle du processus 
		GetModuleBaseName(hProcess, moduleHandle, pName, sizeof(pName) / sizeof(TCHAR)); // Recupere le nom en fonction du handle process et module 

																						 // Stocker les données dans la class process
		this->setProcessName(pName);
		this->setWindowTitle(windowTitle);
		this->setProcessId(processId);
		this->setWindowHandle(windowHandle);
		this->setProcessHandle(hProcess);
	}

}
/*********************************************************/
/* DESTRUCTEUR */
Process::~Process()
{
	CloseHandle(this->pHandle);
	std::cout << "[PROCESS] process handle was closed ." << std::endl;
}

/*********************************************************/

/* Encapsulasion : Getteur */
std::string Process::getWindowTitle()
{
	return this->windowTitle;
}
std::string Process::getProcessName()
{
	return this->processName;
}

HWND Process::getWindowHandle()
{
	return this->hWnd;
}
DWORD Process::getProcessId()
{
	return this->pId;
}
HANDLE Process::getProcessHandle()
{
	return this->pHandle;
}
/* Encapsulasion : Setteur */
void Process::setWindowTitle(std::string title)
{
	this->windowTitle = title;
}
void Process::setProcessName(std::string pName)
{
	this->processName = pName;
}

void Process::setWindowHandle(HWND hWindow)
{
	this->hWnd = hWindow;
}
void Process::setProcessId(DWORD processId)
{
	this->pId = processId;
}
void Process::setProcessHandle(HANDLE processHandle)
{
	this->pHandle = processHandle;
}
/*****************************************************/

/* Fonction: Outils */
void Process::shownProcessInfo()
{
	std::cout << "\t\t[PROCESS INFO]" << std::endl;

	std::cout << "[+] Window Title   : " << this->getWindowTitle() << std::endl;
	std::cout << "[+] Process Name   : " << this->getProcessName() << std::endl;
	std::cout << "[+] Window Handle  : " << std::hex << this->getWindowHandle() << std::endl;
	std::cout << "[+] Process Handle : " << std::hex << this->getProcessHandle() << std::endl;
	std::cout << "[+] Process Id     : " << std::dec << this->getProcessId() << std::endl;
}

DWORD Process::attachModule(std::string moduleName)
{
	DWORD pId = this->getProcessId(); // id du processus
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pId); //Prend un instantané des processus spécifiés, ainsi que des tas, modules et threads utilisés par ces processus.
	MODULEENTRY32 mEntry; // Liste d'entrée de module appartenant au processus
	mEntry.dwSize = sizeof(mEntry); // La taille de la structure sizeof

	do
	{
		if (!lstrcmp(mEntry.szModule, moduleName.c_str()))
		{
			CloseHandle(hModule); // Ferme l'handle du module 
			return (DWORD)mEntry.modBaseAddr; // recupere l'addresse du module
		}
	} while (Module32Next(hModule, &mEntry)); // recupere info du module

	std::cout << "[PROCESS] Can't attached the module" << std::endl;
}

void Process::processRPM(DWORD address, DWORD* data)
{
	ReadProcessMemory(this->getProcessHandle(), (LPCVOID)address, (LPVOID)data, sizeof(*data), nullptr);
}
void Process::processWPM(DWORD address, DWORD* data)
{
	WriteProcessMemory(this->getProcessHandle(), (LPVOID)address, (LPCVOID)data, sizeof(*data), nullptr);

}
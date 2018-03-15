#include <iostream>
#include <cstdlib>
#include <string>

#include <Windows.h>
#include <psapi.h>
#include <tchar.h>
#include "process.hpp"

bool Process::error = false;

Process::Process()
{
	HWND windowHandle = nullptr;
	HANDLE processHandle = nullptr;
	DWORD processId = 0;

	std::string windowName{};
	
	std::cout << "[+] Please write the window name : ";
	std::getline(std::cin, windowName);

	windowHandle = FindWindow(nullptr, windowName.c_str());

	if (windowHandle == nullptr)
	{
		std::cout << "[!] Please run \"" << windowName << "\"." << std::endl;
		this->setError(true);
	}
	else
	{
		GetWindowThreadProcessId(windowHandle, &processId);
		processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
		 
		if (processHandle == nullptr)
		{
 			std::cout << "[!] Can't get access in this process ." << std::endl;
			this->setError(true);
		}
		else
		{
			TCHAR processName[256] = TEXT("?");

			HMODULE moduleHandle = nullptr;
			DWORD cbNeeded;
			EnumProcessModules(processHandle, &moduleHandle, sizeof(moduleHandle), &cbNeeded);
			GetModuleBaseName(processHandle, moduleHandle, processName, sizeof(processName) / sizeof(TCHAR));

			this->setProcessName(processName);
			this->setWindowName(windowName);
 			this->setProcessHandle(processHandle);
			this->setWindowHandle(windowHandle);
			this->setProcessId(processId);
		}
	}

 }

Process::Process(std::string windowName)
{
	HWND windowHandle = nullptr;
	HANDLE processHandle = nullptr;
	DWORD processId = 0;

	windowHandle = FindWindow(nullptr, windowName.c_str());

	if (windowHandle == nullptr)
	{
		std::cout << "[!] Please run \"" << windowName << "\"." << std::endl;
		this->setError(true);
	}
	else
	{
		GetWindowThreadProcessId(windowHandle, &processId);
		processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

		if (processHandle == nullptr)
		{
			std::cout << "[!] Can't get access in this process ." << std::endl;
			this->setError(true);
		}
		else
		{
			TCHAR processName[256] = TEXT("<unknow>");

			HMODULE moduleHandle = nullptr;
			DWORD cbNeeded;
			EnumProcessModules(processHandle, &moduleHandle, sizeof(moduleHandle), &cbNeeded);
			GetModuleBaseName(processHandle, moduleHandle, processName, sizeof(processName) / sizeof(TCHAR));

			this->setProcessName(processName);
			this->setWindowName(windowName);
			this->setProcessHandle(processHandle);
			this->setWindowHandle(windowHandle);
			this->setProcessId(processId);
		}
	}
}


Process::~Process()
{
	std::cout << "[+] Process " << this->processName << " was closed ." << std::endl;
	std::cout << "[+] Press enter to quit ..." << std::endl;

	CloseHandle(this->processHandle);
	
	std::cin.get();
}

void Process::setWindowName(std::string windowName)
{
	this->windowName = windowName;
}
std::string Process::getWindowName()
{
	return this->windowName;
}
void Process::setProcessName(std::string processName)
{
	this->processName = processName;
}
std::string Process::getProcessName()
{
	return this->processName;
}
void Process::setError(bool error)
{
	this->error = error;
}
bool Process::getError()
{
	return this->error;
}

void Process::setWindowHandle(void* ptrHandle)
{
	this->windowHandle = ptrHandle;
}
void* Process::getWindowHandle()
{
	return this->windowHandle;
}

void Process::setProcessHandle(void* ptrHandle)
{
	this->processHandle = ptrHandle;
}
void* Process::getProcessHandle()
{
	return this->processHandle;
}

void Process::setProcessId(unsigned long pId)
{
	this->processId = pId;
}
unsigned long Process::getProcessId()
{
	return this->processId;
}

void Process::processInfo()
{
	std::cout << "******************************" << std::endl;
	std::cout << "* Game : " << this->getWindowName() << std::endl;
	std::cout << "* Process name : " << this->getProcessName() << std::endl;
	std::cout << "* Process Id :" << this->getProcessId() << std::endl;
	std::cout << "* Window Handle : " << this->getWindowHandle() << std::endl;
	std::cout << "* Process Handle : " << this->getProcessHandle() << std::endl;
	std::cout << "******************************" << std::endl;

}

void Process::processRPM(unsigned long* data, unsigned long address)
{

	ReadProcessMemory(this->getProcessHandle(), (LPVOID)address, data, sizeof(DWORD), nullptr);
}
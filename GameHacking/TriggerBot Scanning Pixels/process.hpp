#ifndef __PROCESS__HPP__
 
class Process
{
public:
	Process();
	Process(std::string windowName);
	~Process();

	void setWindowName(std::string windowName);
	std::string getWindowName();

	void setProcessName(std::string processName);
	std::string getProcessName();

	void setError(bool error);
	bool getError();

	void setWindowHandle(void* ptrHandle);
	void* getWindowHandle();

	void setProcessHandle(void* ptrHandle);
	void* getProcessHandle();

	void setProcessId(unsigned long pId);
	unsigned long getProcessId();


	void processInfo();
	
	void processRPM(unsigned long* data, unsigned long address);

private:
	std::string windowName;
	std::string processName;
	static bool error;
	void* windowHandle;
	void* processHandle;
	unsigned long processId;
	
};

#endif
#include <iostream>
#include <cstdlib>

#include "process.hpp"

int main()
{
	Process process{"Counter-Strike Source"};
	unsigned long r_drawo = 0;

	process.processInfo();

	process.processRPM(&r_drawo, 0x210F29C0);

	std::cout << r_drawo << std::endl ;
	

	if (process.getError())
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
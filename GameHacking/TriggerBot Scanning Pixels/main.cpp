#include <iostream>
#include <cstdlib>

#include "process.hpp"
#include "scan.hpp"

int main()
{
	Process process{ "Counter-Strike Source" };
	Scanner sc;

	if (process.getError())
	{
		return EXIT_FAILURE;
	}
	process.processInfo();
	sc.scan();
	return EXIT_SUCCESS;
}
#include <iostream>

#include "random.h"

int main()
{
	std::cout << "rnd: " << example::random().get() << std::endl;
	return 0;
}

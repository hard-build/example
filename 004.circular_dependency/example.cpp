#include <iostream>

#include "container/container.h"

int main()
{
	container c;
	c.push(100);
	c.push(200);
	c.push(300);
	std::cout << c.dump() << std::endl;
	return 0;
}

#include "object.h"

#include <iostream>

using namespace example;

object::object(const char* name) :
        name_(name)
{
}

object::~object()
{
}

void object::greeting()
{
	std::cout << "Hello, " << name_ << "!" << std::endl;
}

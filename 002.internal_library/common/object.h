#pragma once

#include <string>

namespace example
{

class object
{
public:
	object(const char* name);
	virtual ~object();

	void greeting();

protected:
	std::string name_;
};

}

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../component/component.h"

class container
{
public:
	container();

	void push(int value);
	std::string dump();

protected:
	std::vector<std::shared_ptr<component>> components_;
};

#pragma once

#include <memory>
#include <vector>

#include "../container/container.h"

class component
{
public:
	component(int value);

	int value() const;

protected:
	int value_;
	std::shared_ptr<container> container_;
};

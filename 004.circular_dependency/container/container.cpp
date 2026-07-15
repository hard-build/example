#include "container.h"

container::container()
{
}

void container::push(int value)
{
	components_.push_back(std::make_shared<component>(value));
}

std::string container::dump()
{
	std::string result = "[";
	for (size_t i = 0; i < components_.size(); ++i)
	{
		if (i != 0)
		{
			result += ", ";
		}
		result += std::to_string(components_[i]->value());
	}
	result += "]";
	return result;
}

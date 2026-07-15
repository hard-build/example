#include "component.h"

component::component(int value) :
        value_(value)
{
}

int component::value() const
{
	return value_;
}

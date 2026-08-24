#include "yaml_cpp.hard.h"

#include <iostream>

int main()
{
	const YAML::Node document = YAML::Load("answer: 42");
	std::cout << "answer=" << document["answer"].as<int>() << '\n';
	return 0;
}

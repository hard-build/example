#include <filesystem>
#include <fstream>
#include <iostream>

#include <github.com/nlohmann/json/single_include/nlohmann/json.hpp>

int main(int argc, char** argv)
{
	std::filesystem::path path;
	if (argc == 2)
	{
		path = argv[1];
	}
	else
	{
		std::cerr << "usage: " << argv[0] << " <path/to/json>" << std::endl;
		return 1;
	}

	nlohmann::json json;
	try
	{
		std::ifstream file_stream(path, std::ios::in | std::ios::binary);
		json = nlohmann::json::parse(file_stream);
	}
	catch (const std::exception& exception)
	{
		std::cerr << "error: " << exception.what() << std::endl;
		return 1;
	}

	std::cout << json.dump(4) << std::endl;
	return 0;
}

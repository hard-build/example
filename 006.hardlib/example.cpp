#include <iostream>

#include <hard/application/application.h>

class example_module : public hard::module
{
protected:
	void on_init() override
	{
		std::cout << "on_init" << std::endl;
	}

	void on_tick() override
	{
		++ticks_;
		std::cout << "on_tick " << ticks_ << std::endl;

		if (ticks_ == 3)
		{
			application_->broadcast("example.complete", "three ticks completed");
			application_->stop();
		}
	}

	void on_broadcast(const std::string& key, const hard::variable& value) override
	{
		std::cout << "on_broadcast " << key << " = " << value << std::endl;
	}

private:
	int ticks_ = 0;
};

int main()
{
	hard::application application;

	try
	{
		application.emplace_module<example_module>();
		application.init();
	}
	catch (const std::exception& exception)
	{
		std::cerr << "error: " << exception.what() << std::endl;
		return 1;
	}

	application.start();
	return 0;
}

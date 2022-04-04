#include <iostream>

#include <cargs.h>

static struct cag_option options[] = {
    {.identifier = 'h',
     .access_letters = "h",
     .access_name = "help",
     .value_name = NULL,
     .description = "Display the command line help"}};

void showHelp()
{
	std::cout << "Usage: cpptemplate_app [OPTIONS] ..." << std::endl;
	std::cout << "Base template to build a C++ library or app with integrated unit tests and documentation."
	          << std::endl;
	cag_option_print(options, CAG_ARRAY_SIZE(options), stdout);
}

struct program_config
{
	bool showHelp = false;
};

int main(int argc, char** argv)
{
	cag_option_context context;
	cag_option_prepare(&context, options, CAG_ARRAY_SIZE(options), argc, argv);

	program_config config;

	while (cag_option_fetch(&context))
	{
		const char identifier = cag_option_get(&context);
		switch (identifier)
		{
		case 'h':
			config.showHelp = true;
			break;

		default:
			break;
		}
	}

	if (config.showHelp)
	{
		showHelp();
		return 0;
	}

	return 0;
}

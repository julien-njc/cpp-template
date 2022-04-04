#include <cassert>
#include <string>

#define build_error_message(message, format, function, ...)                                                            \
	static_assert(sizeof(message) == 128, "message has to be a 128 characters buffer");                                \
	int written = sprintf(message, format, function, __VA_ARGS__);                                                     \
	if (written < 0)                                                                                                   \
	{                                                                                                                  \
		sprintf(message, "%s failed (original error message too long)", function);                                     \
	}                                                                                                                  \
	report_error(message)

void report_error(const char* error);

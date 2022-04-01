#include "error.h"

#include <stdio.h>

void report_error(const char* error)
{
	perror(error);
}

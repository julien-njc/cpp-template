#include "utilities/memory.hpp"
#include "error.hpp"

#include <cstddef>

void* safe_malloc(size_t size)
{
	void* allocated = malloc(size);
	if (allocated == NULL)
	{
		const char* function = "malloc";
		char        message[128];
		build_error_message(message, "%s failed allocating size %zu", function, size);
	}
	return allocated;
}

void* safe_calloc(size_t num, size_t size)
{
	void* allocated = calloc(num, size);
	if (allocated == NULL)
	{
		const char* function = "calloc";
		char        message[128];
		build_error_message(message, "%s failed allocating %zu items of size %zu", function, num, size);
	}
	return allocated;
}

void* safe_realloc(void* ptr, size_t new_size)
{
	void* allocated = realloc(ptr, new_size);
	if (allocated == NULL)
	{
		const char* function = "realloc";
		char        message[128];
		build_error_message(message, "%s failed reallocating %p with size %zu", function, ptr, new_size);
	}
	return allocated;
}

void* safe_aligned_alloc(size_t alignment, size_t size)
{
	void* allocated = aligned_alloc(alignment, size);
	if (allocated == NULL)
	{
		const char* function = "aligned_alloc";
		char        message[128];
		build_error_message(message, "%s failed allocating size %zu aligned on %zu", function, size, alignment);
	}
	return allocated;
}

void safe_free(void** ptr)
{
	void* allocated = *ptr;
	free(allocated);
	*ptr = NULL;
}
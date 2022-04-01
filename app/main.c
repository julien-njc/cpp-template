#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	printf("C Template just print out all command arguments\n");
	for (int index = 0; index < argc; index++)
	{
		printf("\targv[%d] is %s\n", index, argv[index]);
	}
	return (EXIT_SUCCESS);
}

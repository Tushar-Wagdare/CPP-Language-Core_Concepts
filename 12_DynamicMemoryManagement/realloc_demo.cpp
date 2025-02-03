#include <stdio.h>
#include<stdlib.h>





int main(void)
{
	int* ptr = NULL;
	size_t N = 0;
	size_t i = 0;

	int date;

	printf("Enter Integer: ");
	scanf("%d", &date);

	ptr = (int*)realloc(ptr, (N + 1) * sizeof(int));
	if (NULL == ptr)
	{
		printf("Error allocating memory");
		exit(-1);
	}
	N = N + 1;
	ptr[N - 1] = date;

	printf("Enter Integer: ");
	scanf("%d", &date);

	ptr = (int*)realloc(ptr, (N + 1) * sizeof(int));
	if (NULL == ptr)
	{
		printf("Error allocating memory");
		exit(-1);
	}
	N = N + 1;
	ptr[N - 1] = date;

	printf("Enter Integer: ");
	scanf("%d", &date);

	ptr = (int*)realloc(ptr, (N + 1) * sizeof(int));
	if (NULL == ptr)
	{
		printf("Error allocating memory");
		exit(-1);
	}
	N = N + 1;
	ptr[N - 1] = date;


	for (i = 0; i < N; ++i)
	{
		printf("ptr[%llu]: %d\n", i, ptr[i]);
	}

	free(ptr);
	ptr = NULL;

	return(0);
}

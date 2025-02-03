#include <stdio.h>
#include <stdlib.h>

const int gNum = 100;
void test(void);

int main(void)
{
	//gNum = 600;
	test();

	return(0);
}


void test(void)
{
	const int local_num = 500;
	int* ptr = NULL;                    ///int*

	ptr = &local_num;                   ///const int*

	//local_num = 700;
}
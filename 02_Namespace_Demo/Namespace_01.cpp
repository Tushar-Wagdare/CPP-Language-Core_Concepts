#include<stdio.h>

namespace X
{
	int num = 500;
	float f_num;
}

int num = 1000;

int main(void)
{
	printf("NUMBER = %d\n", num);    //1000
	printf("NUMBER = %d\n", X::num); //500

	return(0);
}


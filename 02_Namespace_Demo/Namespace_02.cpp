#include<stdio.h>

namespace X
{
	int num = 500;
	float f_num;

	struct date
	{
		int day;
		int month;
		int year;
	};

	struct Date myDate;

	class cDate
	{
		
	};

	namespace Y
	{

	}

	int main(void)
	{
		X::num = 100;

		return(0);
	}
}

int num = 1000;

int main(void)
{
	printf("NUMBER = %d\n", num);    //1000
	printf("NUMBER = %d\n", X::num); //500

	return(0);
}



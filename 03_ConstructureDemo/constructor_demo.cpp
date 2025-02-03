#include<cstdio>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date()
	{
		puts("Inside Date()");
		printf("Date():Address in this Pointer:%llu\n", (unsigned long long)this);
	}
};

int main(void)
{
	Date myDate1;
	printf("Main():Address in myDate1:%llu\n", (unsigned long long)&myDate1);
	Date myDate2;
	printf("Main():Address in myDate2:%llu\n", (unsigned long long)&myDate2);
	Date myDate3;
	printf("Main():Address in myDate3:%llu\n", (unsigned long long)&myDate3);

	return(0);
}
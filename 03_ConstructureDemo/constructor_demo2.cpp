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
		this->day = 1;
		this->month = 1;
		this->year = 1970;
	}

	void show()
	{
		printf("Date::show:addr(this):%llu\n", (unsigned long long)this);
		printf("%d/%d/%d\n", this->day, this->month, this->year);
	}
};

int main(void)
{
	Date myDate1;
	Date myDate2;
	Date myDate3;


	printf("main():addr(myDate1):%llu::addr(myDate2):%llu:addr(myDate3):%llu\n", (unsigned long long) & myDate1, (unsigned long long) & myDate2, (unsigned long long) & myDate3);

	myDate1.show();
	myDate2.show();
	myDate3.show();



	return(0);
}
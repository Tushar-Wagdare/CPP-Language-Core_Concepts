#include <cstdio>


class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int initDay, int initMonth, int initYear)
	{
		this->day = initDay;
		this->month = initMonth;
		this->year = initYear;
	}

	void show()
	{
		printf("Date::show:addr(this):%llu\n", (unsigned long long)this);
		printf("%d/%d/%d\n", this->day, this->month, this->year);
	}

};




int main(void)
{
	Date myDate1(1, 1, 1970);
	Date myBirthDay(31, 03, 2000);

	myDate1.show();
	myBirthDay.show();

	return(0);
}
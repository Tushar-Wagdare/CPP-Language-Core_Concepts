#include <cstdio>


class Date_1
{
	private:
		int day;
		int month;
		int year;

	public:
		Date_1() : day(3), month(5), year(1999)
		{

		}

		void show()
		{
			printf("Date::show:addr(this):%llu\n", (unsigned long long)this);
			printf("%d/%d/%d\n", this->day, this->month, this->year);
		}

};

class Date_2
{
private:
	int day;
	int month;
	int year;

public:
	Date_2(int initDay, int initMonth, int initYear) : day(initDay), month(initMonth), year(initYear)
	{

	}

	void show()
	{
		printf("Date::show:addr(this):%llu\n", (unsigned long long)this);
		printf("%d/%d/%d\n", this->day, this->month, this->year);
	}
};




int main(void)
{
	Date_1 myDate1;
	Date_2 myBirthDay(31, 03, 2000);

	myDate1.show();
	myBirthDay.show();

	return(0);
}
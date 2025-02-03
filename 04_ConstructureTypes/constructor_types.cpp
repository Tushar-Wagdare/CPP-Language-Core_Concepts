#include <cstdio>


class Date
{
	private:
		int day;
		int month;
		int year;

	public:
		///Default Constructor
		Date()
		{
			day = 1;
			month = 5;
			year = 2000;
		}
		///Parameterized constructor
		Date(int initDay, int initMonth, int initYear)
		{
			day = initDay;
			month = initMonth;
			year = initYear;
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

	myDate1.show();

	return(0);
}
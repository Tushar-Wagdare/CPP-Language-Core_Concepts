#include<iostream>
#include"DateWithClass.hpp"

int main(void)
{
	Date* pDate = new Date(20, 12, 2000);

	pDate->show();

	int day_part = pDate->get_day();
	int month_part = pDate->get_month();
	int year_part = pDate->get_year();


	std::cout << "day_part:" << day_part << std::endl
		      << "month_part:" << month_part << std::endl
		      << "year_part:" << year_part << std::endl;

	pDate->set_day(31);
	pDate->set_month(03);
	pDate->set_year(2000);

	pDate->show();

	delete pDate;
	pDate = 0;

	return(EXIT_SUCCESS);
}


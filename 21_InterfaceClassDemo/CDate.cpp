#include<iostream>
#include "CDate.hpp"

IDate* IDate::get_instance(int _day, int _month, int _year)
{
    return(new CDate(_day, _month, _year));
}

void IDate::release_instance(IDate* pIDate)
{
    delete pIDate;
}

CDate::CDate() : day(0), month(0), year(0) {}

CDate::CDate(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

int CDate::get_day(void)
{
    return(day);
}

void CDate::set_day(int _day)
{
    day = _day;
}

void CDate::show(void)
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}
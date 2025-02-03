#include<iostream>

class Date
{
    private:    
        int day;
        int month;
        int year;

    public:
        Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

        friend std::ostream& operator<<(std::ostream& os, const Date& _date);
};


std::ostream& operator<<(std::ostream& os, const Date& _date)
{
    os << _date.day << "/" << _date.month << "/" << _date.year << std::endl;

    return(os);
}

int main(void)
{
    Date my_date(31, 3, 2000);

    std::cout << my_date << std::endl;


    return(0);
}
#include<iostream>


class Date
{
    private:    
        int day;
        int month;
        int year;

    public:
        Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}
        Date()
        {

        }

        friend std::ostream& operator<<(std::ostream& os, const Date& _date);
        friend std::istream& operator>>(std::istream& is, Date& _date);
};


std::ostream& operator<<(std::ostream& os, const Date& _date)
{
    os << _date.day << "/" << _date.month << "/" << _date.year << std::endl;

    return(os);
}

std::istream& operator>>(std::istream& is, Date& _date)
{
    std::cout << "Enter day : ";
    is >> _date.day;
    std::cout << "Enter month : ";
    is >> _date.month;
    std::cout << "Enter year : ";
    is >> _date.year;

    return(is);
}

int main(void)
{
    Date my_date;

    std::cin >> my_date;

    std::cout << "Entered Date is : "<< std::endl;
    std::cout << my_date << std::endl;


    return(0);
}


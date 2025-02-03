#include<iostream>

class Date
{
    private:
        int day, month, year;

    public:
        Date() : day(31), month(3), year(2000) {}

        Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

        void show(char* msg = 0)
        {
            if(msg)
                std::cout << msg << std::endl;

            std::cout << day << "/" << month << "/" << year << std::endl;
        }
};

int main(void)
{
    Date d1;
    Date d2(1,1,2000);
    Date d3 = d1;
    Date d4(d2);

    d1.show("d1");
    d2.show("d2");
    d3.show("d3");
    d4.show("d4");



    return(0);
}
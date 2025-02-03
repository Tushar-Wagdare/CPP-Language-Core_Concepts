#include<iostream>

class Date
{
    private:
        int day, month, year = 0;

        Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year)
        {

        }

    public:
        static int object_count;

        static Date* getInstance(int _day,int _month, int _year)
        {
            object_count++;

            if(object_count > 1)
                throw std::runtime_error("This is a singleton class and can not allow more than one object");
            else
                std::cout << "First object of a singleton class is now being created" << std::endl;

            return(new Date(_day, _month, _year));
        }

        void show(void)
        {
            std::cout << day << "/" << month << "/" << year << std::endl;
        }

};

int Date::object_count = 0;


int main(void)
{
    Date* singleton_instance_one = Date::getInstance(31, 3, 2000);
    singleton_instance_one->show();

    try
    {
        Date* singleton_instance_two_try = Date::getInstance(1, 1, 2000);
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return(0);
}



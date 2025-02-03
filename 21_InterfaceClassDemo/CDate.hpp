#ifndef _CDATE_HPP
#define _CDATE_HPP

#include "IDate.hpp"


class CDate : public IDate
{
    private:
        int day, month, year;

    public:
        CDate();
        CDate(int _day, int _month, int _year);
        int get_day(void);
        void set_day(int);
        void show(void);
       
};

#endif // _CDATE_HPP
#ifndef _IDATE_HPP
#define _IDATE_HPP

class IDate
{
    public:
        virtual int get_day(void) = 0;
        virtual void set_day(int) = 0;
        virtual void show(void) = 0;
        static IDate* get_instance(int, int, int);
        static void release_instance(IDate*);
};



#endif // _IDATE_HPP
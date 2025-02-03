#include <iostream>
#include "IDate.hpp"



int main(void)
{
    IDate* pIDate = NULL;
    pIDate = IDate::get_instance(31, 3, 2000);

    pIDate->show();
    pIDate->set_day(13);
    pIDate->show();

    IDate::release_instance(pIDate);

    return(0);
}


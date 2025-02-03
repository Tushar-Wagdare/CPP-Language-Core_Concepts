#include<iostream>
#include<cstdlib>
#include"range.hpp"




int main(void)
{
    Range R(10, 20);

    Range::iterator iter = R.begin();

    

    while(iter != R.end())
    {
        std::cout << "*iter : " << *iter << std::endl;
        ++iter;
    }



    return(0);
}



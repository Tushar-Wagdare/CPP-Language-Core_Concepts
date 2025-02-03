#include<iostream>
#include"max.hpp"


int main(void)
{
    int a = 300;

    int m1 = max<int>(a, 200);

    std::cout << "max in " << a << " and 200 is : " << m1 << std::endl;

    
    float f = 500.5f;

    float f1 = max<float>(f, 100.3);

    std::cout << "max in " << f << " and 100.3 is : " << f1 << std::endl;   


    return(0);
}
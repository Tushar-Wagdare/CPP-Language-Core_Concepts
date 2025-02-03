#include<iostream>


int main(void)
{
    void test(int&);

    int n = 100;

    std::cout << "Before test() n : " << n << std::endl;
    test(n);
    std::cout << "After test() n : " << n << std::endl;

    return(0);
}

void test(int& _n)
{
    _n = 200;
}
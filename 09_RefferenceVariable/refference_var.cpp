#include<iostream>

int main(void)
{
    int num = 100;
    int& refNum = num;

    std::cout << "num:" << num << "\nrefNum:" << refNum << std::endl;

    std::cout << "&num:" << reinterpret_cast<unsigned long long>(&num) 
              << "\n&refNum:" << reinterpret_cast<unsigned long long>(&refNum) 
              << std::endl;

    return(0);
}

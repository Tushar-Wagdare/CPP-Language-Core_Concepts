#include <iostream>

template <typename T, int N>
T max(const T& a, const T& b)
{
    if(a > b)
        return(a*N);
    return(b*N);
}


int main(void)
{
    double a = 21.555555f; 
    double b = 30.56666666f;

    double ret = max<double, 30>(a, b);
    std::cout << "max in " << a << " and " << b << " is " << ret << std::endl;


    return(0);
}


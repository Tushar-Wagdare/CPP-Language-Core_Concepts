#include<iostream>


class ArithmaticFunction
{
    private:
        int (*pfn)(int, int);

    public:
        ArithmaticFunction() : pfn(0) {}

        void set(int(*_pfn)(int, int))
        {
            pfn = _pfn;
        }

        int operator()(int op1, int op2)
        {
            return(pfn(op1, op2));
        }
};

int main(void)
{
    int add(int, int);
    int sub(int, int);

    ArithmaticFunction af;

    af.set(add);
    int ret = af(10, 20);
    std::cout << "addition : " << ret << std::endl;

    af.set(sub);
    ret = af(10, 20);
    std::cout << "subtraction : " << ret << std::endl;

    return(0);
}


int add(int a, int b)
{
    return(a+b);
}


int sub(int a, int b)
{
    return(a-b);
}


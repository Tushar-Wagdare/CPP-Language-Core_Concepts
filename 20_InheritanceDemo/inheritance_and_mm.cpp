#include<iostream>

const int ARRAY_SIZE = 5;

class B
{
    private:
        int m, n;

    public:
        B() : m(10), n(20) { }

        void show(void) const
        {
            std::cout << "B::show()" << std::endl 
                                     << "m = " << m << std::endl
                                     << "n = " << n << std::endl; 
        }
};

class D1 : public B
{
    private:
        float x, y;

    public:
        D1() : x(1.1f), y(2.2f) { }

        void show(void) const
        {
            std::cout << "D1::show()" << std::endl 
                                      << "x = " << x << std::endl
                                      << "y = " << y << std::endl; 
        }
};

class D2 : public D1
{
    private:
        int arr[ARRAY_SIZE];

    public:
        D2()
        {
            for(int i = 0; i < ARRAY_SIZE; i++)
                arr[i] = (i+1)*100;
        }

        void show(void) const
        {
            std::cout << "D2::show()" << std::endl;
            for(int i = 0; i < ARRAY_SIZE; i++)
                std::cout << "arr[" << i << "] = " << arr[i] << std::endl;                          
        }
};


int main(void)
{
    D2 objD2;
    D1* pD1 = 0;
    B* pB = 0;

    objD2.show();

    (*dynamic_cast<B*>(&objD2)).show();
    (*dynamic_cast<D1*>(&objD2)).show();


    pB = dynamic_cast<B*>(&objD2); 
    pD1 = dynamic_cast<D1*>(&objD2);

    std::cout << "pB  :" << pB << std::endl; 
    std::cout << "pD1 :" << pD1 << std::endl;
    std::cout << "pD2 :" << &objD2 << std::endl;


    return(EXIT_SUCCESS);
}
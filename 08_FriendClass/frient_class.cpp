#include<iostream>

class C1
{
    friend class C2;
    private: 
        int a,b;
        float x,y;

    public:

    C1() : a(10), b(20)
    {

    } 
};

C1 inC1;


class C2
{
    private:
        const char* msg = "Tushar Wagdare";
        int m,n;

    public:
        C2() : m(50), n(100)
        {

        }

    static void printC1(void)
    {
        std::cout << "a:" 
                  << inC1.a << "\nb:" 
                  << inC1.b << "\nx:" 
                  << inC1.x << "\ny:" 
                  << inC1.y << "\n"
                  << std::endl;
    }

    static void setC1(int _a, int _b, float _x, float _y)
    {
        inC1.a = _a;
        inC1.b = _b;
        inC1.x = _x;
        inC1.y = _y;
    }
};


int main(void)
{
    C2::printC1();
    
    C2::setC1(1, 2, 3.3f, 4.4f);

    C2::printC1();

    return(0);
}




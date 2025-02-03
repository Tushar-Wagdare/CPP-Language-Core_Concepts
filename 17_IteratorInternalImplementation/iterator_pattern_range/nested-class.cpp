#include<iostream>

class A
{
    private:
        int a;
        int b;

    public:
        A(int _a, int _b): a(_a), b(_b){

        }

        void show() const{
            std::cout << "a:" << a << std::endl
                      << "b:" << b << std::endl;
        }

    
        class B
        {
            private:
                double x,y,z;
            
            public:
                B(double _x, double _y, double _z): x(_x), y(_y), z(_z){

        }
        };
};

//Here class A and class B han NO MEMMORY MANAGEMENT between then 
//ther is only one consiquence that we can only make object of class B usin A::B


int main(void)
{
    A objA(12, 13);
    A::B objB(1.1,2.2,3.3);

    printf("sizeof(A) : %zu, sizeof(B) : %zu\n", sizeof(objA), sizeof(objB));

    return 0;
}

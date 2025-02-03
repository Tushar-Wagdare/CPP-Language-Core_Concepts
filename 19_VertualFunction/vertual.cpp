#include<iostream>


class B
{
    private:
        int a, b;

    public:
        B() : a(10), b(20) {}

        virtual void func(void)
        {
            puts("in B::func()");
        }
};

class D : public B
{
    private:
        int c, d;

    public:
        D() : c(100), d(200) {}

        void func(void)
        {
            puts("in D::func()");
        }
};


int main(void)
{
    D inD;

    inD.func();

    B* pB = &inD;

    


    return(0);
}
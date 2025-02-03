#include <iostream>

class Base
{
    public:
        void f(void)
        {
            puts("Base::f()");
        }

        void g(void)
        {
            puts("Base::g()");
        }

        virtual void h(void)
        {
            puts("Base::h()");
        }
};

class Derived : public Base
{
    public:
        void g(void)
        {
            puts("Derived::g()");
        }

        void h(void)
        {
            puts("Derived::h()");
        }

        void i(void)
        {
            puts("Derived::i()");
        }
};


int main(void)
{
    Derived inD;
    Base* pB = &inD;
    Derived* pD = &inD;

    pB->f();                            // Base::f();
    pB->g();                            // Base::g();
    pB->Base::h();                      // Base::h();
    dynamic_cast<Derived*>(pB)->g();    // Derived::g();
    pB->h();                            // Derived::h();
    dynamic_cast<Derived*>(pB)->i();    // Derived::i();

    puts("\n\n");

    pD->g();                            // Derived::g();
    pD->h();                            // Derived::h();
    pD->i();                            // Derived::i();
    pD->f();                            // Base::f();
    pD->Base::g();                      // Base::g();
    pD->Base::h();                      // Base::h();

    return(0);
}


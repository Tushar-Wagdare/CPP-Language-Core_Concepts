#include<iostream>


class B
{
    private:
        int a, b;

    protected:
        void pro_showB(void)
        {
            std::cout << "    B::pro_showB()" << std::endl;
        }

    public:
        void pub_showB(void)
        {
            std::cout << "    B::pub_showB()" << std::endl;
        }
};

class B1 : protected B
{
    private:
        int a, b;

    protected:
        void pro_showB1(void)
        {
            std::cout << "  B1::pro_showB1() HAS ACCESS TO" << std::endl;
            pro_showB();
            pub_showB();
        }

    public:
        void pub_showB1(void)
        {
            std::cout << "  B1::pub_showB1() HAS ACCESS TO" << std::endl;
            pro_showB();
            pub_showB();
        }
};

class D : public B1
{
    private:
        int a, b;

    public:
        void showD(void)
        {
            std::cout << "D::showD() HAS ACCESS TO" << std::endl;
            pro_showB1();
            pub_showB1();
            pro_showB();
            pub_showB();
        }
};


int main(void)
{
    D objD;
    B1 objB1;

    //objB1.pub_showB();  // pub of B unavailable

    //objD.pub_showB();   // pub of B unavailable
    objD.pub_showB1();    // pub of B1 available
    objD.showD();         // pub of D available

    return(0);
}
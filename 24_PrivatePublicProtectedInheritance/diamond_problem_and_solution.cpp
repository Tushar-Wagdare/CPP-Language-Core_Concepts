#include<iostream>


class B
{
    private:
        int a, b;

    public:
        void showB(void)
        {
            std::cout << "in B::show()" << std::endl;
        }
};

class B1 : virtual public B
{
    private:
        int a, b;

    public:
        void showB1(void)
        {
            std::cout << "in B1::show()" << std::endl;
        }
};

class B2 : virtual public B
{
    private:
        int a, b;

    public:
        void showB2(void)
        {
            std::cout << "in B2::show()" << std::endl;
        }
};

class D : public B1, public B2
{
    private:
        int a, b;

    public:
        void showD(void)
        {
            std::cout << "in D::show()" << std::endl;
        }
};


int main(void)
{
    D objD;


    // objD.showB(); // befour class D : vertual private B1,  vertual private B2
    // ERROR -> D::showB" is ambiguous and size of objD is 40 bytes

    objD.showB();// after class D : vertual private B1, vertual private B2 
    //NO ERROR -> D::showB" size is 48 bytes 32 bytes objD size + two 8 bytes vptr

    std::cout << "sizeof(objD) : " << sizeof(objD) << std::endl;


    return(0);
}
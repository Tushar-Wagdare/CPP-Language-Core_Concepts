#include<iostream>

class MYInt
{
    private:
        int i;

    public:
        MYInt() : i(0) {}

        MYInt(int _i) : i(_i) {}

        void show(void) const{ std::cout << i << std::endl; }

        MYInt operator+(MYInt& input_i) { return(i + input_i.i); }
        MYInt operator-(MYInt& input_i) { return(i - input_i.i); }
        MYInt operator*(MYInt& input_i) { return(i * input_i.i); }
        MYInt operator/(MYInt& input_i) { return(i / input_i.i); }
        MYInt operator%(MYInt& input_i) { return(i % input_i.i); }

        ~MYInt() {}
};


int main(void)
{
    MYInt i1(30);
    MYInt i2(10);
    
    MYInt sumI = i1 + i2;
    MYInt subI = i1 - i2;
    MYInt mulI = i1 * i2;
    MYInt devI = i1 / i2;
    MYInt modI = i1 % i2;

    sumI.show();
    subI.show();
    mulI.show();
    devI.show();
    modI.show();

    return(0);
}

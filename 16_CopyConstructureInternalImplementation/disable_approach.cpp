#include<iostream>
#include<stdexcept>


class HashPtr{
    private:
    int N;
    int* ptr;

    public:
    HashPtr(int _n, int _val) : N(_n), ptr(new int(_val)){
    }

    HashPtr(const HashPtr)
};


int main(void){



    return(0);
}
#include<iostream>


class HashPtr{
    private:
    int n;
    int* ptr;

    public:
    HashPtr(int _n, int _val) : n(_n), ptr(new int((_val))){
    }

    ~HashPtr(){
        delete(ptr);
    }

    HashPtr(const HashPtr& other) : n(other.n), ptr(new int(*other.ptr)){
    }

    HashPtr& operator=(const HashPtr other){
        if(this != &other)
        {
            n = other.n;
            *this->ptr = *other.ptr;
        }
        return(*this);
    }

    int getn()const{
        return(n);
    }

    void setn(int new_n){
        n = new_n;
    }

    int* get_ptr()const{
        return(ptr);
    }

    int getptr_val()const{
        return(*ptr);
    }

    void setptr_val(int new_val){
        *this->ptr = new_val;
    }
};


int main(void)
{
    test();

    return(0);
}

void test(void)
{
    HashPtr hp1(10,20);

    HashPtr hp2(hp1);

    HashPtr hp3(100,200);

    hp1 = hp3;
}
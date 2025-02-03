#include <iostream> 
#include <typeinfo> 

class B1 {
    public: 
        void f(){
            std::cout << "In B1::f()" << std::endl; 
        }
};  

class D1 : public B1{
    public: 
        void f(){
            std::cout << "In D1::f()" << std::endl; 
        }
}; 

class B2 {
    public: 
        virtual void f(){
            std::cout << "In B2::f()" << std::endl; 
        }
};  

class D2 : public B2{
    public: 
        void f(){
            std::cout << "In D2::f()" << std::endl; 
        }
}; 

int main(void){
    int a = 10; 
    float f = 3.14; 
    auto d = 345435.353445; 

    std::cout << "typeid(a).name() -> " << typeid(a).name() << std::endl; 
    std::cout << "typeid(f).name() -> " << typeid(f).name() << std::endl; 
    std::cout << "typeid(d).name() -> " << typeid(d).name() << std::endl; 
    std::cout << "typeid(typeid(a)).name() -> " << typeid(typeid(a)).name() 
                << std::endl; 

    D1 objD1; 
    D2 objD2; 

    B1* pB1 = &objD1; 
    B2* pB2 = &objD2; 

    std::cout << "typeid(pB1).name() -> " << typeid(pB1).name() << std::endl; 
    std::cout << "typeid(pB2).name() -> " << typeid(pB2).name() << std::endl; 

    std::cout << "typeid(*pB1).name() -> " << typeid(*pB1).name() << std::endl; 
    std::cout << "typeid(*pB2).name() -> " << typeid(*pB2).name() << std::endl; 

    return 0; 
}
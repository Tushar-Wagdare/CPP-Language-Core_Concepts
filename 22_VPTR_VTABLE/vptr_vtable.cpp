#include <iostream>


class B
{
    public:
        virtual void funcA(void)
        {
            std::cout << "in B::funcA" << std::endl;
        }

        virtual void funcB(void)
        {
            std::cout << "in B::funcB" << std::endl;
        }
};

class D : public B
{
    public:
        void funcA(void)
        {
            std::cout << "in D::funcA" << std::endl;
        }

        void funcB(void)
        {
            std::cout << "in D::funcB" << std::endl;
        }
};


int main(void)
{
   D* pD = new D;
   void (*pfnA)(void) = NULL;
   void (*pfnB)(void) = NULL;

   unsigned long long* vptr = reinterpret_cast<unsigned long long*>(pD);
   unsigned long long* vtable = reinterpret_cast<unsigned long long*>(*vptr);
   unsigned long long* add_of_func_a = reinterpret_cast<unsigned long long*>(vtable[0]);
   unsigned long long* add_of_func_b = reinterpret_cast<unsigned long long*>(vtable[1]);

   std::cout << "address of vptr -> (pD)          : " 
             << reinterpret_cast<unsigned long long>(vptr) 
             << std::endl;
   std::cout << "address of vtable -> (*pD)       : " 
             << reinterpret_cast<unsigned long long>(vtable) 
             << std::endl;
   std::cout << "address of funcA -> (*pD)[0]     : " 
             << reinterpret_cast<unsigned long long>(add_of_func_a) 
             << std::endl;
   std::cout << "address of funcB -> (*pD)[1]     : " 
             << reinterpret_cast<unsigned long long>(add_of_func_b) 
             << std::endl;
     

   pfnA = reinterpret_cast<void (*)()>(add_of_func_a);
   pfnB = reinterpret_cast<void (*)()>(add_of_func_b);

   std::cout << "\nManually calling overridden derived class functions using vptr and vtable" << std::endl;
   pfnA();
   pfnB();


   return(0);
}


#include <iostream>
#include <memory>

class HasPtr
{
    public:
        int n;
        std::shared_ptr<int> sp;

        HasPtr(int _n, int val) : n(_n), sp(std::make_shared<int>(val)) {}
        void get_ref_count(const char* msg)
        {
            if(msg)
                std::cout << msg << std::endl;

            std::cout << sp.use_count() << std::endl;
        }
};



int main(void)
{
    HasPtr hp1(100, 200);
    hp1.get_ref_count("hp1");
    HasPtr hp2(hp1);
    hp1.get_ref_count("hp1");
    HasPtr hp3(hp2);
    hp1.get_ref_count("hp1");



    return(0);
}
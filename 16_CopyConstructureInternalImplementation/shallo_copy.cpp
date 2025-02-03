#include<iostream>


typedef struct S_INTPTR
{
    unsigned int ui_ref_count;
    int* ip_num;
}S_INTPTR;


class C_HasPtr
{
    private:
        int i_randNum;
        S_INTPTR* sp_intPtr;

    public:
        C_HasPtr()
        {
            i_randNum = 0;
            sp_intPtr = (S_INTPTR*)malloc(sizeof(S_INTPTR));
            sp_intPtr->ui_ref_count = 1;
            sp_intPtr->ip_num = (int*)malloc(sizeof(int));
            *sp_intPtr->ip_num = 0;
        }

        C_HasPtr(int rand_num, int val)
        {
            i_randNum = rand_num;
            sp_intPtr = (S_INTPTR*)malloc(sizeof(S_INTPTR));
            sp_intPtr->ui_ref_count = 1;
            sp_intPtr->ip_num = (int*)malloc(sizeof(int));
            *sp_intPtr->ip_num = val;
        }

        C_HasPtr(const C_HasPtr& other)
        {
            i_randNum = other.i_randNum;
            sp_intPtr = other.sp_intPtr;
            sp_intPtr->ui_ref_count++;
        }

        C_HasPtr& operator=(const C_HasPtr& other)
        {
            if(&other != this)
            {
                sp_intPtr->ui_ref_count--;
                if(sp_intPtr->ui_ref_count == 0)
                {
                    free(sp_intPtr->ip_num);
                    free(sp_intPtr);
                }
                i_randNum = other.i_randNum;
                sp_intPtr = other.sp_intPtr;
                sp_intPtr->ui_ref_count++;
            }
            
            return(*this);
        }

        unsigned int get_ref_count(void)
        {
            return(sp_intPtr->ui_ref_count);
        }

        ~C_HasPtr()
        {
            std::cout << "In Destructor : RC = " << sp_intPtr->ui_ref_count << std::endl;
            sp_intPtr->ui_ref_count--;
            if(sp_intPtr->ui_ref_count == 0)
            {
                std::cout << "FREEING sp_intPtr OBJECT NOW..." << std::endl;
                free(sp_intPtr->ip_num);
                free(sp_intPtr);
                std::cout << "sp_intPtr is destroyed..." << std::endl;
            }
        }
};


int main(void)
{
    C_HasPtr h1(100, 200);
    std::cout<<"AFTER : C_HasPtr h1(100, 200); rc = "<<h1.get_ref_count()<<std::endl;

    C_HasPtr h2(h1);
    std::cout <<"AFTER : C_HasPtr h2(h1); rc(h1) = "
              <<h1.get_ref_count()
              <<" | rc(h2) = "
              << h2.get_ref_count()
              <<std::endl;

    C_HasPtr h3(300, 400);
    std::cout<<"AFTER : C_HasPtr h3(300, 400); rc = "<<h3.get_ref_count()<<std::endl;

    h3 = h2;
    std::cout <<"AFTER : h3 = h2; rc(h1) = "
              <<h1.get_ref_count()
              <<" | rc(h2) = "
              << h2.get_ref_count()
              <<" | rc(h3) = "
              << h3.get_ref_count()
              <<std::endl;

    return(0);
}
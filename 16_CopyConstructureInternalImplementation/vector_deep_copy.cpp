#include<iostream>
#include<cstdlib>

#define SUCCESS 0
#define FAIL    1

typedef int status_t;


class Vector
{
    private:
        int* pArr;
        size_t N;

    public:
        Vector() : pArr(0), N(0) { }

        Vector(const Vector& other)
        {
            N = other.N;
            pArr = (int*)malloc(N*sizeof(int));
            if(pArr==NULL)
            {
                std::cout<<"Error in memory allocation"<<std::endl;
                exit(EXIT_FAILURE);
            }

            memcpy((void*)pArr, (void*)other.pArr, N*sizeof(int));
        }

        void operator=(const Vector& other)
        {
            N = other.N;
            pArr = (int*)realloc(pArr, N*sizeof(int));
            if(pArr==NULL)
            {
                std::cout<<"Error in memory allocation"<<std::endl;
                exit(EXIT_FAILURE);
            }

            memcpy((void*)pArr, (void*)other.pArr, N*sizeof(int));
        }

        status_t push_back(int _data)
        {
            N++;
            pArr = (int*)realloc(pArr, N * sizeof(int));
            if(NULL == pArr)
            {
                std::cout << "Error in memory allocation" << std::endl;
                exit(-1);
            }

            *(pArr + (N - 1)) = _data;

            return(SUCCESS);
        }

        void show(char* msg = 0) const
        {
            if(msg)
                std::cout<<msg<<std::endl;
            for(int i = 0; i < N; i++)
                std::cout << "arr[" << i << "] = " << *(pArr + i) << std::endl;
        }

        ~Vector()
        {
            free(pArr);
        }
};


int main(void)
{
    Vector v1;
    for(int i = 0; i < 5; i++)
        v1.push_back((i+1)*10);
    v1.show("v1 : " );

    Vector v2(v1);
    v2.show("v2 : 1st time");
    v2.push_back(60);
    v2.push_back(70);
    v2.push_back(80);
    v2.push_back(90);
    v2.push_back(100);
    v2.show("v2 : 2nd time");

    Vector v3 = v2;
    v3.show("v3 : ");

    return(0);
}
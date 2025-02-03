#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>


class string
{
    private:
        char* p_str;
        size_t N;

    public:
        string() : p_str(0), N(0) {}

        string(const char* init_string)
        {
            N = strlen(init_string);

            p_str = (char*)malloc((N + 1) * sizeof(char));
            if(NULL == p_str)
            {
                std::cout << "Error in memory allocation" << std::endl;
                exit(-1);
            }

            strncpy(p_str, init_string, N);
            p_str[N] = '\0';
        }

        string(size_t size, char c)
        {
            N = size;
            p_str = (char*)malloc((N + 1) * sizeof(char));
             if(NULL == p_str)
            {
                std::cout << "Error in memory allocation" << std::endl;
                exit(-1);
            }

            memset(p_str, c, N);

            p_str[N] = '\0';
        }

        void show(char* msg)
        {
            if(msg)
                std::cout << msg << std::endl;


            if(NULL != p_str)
                std::cout << "string = " << p_str << std::endl;
            else
                std::cout << "string = " << std::endl;
        }

        ~string()
        {
            free(p_str);
        }
};


int main(void)
{
    string s1;
    string s2("Hello World");
    string s3(5, 'T');

    
    s1.show("string 1");
    s2.show("string 2");
    s3.show("string 3");

    return(0);
}
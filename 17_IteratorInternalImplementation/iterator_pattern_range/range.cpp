#include<iostream>
#include<cstdlib>

class Range
{
    private:
        int n_start;
        int n_end;

    public:
        class iterator; //Forward declaration

        Range(int _start, int _end) : n_start(_start), n_end(_end) {   
            if(n_start >= n_end){
                std::cout << "start must be less than end" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        iterator begin() const{
            iterator iter(n_start);
            return(iter);
        }

        iterator end() const{
            iterator iter(n_end);
            return(iter);
        }

        class iterator{
            private:
                int current_n;

            public:
                iterator(int _n) : current_n(_n){
                }

                int& operator*(){
                    return(current_n);
                }

                iterator operator++(){
                    current_n += 1;
                    return(*this);
                }

                iterator operator++(int){
                    iterator tmp(current_n); 
                    current_n += 1; 
                    return tmp; 
                }

                iterator operator--(){
                    current_n -= 1;
                    return(*this);
                }

                iterator operator--(int){
                    iterator tmp(current_n); 
                    current_n -= 1; 
                    return tmp;
                }

                bool operator==(const iterator& rhs){
                    return(current_n == rhs.current_n);
                }

                bool operator!=(const iterator& rhs){
                    return(current_n != rhs.current_n);
                }
        };
};



int main(void)
{
    Range R(10, 20);

    Range::iterator iter = R.begin();

    

    while(iter != R.end())
    {
        std::cout << "*iter : " << *iter << std::endl;
        ++iter;
    }



    return(0);
}



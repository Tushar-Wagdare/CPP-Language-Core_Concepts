#include"range.hpp"


Range::Range(int _start, int _end) : n_start(_start), n_end(_end) {   
    if(n_start >= n_end){
        std::cout << "start must be less than end" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Range::iterator Range::begin() const{
    iterator iter(n_start);
    return(iter);
} 

Range::iterator Range::end() const{
    iterator iter(n_end);
    return(iter);
}

    
Range::iterator::iterator(int _n) : current_n(_n){
}

int& Range::iterator::operator*(){
    return(current_n);
}

Range::iterator Range::iterator::operator++(){
    current_n += 1;
    return(*this);
}

Range::iterator Range::iterator::operator++(int){
    iterator tmp(current_n); 
    current_n += 1; 
    return tmp; 
}

Range::iterator Range::iterator::operator--(){
    current_n -= 1;
    return(*this);
}

Range::iterator Range::iterator::operator--(int){
    iterator tmp(current_n); 
    current_n -= 1; 
    return tmp;
}

bool Range::iterator::operator==(const iterator& rhs){
    return(current_n == rhs.current_n);
}

bool Range::iterator::operator!=(const iterator& rhs){
    return(current_n != rhs.current_n);
}




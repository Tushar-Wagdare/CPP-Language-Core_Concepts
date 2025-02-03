#ifndef _MAX_HPP
#define _MAX_HPP

template <typename T>

T max(T const& a, T const&b)
{
    if(a>b)
        return(a);
    else
        return(b);
}


#endif // _MAX_HPP
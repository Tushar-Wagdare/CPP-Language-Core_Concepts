#ifndef _RANGE_HPP
#define _RANGE_HPP

#include<iostream>

class Range
{
    private:
        int n_start;
        int n_end;

    public:
        class iterator; //Forward declaration

        Range(int, int);

        iterator begin() const;

        iterator end() const;

        class iterator{
            private:
                int current_n;

            public:
                iterator(int);

                int& operator*();

                iterator operator++();

                iterator operator++(int);

                iterator operator--();

                iterator operator--(int);

                bool operator==(const iterator&);

                bool operator!=(const iterator&);
        };
};


#endif // _RANGE_HPP

#include<iostream>


class MyInt
{
    private:
        int n;

    public:
        MyInt() : n(0) {}

        MyInt(int _n) : n(_n) {}

        void show(char* msg)
        {
            if(msg)
                std::cout << msg << std::endl;

            std::cout << "n : " << n << std::endl;
        }

        MyInt operator+(const MyInt& other) const
        {
            MyInt result;
            result.n = n + other.n;

            return(result);
        }

        MyInt operator-(const MyInt& other) const
        {
            MyInt result;
            result.n = n - other.n;

            return(result);
        }

        MyInt operator*(const MyInt& other) const
        {
            MyInt result;
            result.n = n * other.n;

            return(result);
        }

        MyInt operator/(const MyInt& other) const
        {
            MyInt result;
            result.n = n / other.n;

            return(result);
        }

        MyInt operator%(const MyInt& other) const
        {
            MyInt result;
            result.n = n % other.n;

            return(result);
        }

        MyInt operator&(const MyInt& other) const
        {
            MyInt result;
            result.n = n & other.n;

            return(result);
        }

        MyInt operator|(const MyInt& other) const
        {
            MyInt result;
            result.n = n | other.n;

            return(result);
        }

        MyInt operator~(void)
        {
            MyInt result;
            result.n = ~n;

            return(result);
        }

        MyInt operator^(const MyInt& other) const
        {
            MyInt result;
            result.n = n ^ other.n;

            return(result);
        }

        MyInt operator<<(const MyInt& other) const
        {
            MyInt result;
            result.n = n << other.n;

            return(result);
        }

        MyInt operator>>(const MyInt& other) const
        {
            MyInt result;
            result.n = n >> other.n;

            return(result);
        }

        MyInt operator&&(const MyInt& other) const
        {
            MyInt result;
            result.n = n && other.n;

            return(result);
        }

        MyInt operator||(const MyInt& other) const
        {
            MyInt result;
            result.n = n || other.n;

            return(result);
        }

        MyInt operator!(void)
        {
            MyInt result;
            result.n = !n;

            return(result);
        }

        bool operator>(const MyInt& other) const
        {
            bool exp;
            exp = n > other.n;

            return(exp);
        }

        bool operator<(const MyInt& other) const
        {
            bool exp;
            exp = n < other.n;

            return(exp);
        }

        bool operator>=(const MyInt& other) const
        {
            bool exp;
            exp = n >= other.n;

            return(exp);
        }

        bool operator<=(const MyInt& other) const
        {
            bool exp;
            exp = n <= other.n;

            return(exp);
        }

        bool operator==(const MyInt& other) const
        {
            bool exp;
            exp = n == other.n;

            return(exp);
        }

        bool operator!=(const MyInt& other) const
        {
            bool exp;
            exp = n > other.n;

            return(exp);
        }

        // pre-increment
        MyInt operator++()
        {
            n = n + 1;

            return(*this);
        }

        // pre-decrement
        MyInt operator--()
        {
            n = n - 1;

            return(*this);
        }

        // post-increment
        MyInt operator++(int)
        {
            n = n + 1;

            return(*this);
        }

        // post-decrement
        MyInt operator--(int)
        {
            n = n - 1;

            return(*this);
        }
};


int main(void)
{
    MyInt n1(100);
    MyInt n2(10);
    MyInt result(0);

    result = n1 + n2;
    result.show("addition");

    result = n1 - n2;
    result.show("sub");

    result = n1 * n2;
    result.show("mul");

    result = n1 / n2;
    result.show("div");

    result = n1 % n2;
    result.show("modulo");

    result = n1 & n2;
    result.show("bitwise and");

    result = n1 | n2;
    result.show("bitwise or");

    result = ~n2;
    result.show("bitwise not");

    result = n1 ^ n2;
    result.show("bitwise xor");

    result = n1 << n2;
    result.show("bitwise left shift");

    result = n1 >> n2;
    result.show("bitwise right shift");

    result = n1 && n2;
    result.show("logical and");

    result = n1 || n2;
    result.show("logical or");

    result = !n2;
    result.show("logical not");

    result = n1 > n2;
    result.show("greater than");

    result = n1 < n2;
    result.show("less than");

    result = n1 >= n2;
    result.show("greater than or equal to");

    result = n1 <= n2;
    result.show("less than or equal to");

    result = n1 == n2;
    result.show("equal to equal to");

    result = n1 != n2;
    result.show("not equal to");

    result = ++n1;
    result.show("pre-increment");

    result = n1++;
    result.show("post-increment");

    result = --n1;
    result.show("pre-decrement");

    result = n1--;
    result.show("post-decrement");


    return(0);
}
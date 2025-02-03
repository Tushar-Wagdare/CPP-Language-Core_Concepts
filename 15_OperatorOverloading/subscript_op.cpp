#include<iostream>

const int ARRAY_INDICES = 5;

class Array
{
    private:
        int* arr;
        size_t N;

    public:
        Array(size_t _N) : arr(new int[_N]), N(_N) {}

        void set(size_t index, int val)
        {
            arr[index] = val;
        }

        int get(size_t index)
        {
            return(arr[index]);
        }


        int& operator[](size_t index)
        {
            return(arr[index]);
        }

        ~Array()
        {
            delete[] arr;
        }
};



int main(void)
{
    Array arr(ARRAY_INDICES);

    for(int i = 0; i < ARRAY_INDICES; i++)
        arr[i] = (i+1) * 10;


    for(int i = 0; i < ARRAY_INDICES; i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;


    return(0);
}
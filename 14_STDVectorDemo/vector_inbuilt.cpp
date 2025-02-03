#include<iostream>
#include<vector>

int main(void)
{
    std::vector<int> ivec;

    ivec.push_back(100);
    ivec.push_back(200);
    ivec.push_back(300);
    ivec.push_back(400);
    ivec.push_back(500);

    std::cout << "ivec length = " << ivec.size() << std::endl;

    for(std::vector<int>::size_type i = 0; i < ivec.size(); i++)
        std::cout << "ivec[" << i << "] = " << ivec[i] << std::endl;

    ivec.pop_back();
    ivec.pop_back();

    std::cout << "ivec length = " << ivec.size() << std::endl;

    for(std::vector<int>::size_type i = 0; i < ivec.size(); i++)
        std::cout << "ivec[" << i << "] = " << ivec[i] << std::endl;



    return(0);
}
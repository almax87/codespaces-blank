#include <iostream>
#include <cmath>
#include <vector>
template <class T>
    void square (T& a_)
    {
        std::cout << "IN: " << a_ << std::endl;
        a_ = pow(a_,2);
        std::cout << "OUT: " << a_ << std::endl;
    }
template <>
    void square (std::vector<int>& arr)
    {
        std::cout << "IN: ";
        for (auto i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        std::cout << "OUT: ";
        for (auto i = 0; i < arr.size(); i++)
        {
            arr[i] = pow(arr[i],2);
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }


int main()
{
    int a{10};
    std::vector<int> numbers{2, 4, 6, 7, 9};

    square(a);
    square(numbers);

    return 0;
}
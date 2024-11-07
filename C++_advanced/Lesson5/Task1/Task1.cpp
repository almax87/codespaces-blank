#include <iostream>
#include <cmath>
#include <vector>

template <class T>
    T square (const T& a_)
    {
        T a{};
        std::cout << "IN: " << a_ << std::endl;
        a = pow(a_,2);
        std::cout << "OUT: " << a << std::endl;
        return a;
    }

template <class T>
    std::vector<T> square (const std::vector<T>& arr)
    {
        std::vector<T> vec{};
        std::cout << "IN: ";
        for (const auto&i: arr)
            std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "OUT: ";
        for (auto i = 0; i < arr.size(); i++)
        {
            vec.push_back(pow(arr[i],2));
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        return vec;
    }


int main()
{
    int a{10};
    std::vector<int> numbers{2, 4, 6, 7, 9};

    square(a);
    square(numbers);

    return 0;
}
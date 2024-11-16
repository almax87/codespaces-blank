#include <iostream>
#include <vector>

template <class T>
std::vector<T> move_vector(std::vector<T>& dest_vec, const std::vector<T>& vec)
{
    dest_vec = std::move(vec);
    return dest_vec;    
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    move_vector(two, one);

    for (auto& i : two)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
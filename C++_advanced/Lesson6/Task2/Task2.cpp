#include <iostream>
#include <set>

int main()
{
    std::cout << "IN: " << std::endl;
    int size;
    std::cin >> size;
    int count{};
    std::set <int, std::greater<int>> list{};
    int x;
    while (count != size)
    {
        std::cin >> x;
        list.emplace(x);
        count++;
    }
    std::cout << "OUT: " << std::endl;
    for (auto& i : list)
    {
        std::cout << i << std::endl;
    }
    
    return 0;
}
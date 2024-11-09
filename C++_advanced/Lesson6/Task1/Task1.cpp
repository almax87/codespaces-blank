#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

int main()
{
    std::ifstream in("in.txt");
    std::string s{};
    char ch{};
    if (in.is_open())
    {
        while (std::getline(in, s))
        {
            std::cout << "IN: " << s << std::endl;
        }
            
        std::map <char, int> map_count{};
        for (auto& i : s)
        {
            map_count.insert(std::make_pair(i, std::count(s.begin(), s.end(), i)));
        }

        std::multimap<int, char, std::greater<int>> map_count_sort{};
        for (auto& i : map_count)
        {
            map_count_sort.insert(std::make_pair(i.second, i.first));
        }

        std::cout << "OUT: " << std::endl;

        for (auto&i : map_count_sort)
        {
            std::cout << i.second << ": " << i.first << std::endl;
        }

        in.close();
    }
    else
        {
            std::cout << "Error";
            return 1;
        }

    return 0;
}
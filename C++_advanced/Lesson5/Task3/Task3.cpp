#include <iostream>
#include <vector>
#include <algorithm>


struct Counter
{
    private:
    int sum{};
    int count{};

    public:
    void operator()(int n)
    {
        if (n%3 == 0)
        {
            sum+=n;
            count++;
        }
    }

    int get_sum() const
    {
        return sum;
    }

    int get_count() const
    {
        return count;
    }
};

template <class T>
std::ostream& operator << (std::ostream &os, const std::vector<T>& list)
{
    for (auto&i : list)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
}

int main()
{
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
    std::cout << "IN: ";
    std::cout << numbers;
    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;
    
    return 0;
}
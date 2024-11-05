#include <iostream>
#include <vector>
template <class T>
class Counter
{
    private:
        std::vector<T> numbers{};
        T sum{};
        T count{};
    public:
        Counter(std::vector<T> numbers):numbers(numbers){}
        const std::vector<T> getNumbers()
        {
            return numbers;
        }
        void operator()()
        {
            for (int i = 0; i < numbers.size(); i++)
            {
                if (numbers[i]%3 == 0)
                {
                    sum += numbers[i];
                    count++;
                }
            }
            std::cout << "[OUT]: get_sum() = " << sum << std::endl;
            std::cout << "[OUT]: get_count() = " << count << std::endl;
        }
};

template <class T>
std::ostream& operator << (std::ostream &os, const std::vector<T>& list)
{
    for (int i = 0; i < list.size(); i++)
    {
        os << list[i] << " ";
    }
    os << std::endl;
    return os;
}

int main()
{
    auto test = Counter<short>({4, 1, 3, 6, 25, 54});
    std::cout << "IN: ";
    std::cout << test.getNumbers();
    test();
    
    return 0;
}
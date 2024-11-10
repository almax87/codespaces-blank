#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
class Test 
{
    private:
    std::vector<T> vec;

    public:
        Test(std::vector<T> vec_) : vec{vec_} {}
        const void print_vector () const
        {
            for (auto& i : this->vec)
                {
                    std::cout << i << " ";
                }
            std::cout << std::endl;
        }

        std::vector<T>& make_unique ()
        {
            std::sort (vec.begin(), vec.end());
            auto it = std::unique (vec.begin(), vec.end());
            vec.erase(it, vec.end());
            return vec;
        }

};


int main()
{
    Test<int> obj({1, 1, 2, 5, 6, 1, 2, 4});
    std::cout << "IN: ";
    obj.print_vector();
    obj.make_unique();
    std::cout << "OUT: ";
    obj.print_vector();

    return 0;
}
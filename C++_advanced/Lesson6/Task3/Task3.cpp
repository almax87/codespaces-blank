#include <iostream>
#include <cstring>

template<class T>
class Vector 
{
    private:
        T* a = nullptr;
        unsigned long current;
        unsigned long capacity;


    public:
        Vector(): current(0), capacity(1), a(new T[1]) {a[0] = 0;}
        ~Vector()
        {
            delete[] a;
            a = nullptr;
        }

        T at(int index)
        {
            if (index >= current)
                throw std::runtime_error("Выход за рамки массива");
            return a[index];
        }

        void push_back (T value)
        {
            if (current != (capacity - 1))
            {
                a[current] = value;
                current++;
            }
            else 
            {
                capacity *= 2;
                T* temp = new T[capacity];
                memcpy(temp, a, capacity);
                delete[] a;
                a = temp;
                temp = nullptr;
                a[current] = value;
                current++;
            }
        }

        unsigned long getCapacity()
        {
            return capacity;
        }

        unsigned long getSize()
        {
            return current;
        }

    };

int main()
{
    Vector<int> vector;
    vector.push_back(4);
    try
    {
        std::cout << vector.at(0) << std::endl;
    }
    catch(const std::string& ex)
    {
        std::cout << ex << std::endl;
    }
    
    vector.push_back(100);
    try
    {
        std::cout << vector.at(1) << std::endl;
    }
    catch(const std::string& ex)
    {
        std::cout << ex << std::endl;
    }

    vector.push_back(2);
    vector.push_back(3);
    try
    {
        std::cout << vector.at(3) << std::endl;
    }
    catch(const std::string& ex)
    {
        std::cout << ex << std::endl;
    }


    std::cout << vector.getCapacity() << std::endl;
    std::cout << vector.getSize() << std::endl;


    return 0;
}
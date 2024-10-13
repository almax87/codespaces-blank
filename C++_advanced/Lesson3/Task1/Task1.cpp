#include <iostream>
#include <exception>
#include <stdexcept>

class arr_exception : public std::runtime_error{
    using std::runtime_error :: runtime_error;
};

class smart_array{

    private:
    int index;

    public:
    int size;
    int* arr;

    smart_array(const int& size):size(size)
    {
        arr = new int[size];
        this->index = 0;
    }
    smart_array():smart_array(size){};

    void addElement(int el)
    {
        if (index >= size)
            throw arr_exception("Выход за рамки массива!");
        else
            {
                arr[index] = el;
                index++;
                return;
            }
    }

    int getElement(const int& i)
    {
        if (i >= size)
            throw arr_exception("Выход за рамки массива!");
        else 
            return arr[i];
    }

    ~smart_array()
    {
        delete[] arr;
        arr = nullptr;
    }
};

int main()
{

    try
    {
        smart_array arr(5);
        arr.addElement(1);
        arr.addElement(4);
        arr.addElement(155);
        arr.addElement(14);
        arr.addElement(15);
        std::cout << arr.getElement(1) << std::endl;
    }
    catch (const arr_exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
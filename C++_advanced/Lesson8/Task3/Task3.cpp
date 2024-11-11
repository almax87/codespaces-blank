#include <iostream>

template <class T>
class unique_ptr 
{
    private: 
        T* ptr = nullptr;
    public:
        unique_ptr(T* ptr) : ptr(ptr) {};
        unique_ptr(const unique_ptr<T>& unique_ptr) = delete;
        unique_ptr& operator = (const unique_ptr&) = delete;

        ~unique_ptr()
        {
            delete ptr;
            std::cout << "Destructor called!" << std::endl;
        }

        T operator* ()
        {
            return *this->ptr;
        }

        T* release()
        {
            T* ptr_new = this->ptr;
            this->ptr = nullptr;
            return ptr_new;
        }
};

int main()
{
    unique_ptr<int> unique_ptr(new int(5));
    std::cout << "*unique_ptr = " << *unique_ptr << std::endl;
    std::cout << "release() = " << unique_ptr.release() << std::endl;
    
    return 0;
}
#include <iostream>
#include <exception>
#include <stdexcept>
class arr_exception : public std::runtime_error{
    public:
    arr_exception() : std::runtime_error("Выход за рамки массива!"){}
};
template <class T>
class Matrix 
{
    private:
        int row;
        int col;
        T** matrix = nullptr;

    public:
        Matrix(const int& row, const int& col) : row{row}, col{col}, matrix{new T* [row]} 
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i] = new T[row];
            }
        }

        T getMatrix()
        {
            return matrix;
        }

        T* operator[] (const int& index)
        {
            if ((index < 0)||(index >= row))
                throw arr_exception();
            return matrix[index];
        }

        const T* operator[] (const int& index) const
        {
            if ((index < 0)||(index >= col))
                throw arr_exception();
            return matrix[index];
        }

        void setElement(const int& index_row, const int& index_col, const int& value)
        {
            if ((index_row < 0)||(index_row >= row)||(index_col < 0)||(index_col >= col))
                throw arr_exception();
            matrix[index_row][index_col] = value;
        }

        ~ Matrix()
        {
            for (int i = 0; i < row; i++)
                delete[] matrix[i];
            delete[] matrix;
            matrix = nullptr;
        }
};


int main()
{
    auto test = Matrix<int>(1,2);
    
    try
    {
        test[0][0] = 4;
        std::cout << test[0][0] << std::endl;
    }
        catch (const arr_exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
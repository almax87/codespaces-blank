#include <iostream>
#include <vector>
#include <string>
#include <memory>

class BigInteger
{
    private:
        std::string number{};
    public: 
        BigInteger(const std::string& number) : number(number){}
        BigInteger(const BigInteger& other) : number(std::move(other.number)){}
        BigInteger() : number(){}

        BigInteger& operator= (BigInteger& other) noexcept
        {
            std::swap(this->number, other.number);
            return *this;
        }

        std::string getNumber()
        {
            return this->number;
        }

        BigInteger operator+ (BigInteger& other)
        {
            int digit_sum{};
            int rest{};
            if(other.number.length() > this->number.length())
                *this = other;
            BigInteger res;
            int size2 = other.number.length();
            int size1 = this->number.length();
            res.number.resize(size1 + 1);
            
            for (int i = size1-1; i >= 0; i--)
            {
                if (--size2 >= 0)
                {
                    digit_sum = static_cast<int>(number[i]) - 48 + static_cast<int>(other.number[size2]) - 48 + rest;
                    res.number[i+1] = static_cast<char>(digit_sum%10 + 48);
                    rest = digit_sum/10;
                }
                else
                {
                    digit_sum = number[i] - 48 + rest;
                    res.number[i+1] = static_cast<char>(digit_sum%10 + 48);
                    rest = digit_sum/10;
                }
                if ((i == 0)&&(rest > 0))
                    res.number[i] = static_cast<char>(rest+48);
                else
                    res.number.shrink_to_fit();
            }
            return res;
        }

        BigInteger operator*(BigInteger& other)
        {
            if(other.number.length() > this->number.length())
                *this = other;

            int row = other.number.length();
            int col = number.length() + row + 1;          
            int** matrix = new int*[row];
            for (int i = 0; i < row; i++)
                matrix[i] = new int[col];
            int rest{};
            int digit_mult{};
            int digit_sum{};
            int count{};
            BigInteger result;
            result.number.resize(col + row + 1);
            for (int i = 0; i < row; i++)
            {
                for (int j = number.length() - i; j >= 0; j--)
                {
                    digit_mult = (static_cast<int>(number[j]) - 48)*(static_cast<int>(other.number[i]) - 48) + rest;
                    matrix[i][j] =  digit_mult%10;
                    rest = digit_mult/10;   
                }
            }
            std::cout << std::endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }

            for (int i = row - 1; i >= 0; i--)
            {
                for (int j = 0; j < col; j++)
                {
                    digit_sum += matrix[i][j] + rest;
                }
                result.number[i] = digit_sum%10;
                rest = digit_sum/10;
            }

            return result;
        }

        void print()
        {
            for (auto&i : this->number)
                std::cout << i;
        }
};

int main()
{
    auto number1 = BigInteger("555");
    auto number2 = BigInteger("23");
    auto result1 = number1 + number2;
    auto result2 = number1*number2;
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}
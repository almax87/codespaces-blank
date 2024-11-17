#include <iostream>
#include <vector>
#include <string>
#include <memory>

std::string operator+(std::string& lhs, std::string& rhs)
    {
        if(rhs.length() < lhs.length())
            std::swap (rhs, lhs);
        std::string sum{};
        auto i = rhs.rbegin();
        auto j = lhs.rbegin();
        int digit_sum{};
        int rest{};
        while (i < rhs.rend())
        {
            if (j < lhs.rend())
            {
                digit_sum = static_cast<int>(*i) - 48 + static_cast<int>(*j) - 48 + rest;
                j++;
            }
            else
            {
                digit_sum = static_cast<int>(*i) - 48 + rest;  
            }
            sum.insert(sum.begin(),static_cast<char>(digit_sum%10 + 48));
            rest = digit_sum/10;
            ++i; 
            if((i == rhs.rend())&&(rest > 0))
                sum.insert(sum.begin(),static_cast<char>(rest+48));            
        }
        return sum;
    }
std::string operator*(std::string& lhs, int rhs)
{
    std::string mult{};
    auto i = lhs.rbegin();
    int digit_mult{};
    int rest{};
    while (i < lhs.rend())
    {
        digit_mult = (static_cast<int>(*i)- 48)*rhs + rest;
        mult.insert(mult.begin(),static_cast<char>(digit_mult%10 + 48));
        rest = digit_mult/10;
        ++i;
        if((i == lhs.rend())&&(rest > 0))
                mult.insert(mult.begin(),static_cast<char>(rest+48)); 
    }
    return mult;
}

class BigInteger
{
    private:
        std::string number{};
    public: 
        BigInteger(std::string number) : number(number){}
        BigInteger(const BigInteger& other) : number(std::move(other.number)){}
        BigInteger() : number(){}


        BigInteger& operator= (BigInteger& other)
        {
            std::swap(this->number, other.number);
            return *this;
        }

        BigInteger operator+ (BigInteger& other)
        { 
            BigInteger sum (this->number + other.number);   
            return sum;
        }

        BigInteger operator* (BigInteger& other)
        {
            BigInteger mult;
            if (other.number.length() > this->number.length())
                *this = other;
            auto i = number.rbegin();
            auto j = other.number.rbegin();
            std::vector <std::string> matrix{};
            int count{};


            while (j < other.number.rend())
            {
                matrix.insert(matrix.begin(), number*(static_cast<int>(*j - 48)));
                j++;
            }

            auto z = matrix.rbegin();
            while (z < matrix.rend())
            {
                for (int i = 0; i < count; i++)
                    z->push_back('0');
                z++;
                count++;
            }

            std::cout << std::endl;

            for (auto i : matrix)
            {
                std::cout << i << std::endl;
            }

            std::cout << std::endl;


            for (auto i : matrix)
            {
                mult.number = mult.number + i;
            }

            return mult;         
        }

        void print() const
        {
            for (auto&i : this->number)
                std::cout << i << " ";
            std::cout << std::endl;
        }
};
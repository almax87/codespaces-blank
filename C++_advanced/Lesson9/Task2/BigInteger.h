#include <iostream>
#include <vector>
#include <string>
#include <memory>

std::string sum(std::string& lhs, std::string& rhs)
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

std::string multiply(std::string& lhs, std::string& rhs)
{
    std::string mult{};

    if (lhs.length() < rhs.length())
        std::swap(lhs,rhs);

    int digit_mult{};
    int rest{};
    std::vector <std::string> matrix;
 
    for (auto j = rhs.rbegin(); j < rhs.rend(); j++)
    {
        for (auto i = lhs.rbegin(); i < lhs.rend(); i++)
        {
            digit_mult = (static_cast<int>(*i)- 48)*(static_cast<int>(*j)-48) + rest;
            mult.insert(mult.begin(),static_cast<char>(digit_mult%10 + 48));
            rest = digit_mult/10;
            if((i == lhs.rend() - 1)&&(rest > 0))
                mult.insert(mult.begin(),static_cast<char>(rest+48)); 
        }
        matrix.insert(matrix.begin(),mult);
        mult.clear();
        rest = 0;
    }

    auto z = matrix.rbegin();
    int count{};
    while (z < matrix.rend())
    {
        for (int i = 0; i < count; i++)
            z->push_back('0');
        z++;
        count++;
    }

    for (auto i : matrix)
    {
        mult = sum(mult, i);
    }

    return mult;
}

class BigInteger
{
    private:
        std::string number{};
    public: 
        BigInteger(std::string str) : number(str){}
        BigInteger(const BigInteger& other) : number(std::move(other.number)){}
        BigInteger() : number(){}


        BigInteger& operator= (BigInteger& other)
        {
            std::swap(this->number, other.number);
            return *this;
        }

        BigInteger operator+ (BigInteger& other)
        { 
            BigInteger result (sum(this->number, other.number));   
            return result;
        }

        BigInteger operator* (BigInteger& other)
        {
            BigInteger mult (multiply(this->number, other.number));
            return mult;         
        }

        BigInteger operator*(int a)
        {
            std::string number_str = std::to_string(a);
            BigInteger mult (multiply(this->number, number_str));
            return mult;
        }

        void print() const
        {
            for (auto&i : this->number)
                std::cout << i;
            std::cout << std::endl;
        }
};
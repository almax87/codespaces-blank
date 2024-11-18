#include "BigInteger.h"

int main()
{
    auto number1 = BigInteger("9999");
    auto number2 = BigInteger("1234");
    BigInteger result1 = (number1 + number2);
    result1.print();
    BigInteger result2 = number1*number2;
    result2.print();
    BigInteger result3 = number1*1234;
    result3.print();

    return 0;
}
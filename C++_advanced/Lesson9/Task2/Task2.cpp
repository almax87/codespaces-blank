#include "BigInteger.h"

int main()
{
    auto number1 = BigInteger("9999");
    auto number2 = BigInteger("9339");
    BigInteger result1 = (number1 + number2);
    result1.print();
    BigInteger result2 = number1*number2;
    result2.print();

    return 0;
}
#include <iostream>

#include "Parser.h"
#include "Section.h"
#include "Support.h"
#include "Parser_except.h"

int main()
{
    IniParser parser("file.ini");
    parser.set_section();
    auto val = parser.get_value<int>("Section1.var1");
    std::cout << val << std::endl;

   return 0;
}
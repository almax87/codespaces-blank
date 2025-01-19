#include <iostream>
#include "lib/Parser.h"
#include "lib/Section.h"
#include "lib/Support.h"
#include "lib/Parser_except.h" 

int main()
{
    IniParser parser("file.ini");
    parser.set_section();
    auto val = parser.get_value<std::string>("Section2.var2");
    std::cout << val << std::endl;

   return 0;
}
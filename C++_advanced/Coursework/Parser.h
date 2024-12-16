#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "Section.h"
#include "Support.h"
#include "Parser_except.h"

class IniParser
{
    private:
        std::string filename{};
        std::ifstream file;
        std::vector <std::string> table{};
        std::map <std::string, Section> section_list{};

    public:
        IniParser(const std::string& input_file);
        std::string parse_input(const std::string& input);
        void set_section();

        template <typename T>
        T get_value (const std::string& input);
};
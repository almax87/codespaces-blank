#pragma once
#include "Parser.h"

class Section
{
    private:
        std::map <std::string, std::string> value_list{};

    public:
        std::map <std::string, std::string> get_value_list() 
        {
            return value_list;
        }

        void set_value_list(const std::string& val_name, const std::string& val) 
        {
            if(!value_list.try_emplace(val_name, val).second)
            {
                for (auto it : value_list)
                {
                    if (it.first == val_name)
                    {
                        it.second = val;
                    }
                }
            }
        }

        void print_value_list()
        {
            for (auto it : get_value_list())
            {
                std::cout << it.first << "\t";
            }
            std::cout << std::endl;
        }
};
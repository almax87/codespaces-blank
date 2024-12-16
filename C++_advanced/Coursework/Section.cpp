
#include "Section.h"
#include <map>
#include <string>

std::map <std::string, std::string> Section::get_value_list() 
{
    return value_list;
}

void Section::set_value_list(const std::string& val_name, const std::string& val) 
{
    if(!value_list.try_emplace(val_name, val).second)
    {
        for (auto& it : value_list)
        {
            if (it.first == val_name)
            {
                it.second = val;
            }
        }
    }
}
#include "Support.h"
#include <string>

std::string remove_spaces(std::string& str_)
{
    while ((str_.size() > 0)&&((*str_.begin() == ' ') || (str_.at(str_.size() - 1) == ' ')))
    {
        if (*str_.begin() == ' ')
            str_.erase(str_.begin());
        else
            str_.erase(str_.size() - 1);
    }
    return str_;
}
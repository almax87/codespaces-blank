#pragma once
#include <map>
#include <string>

class Section
{
    private:
        std::map <std::string, std::string> value_list{};

    public:
        std::map <std::string, std::string> get_value_list();
        void set_value_list(const std::string& val_name, const std::string& val);
};
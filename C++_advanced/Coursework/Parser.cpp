#include <iterator>
#include <cctype>

#include "Parser.h" 

IniParser::IniParser(const std::string& input_file)
{
    file.open(input_file);
    std::string str;  
    while (!file.eof())
        {
            getline(file, str);
            if (!str.empty())
                table.push_back(str);
        }
    file.close();
}
 
void IniParser::set_section()
{
    std::string val_name;
    std::string val;
    std::string key{};
    for (auto i = table.begin(); i < table.end(); i++)
    {
        remove_spaces(*i);
        if ((*begin(*i) == '[') && (*(end(*i) - 1)) == ']')
        {
            Section section;  
            i->erase(begin(*i));
            i->erase(end(*i) - 1);
            if(section_list.try_emplace(*i, section).second)
                key = *i;
            else
                for (auto it : section_list)
                {
                    if (it.first == *i)
                        key = it.first;
                }
        }
            while (*i->begin() != '[')
                {
                    if (i->find("=") != std::string::npos)
                        {
                            val_name = i->substr(0, i->find("="));
                            remove_spaces(val_name);
                            val = i->substr(i->find('=') + 1, (i->find(';') - i->find('=') - 1));
                            remove_spaces(val);
                            section_list[key].set_value_list(val_name, val);
                            break;
                        }
                    else
                        break;
                }
    }
}

std::string IniParser::parse_input(const std::string& input)
{
    std::string sec{}, val_name{}, val{};
    bool sec_found{}, val_found{};

    if (input.find(".") != std::string::npos)
    {
        sec = input.substr(0, input.find("."));
        remove_spaces(sec);
        val_name = input.substr(input.find('.') + 1, (input.size() - input.find('.') - 1));
        val_name = remove_spaces(val_name);
        for (auto& it : section_list)
        {
            if (sec == it.first)
            {
                sec_found = true;
                for (auto& it2 : it.second.get_value_list())
                {
                    if (it2.first == val_name)
                    {
                        val_found = true;
                        val =  it2.second;
                        break;
                    }
                }
            }
        }
        if (!sec_found)
            throw no_sec_except();
        if (!val_found)
            throw no_var_except();
    }
    else
    {
        throw std::runtime_error("Wrong syntax!!!");
    }
    return val;
}

template <typename T>
T IniParser::get_value (const std::string& input)
{
    static_assert(sizeof(T) == -1, "not implemented type for get_value");
}

template <>
std::string IniParser::get_value(const std::string& input)
{
    return IniParser::parse_input(input);
}

template <>
int IniParser::get_value (const std::string& input)
{
    return std::stoi(IniParser::parse_input(input));
}

template <>
double IniParser::get_value (const std::string& input)
{
    return std::stod(IniParser::parse_input(input));
}
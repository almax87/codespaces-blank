#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <exception>
#include <stdexcept>
#include <cctype>
#include "Section.h"
#include "support.h"
#include "Parser_except.h"

class IniParser
{
    public:
        std::string filename{};
        std::ifstream file;
        std::vector <std::string> table{};
        std::map <std::string, Section> section_list{};

  void set_section()
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
                                val = remove_spaces(val);
                                section_list[key].set_value_list(val_name, val);
                                break;
                            }
                        else
                            break;
                    }
        }
    }    

    IniParser(const std::string& input_file)
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

    std::string parse_input(std::string& input)
    {
        std::string sec{}, val_name{}, val{};

            if (input.find(".") != std::string::npos)
            {
                sec = input.substr(0, input.find("."));
                remove_spaces(sec);
                val_name = input.substr(input.find('.') + 1, (input.size() - input.find('.') - 1));
                val_name = remove_spaces(val_name);
                for (auto it : section_list)
                {
                    if (sec == it.first)
                    {
                        for (auto it2 : it.second.get_value_list())
                        {
                            if (it2.first == val_name)
                            {
                                val =  it2.second;
                            }
                            else
                            {
                                throw no_var_except();
                            }
                        }
                    }
                    else
                    {
                        throw std::runtime_error("No section found!");
                    }
                }
            }
            else
            {
                throw std::runtime_error("Wrong syntax!!!");
            }
            return val;
    }

    int get_type(std::string str)
    {
        std::string val = parse_input(str);
        char type = 1;
        int count{};
        for (auto i : val)
        {
            if (isdigit(i))
            {
                
                continue;
            }
            else
            {
                if (i == '.')
                {
                    count++;
                    if (count <= 1)
                        {
                            type = 2;
                            continue;
                        }
                    else
                        {
                            type = 3;
                            break;
                        }
                }
                type = 3;
                break;
            }
        }
        return type;
    }   
};

template <typename T>
class get_val : public IniParser{};

template<>
class get_val<int> : public IniParser
{
    public:
    int get_value (std::string& input)
    {
        if(get_type(parse_input(input)) == 1)
            return stoi(parse_input(input));
        else
            throw std::runtime_error("Value is not integer");
    }
};

template<>
class get_val<double> : public IniParser
{
    public:
    double get_value (std::string& input)
    {
        if(get_type(parse_input(input)) == 1)
            return stod(parse_input(input));
        else
            throw std::runtime_error("Value is not integeer");
    }
};

template<>
class get_val<std::string> : public IniParser
{
    public:
    std::string get_value (std::string& input)
    {
        return parse_input(input);
    }
};

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <exception>
#include <stdexcept>

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

class Section
{
    private:
        std::string section_name{};
        std::map <std::string, std::string> value_list{};

    public:
        std::vector <std::string> comment_list{};

        Section(const std::string& sec_name_) : section_name(sec_name_){}

        void set_value(const std::string& val_name, const std::string& value)
        {
            for (auto i : value_list)
            {
                if (i.first == val_name)
                    i.second = value;
                else
                    continue;
            }
            value_list.insert(value_list.end(), std::pair<std::string, std::string>(val_name, value));
        }

        std::string get_name() const
        {
            return section_name;
        }

        std::map <std::string, std::string> get_value_list() const
        {
            return value_list;
        }
};

template <class T>
class get
{
    public:

    T get_value(const std::string& input)
    {
        if (input.find(".") != std::string::npos)
        {
            std::string val_name = input.substr(0, input.find("."));
            remove_spaces(val_name);
            std::string val = input.substr(input.find('.') + 1, (input.size() - input.find('.') - 1));
            val = remove_spaces(val);
        }
        else
        {
            throw std::runtime_error("Wrong syntax!!!");
        }

    };
};

class IniParser : public get<int>
{
    public:
        std::string filename{};
        std::ifstream file;
        std::vector <std::string> table{};
        std::vector <Section> section_list{};

    bool find_index(const std::string& sec_name_, int& i)
    {
        for (int i = 0; i < section_list.size() - 1; i++)
        {
            if(section_list[i].get_name() == sec_name_)
                return 1;
            else
                return 0;
        };
        return 0;
    }

  void set_section()
    {
        std::string val_name;
        std::string val;
        int index{};
        for (auto i = table.begin(); i < table.end(); i++)
        {
            if ((*begin(*i) == '[') && (*(end(*i) - 1)) == ']')
            {
                i->erase(begin(*i));
                i->erase(end(*i) - 1);
                if (section_list.empty())
                    {
                        Section section(*i);
                        section_list.push_back(section);
                    }
                else
                    {
                        if (find_index(*i, index))
                        {
                            break;
                        }
                        else
                        {
                            Section section(*i);
                            section_list.push_back(section);
                            index = section_list.size() - 1;
                        }
                    }
                continue;
            }
                while (*i->begin() != '[')
                    {
                        if (i->find("=") != std::string::npos)
                            {
                                val_name = i->substr(0, i->find("="));
                                remove_spaces(val_name);
                                val = i->substr(i->find('=') + 1, (i->find(';') - i->find('=') - 1));
                                val = remove_spaces(val);
                                section_list[index].set_value(val_name, val);
                                break;
                            }
                        else
                            break;
                    }
        }
    }       

    IniParser(std::string filename)
    {
        file.open(filename);
        int str_num{};
        std::string str;  
        while (!file.eof())
            {
                getline(file, str);
                if (!str.empty())
                    table.push_back(str);
            }
        file.close();
    }

    void print()
    {
        for (auto i : section_list)
        {
            std::cout << i.get_name() << std::endl;
        }
    }

};

int main()
{
    IniParser parser("file.ini");
    parser.set_section();
    parser.get_value("section1.val1");
    parser.print();

   return 0;
}
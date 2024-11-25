#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

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
            value_list.insert(value_list.begin(), std::pair<std::string, U>(val_name, value));
        }

        std::string& get_name() const
        {
            return section_name;
        }

};


class IniParser
{
    public:
        std::string filename{};
        std::ifstream file;
        std::map <int, std::string> table{};
        std::vector <Section> section_list{};
        

    IniParser(std::string filename)
    {
        file.open(filename);
        auto i = table.begin();
        int str_num{};
        std::string str;
        
        while (!file.eof())
            {
                getline(file, str);
                auto j = str.begin();
                auto z = str.end();
                table.insert(table.end(), std::pair<int, std::string>(++str_num, str));
                
                if ((*str.begin() == '[') && (*str.end() == ']'))
                    {
                        Section section(str);
                        str.erase(j);
                        str.erase(z);
                        section_list.push_back(section);
                        do
                        {
                            getline(file,str);
                                if (str.find("=") != std::string::npos)
                                {
                                    section.set_value(str.substr(0, str.find("=")), str.substr(str.find("=") + 1, str.end() - str.find("=")));

                                }

                        }while (*str.begin() != '[');
                    }
                
                str.clear();

            }
    };

    void print ()
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
    parser.print();

   return 0;
}
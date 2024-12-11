#pragma once
#include "Parser.h"
#include "Section.h"

class no_var_except : public std::runtime_error
{
    private:
        std::string message{"No variable found"};
    public:
        no_var_except() : std::runtime_error(this->message)
        {
            std::cout << get_message() << std::endl;
        }

        std::string get_message()
        {
            return message;
        }
};
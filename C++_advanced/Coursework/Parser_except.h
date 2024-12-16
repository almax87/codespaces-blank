#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>

class no_var_except : public std::runtime_error
{
    public:
        no_var_except() : std::runtime_error("No var found")
        {
            std::cout << what() << std::endl;
        }
};

class no_sec_except : public std::runtime_error
{
    public:
        no_sec_except() : std::runtime_error("No section found")
        {
            std::cout << what() << std::endl;
        }
};

class syntax_except : public std::runtime_error
{
    public:
        syntax_except() : std::runtime_error("Wrong syntax!!!")
        {
            std::cout << what() << std::endl;
        }
};
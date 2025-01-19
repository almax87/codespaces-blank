cmake_minimum_required(VERSION 3.30)
project(sub_IniParser)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_library(IniParser_dynamic_lib Parser.h Parser.cpp Section.h Section.cpp Support.h Support.cpp Parser_except.h)
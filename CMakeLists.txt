cmake_minimum_required(VERSION 3.28)
project(K__)

set(CMAKE_CXX_STANDARD 20)

add_executable(K__ main.cpp
        lexer/Bor.hpp
        lexer/TokenTypeEnum.hpp
        lexer/LexerImplementation.hpp
        lexer/TokenImplementation.hpp
)
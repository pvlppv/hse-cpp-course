////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Some functions for dealing with strings".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>

int main()
{
    // c strings
    char str1[] = "abcd", str2[] = "abCd";
    std::cout << strcmp(str1, str2) << std::endl;
    char str3[3];
    std::cin >> str3;
    std::cout << strlen(str3) << std::endl;

    // c++ strings
    std::string str4;
    std::cin >> str4;
    std::cout << str4.size() << str4.length() << std::endl;
    std::string str5 = "One";
    std::string str6 = "Two";
    bool operator1 = str5 < str6;
    std::string operator2 = str5 + str6;
    std::cout << operator1 << " " << operator2 << std::endl;
    str5 = str6;

    return 0;
}

#pragma once

#include "vector"
#include "boost/algorithm/string.hpp"
#include "regex"
#include <exception>
#include <iostream>
#include "windows.h"


class MyAux {
public:
    static std::vector<std::vector<std::string>> read(std::istream &is);

    static void checkOfEmpty(const std::string &str);

    static void repairArr(std::vector<std::string> &arr);

    static int toInteger(const std::string &str);

    static int toBool(const std::string &str);

    static void printException(std::exception& ex);
};
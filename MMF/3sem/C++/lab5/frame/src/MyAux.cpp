#include "../include/MyAux.h"


void MyAux::checkOfEmpty(const std::string &str) {
    std::regex regex("^\\s*$");
    if (std::regex_match(str, regex))
        throw new std::invalid_argument("line is empty");
}

void MyAux::repairArr(std::vector<std::string> &arr) {
    for(size_t i(0);i<arr.size();i++)
        if(arr[i].empty())
            arr.erase(arr.begin()+i--);
}

int MyAux::toInteger(const std::string &str) {
    return atoi(str.c_str());
}

int MyAux::toBool(const std::string &str) {
    return (bool)toInteger(str);
}

void MyAux::printException(std::exception &ex) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
    std::cerr << ex.what() << std::endl;
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE);
}

std::vector<std::vector<std::string>> MyAux::read(std::istream &is) {
    std::vector<std::vector<std::string>> matrix;
    size_t size = 0;
    while (is.good()) {
        std::string str;
        getline(is, str);
        try {
            checkOfEmpty(str);
            std::vector<std::string> arr;
            boost::split(arr, str, boost::is_any_of(" "));
            repairArr(arr);
            if (size == 0)
                size = arr.size();
            if (size != arr.size())
                throw std::logic_error("invalid input data");
            matrix.push_back(arr);
        }
        catch (std::invalid_argument &ex) {
            printException(ex);
        }
    }
    return matrix;
}
#include <fstream>
#include "../frame/include/matrix/BoolMatrix.h"


void checkOpen(const std::ios& ios) {
    if (!ios.good())
        throw std::exception();
}

std::string operation(const char* operation) {
    std::string str = "\nmatrix 1 ";
    str += operation;
    return str + " matrix 2:\n";
}


int main(int argc, char* argv[]) {
    std::string BaseDir = "C:\\Projects\\MMF\\3sem\\C++\\lab5\\resources\\", in = "input\\", out = "output\\output.txt",
            bool1 = in + "boolMatrixOne.txt", bool2 = in + "boolMatrixTwo.txt", num1 =
            in + "numericMatrixOne.txt", num2 = in + "numericMatrixTwo.txt";
    try {
        std::ifstream fin(BaseDir + bool1);
        checkOpen(fin);
        BoolMatrix a, b;
        fin >> a;
        fin.close();
        fin.open(BaseDir + bool2);
        checkOpen(fin);
        fin >> b;
        fin.close();

        std::ofstream fout(BaseDir + out);
        checkOpen(fout);
        fout << "matrix 1:\n" << a << std::endl;
        fout << "\nmatrix 2:\n" << b << std::endl;
        fout << "\nthe number of units in matrix 1: " << a.numberOfUnits() << std::endl;
        fout << operation("&") << (a & b) << std::endl;
        fout << operation("|") << (a | b) << std::endl;
        fout << operation("^") << (a ^ b) << std::endl;
        fout << operation("*") << (a * b) << std::endl;
        fout << "\nalphacanonical of matrix 1:\n" << a.alphaCanonical() << std::endl;
        fout.close();
    }
    catch (std::exception &ex) {
        MyAux::printException(ex);
    }
    return 0;
}

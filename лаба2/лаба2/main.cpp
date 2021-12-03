#include "Matrix.h"

using namespace std;

int main(int argc, char** argv)
{

    Matrix<int> matrix(3);
    matrix.input_matrix();
    matrix.print_matrix();

    Matrix<int> matrix2(99999999);
    Matrix<int> matrix3(0);
}
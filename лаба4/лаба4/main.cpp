#include <iostream>
#include <cmath>
#include <clocale>
#include "Polinom.h"

int main()
{
    setlocale(LC_ALL, "rus");
    Polinom objPolinom;

    int n1, hlobal1;
    std::cout << "������� �������� ������� ������� ��������:\n";
    std::cin >> n1;
    if (n1 > 9) {
        std::cout << "������!!!! ������� ������� �������";
        exit(-1);
    }
    objPolinom.koef1(n1);
}
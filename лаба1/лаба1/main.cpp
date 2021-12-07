#include <iostream>
#include "tbitfield.h"
#include "tset.h"
#include <iomanip>
#include <conio.h>

int main(int argc, char* argv[])
{

	TSet obj1(12);
	obj1.print_array();

	TSet obj2(14);
	obj1.print_array();

	TSet obj3 = obj2;
	obj3.print_array();

	TSet obj5(5);
	cout<<(obj5<<5);//sdvig 5

	if (obj3 == obj2) std::printf("true");
	else std::printf("false");

	if (obj3 == obj1) std::printf("true");
	else std::printf("false");
	if (obj1 == obj2) std::printf("true");
	else std::printf("false");
	TBitField  Elem1(12); 
    Elem1.print_array();   
	system("pause");
	return 0;
};

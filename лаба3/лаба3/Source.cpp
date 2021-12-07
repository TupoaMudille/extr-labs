#include <iostream>
#include <string>
#include "Postfix.h"
using namespace std;
//THIS IS MAIN

int main()
{
	string formula;
	double res;
	Postfix postfix;
	setlocale(LC_ALL, "Russian");
	cout << "Ваше выражение: ";
	cin >> formula;
	postfix.put_infix(formula);
	if (postfix.check())
	{
		cout << "Инфикс: " << postfix.get_infix()<< endl;
		postfix.save_inti_stek();
		cout << "Постфикс: " << postfix.get_postfix() << endl;
		res = postfix.get_result();
		cout << "Результат: " << res << endl;
	}
	return 0;
}

#include <string>
#include "Stack.h"
#include <iostream>
using namespace std;

class Postfix
{
private:
	string infix;		
	string postfix;	
	string* operations;
	char* prioritet;   
public:
	Postfix();  
	~Postfix();			  
	void put_infix(string& str) { infix = str; };
	string get_postfix();					  
	string get_infix();						  
	int operation(string& str, int& i);    
	int prioritet_operation(string& str); 
	bool check();      
	void save_inti_stek();    
	double get_result();   
};

Postfix::Postfix()
{
	infix = " ";
	postfix = "null";
	operations = new string[9];
	prioritet = new char[9];
	operations[0] = '+'; prioritet[0] = 1;
	operations[1] = '-'; prioritet[1] = 1;
	operations[2] = '*'; prioritet[3] = 2;
	operations[3] = '/'; prioritet[3] = 2;
}

Postfix::~Postfix()
{
	delete[]operations;
	delete[]prioritet;
}

string Postfix::get_postfix()
{
	return postfix;
}

string Postfix::get_infix()
{

	return infix;
}

int Postfix::prioritet_operation(string& str)
{
	int i = 0;
	while (str != operations[i])
		i++;
	return prioritet[i];
}

int Postfix::operation(string& str, int& i)
{
	for (int j = 0; j < 8; j++)
		if (str[i] == operations[j][0])
		{
			if (str[i] = operations[j][0])
				return j;
		}
	return -1;
}

bool Postfix::check()
{

	string Str = infix;  //инфикс
	setlocale(LC_ALL, "Russian");
	string Str1; 
	double tmp;
	char* Str2;
	int i, j, k, l, check;
	char nowElem;        //сейчашний элем строки
	int operation_index_i;    //номер первой операции
	int operation_index_j;   //номер второй операции
	int size = Str.size();  //размер инфикса



	for (i = 0; i < size; i++)
	{
		nowElem = Str[i];  //сейчашний элем
		if (!(((nowElem > 41) && (nowElem < 58)) ))   //ловля исключения симв
		{
			cout << "Ошибка!!!!!!Допустимые символы '.', ',', '0-9', '+' , '-' , '*' , '/' " << endl;
			return 0;
		}
		if (nowElem == 46)   //тчк меняем на зпт
			Str[i] = ',';
	}
	infix = Str; //инфикс с зпт
	operation_index_i = operation(Str, i = 0);  //номер первого символа
	for (i = 0; i < size; i++)
	{
		operation_index_i = operation(Str, i);
		if (operation_index_i != -1)
		{
			operation_index_j = operation(Str, j = i + 1);
			if (operation_index_i < 4)

			{
				if ((operation_index_j > -1) && (operation_index_j < 4) && (operation_index_j != 1))
				{
					cout << "Ошибка!!!!! в записи выражения" << endl;
					return 0;
				}
				if (((operation_index_j < 4) && (operation_index_j > -1) && (operation_index_j != 4) || (Str[i + 1] == 0)))
				{
					cout << "Ошибка!!!!! в записи выражения" << endl;
					return 0;
				}
				continue;
			}
		}
			else
			{
				k = 0;
				l = i;
				do
				{
					k++;
					l++;
					operation_index_i = operation(Str, l);
					if (l == size)
						break;
				} while (operation_index_i == -1);
				Str1 = Str.substr(i, k);
				Str2 = new char[Str1.size() + 1];
				for (j = 0; j < Str1.size() + 1; j++)
					Str2[j] = Str1[j];
				tmp = strtod(Str2, NULL);
				i = i + k - 1;
			}
		return 1;
	}
}

void Postfix::save_inti_stek()
{
	string sign = infix; //
	Stack <string> operation1; //стэк операций
	string str, output, operationstek;
	int size = infix.size(), operationIndex, k, l, j;


	for (int i = 0; i < size; i++) //идем до конца инфикса
	{

		operationIndex = operation(sign, i); 
		if (operationIndex == -1)
		{
			k = 0;
			l = i;
			do
			{
				l++;
				k++;
				if (l == size) 
					break;
				operationIndex = operation(sign, l); 


			} while (operationIndex == -1);
			output += sign.substr(i, k) + " "; 
			i = i + k - 1;

		}
		else  
		{
			
			if (operation1.empty()) //если стек пустой
			{
				operation1.push(operations[operationIndex]); 
				continue;
			}

			operationstek = operation1.watch_top_stek(); 
			str = operations[operationIndex];
			if (operationstek == str)
			{
				operation1.push(str);
				continue;
			}

			if (prioritet_operation(str) <= prioritet_operation(operationstek)) 
				operation1.push(str);
			else
			{
				while (prioritet_operation(str) >= prioritet_operation(operationstek) && !(operation1.empty())) 
				{
					output += operation1.pop();
					if (operation1.empty())
					{
						continue;
					}
					operationstek = operation1.watch_top_stek();
				}
				operation1.push(str);
			}
		}
	}
	while (!operation1.empty())
		output += operation1.pop();
	postfix = output;
}

double Postfix::get_result()
{
	if (postfix == "null") //если постфикс еще не создавали
	{
		cout << "Постфикс еще не создан" << endl; 
		return 0;
	}
	int OperationIndex; 
	Stack <double> stack; 
	string str;
	double tmp, ch1, ch2;
	int k, size = postfix.size();

	int i = 0;
	while (i < size)
	{
		OperationIndex = operation(postfix, i); 
		if (OperationIndex == -1)
		{
			k = 0;
			do
			{
				k++;
				if (i + k == size)
					break;
			} while (postfix[i + k] != ' ');
			str = postfix.substr(i, k);
			tmp = atof(str.c_str());
			i = i + k;
			stack.push(tmp);
			i++;
			continue;
		}
		else
		{

			ch1 = stack.pop();
			ch2 = stack.pop();
			switch (OperationIndex)
			{
			case 0:
			{
				ch1 += ch2;
				stack.push(ch1);
				i++;
				break;
			}
			case 1:
			{

				ch1 = ch2 - ch1;
				stack.push(ch1);
				i++;
				break;
			}
			case 2:
			{
				ch1 *= ch2;
				stack.push(ch1);
				i++;
				break;
			}
			case 3:
			{
				if (ch1 == 0)
				{
					cout << "Ошибка!!!!!!!!!На ноль не делят" << endl;
					return 0;
				}
				ch1 = ch2 / ch1;
				stack.push(ch1);
				i++;
				break;
			}
			}
		}
	}
	return stack.pop();
}
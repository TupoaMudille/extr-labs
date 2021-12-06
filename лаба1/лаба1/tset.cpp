#include "tset.h"
#pragma once
TSet::TSet(int mp) :MaxPower(mp), BitField(mp)
{
	BitField = TBitField(mp);
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField)
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
}

void  TSet::print_array()
{
	BitField.print_array();
}

TSet& TSet::operator=(const TSet& s) // присваивание
{
	this->BitField = s.BitField;
	this->MaxPower = s.GetMaxPower();
	return *this;
}

int TSet::GetMaxPower(void) const// получить макс. к-во эл-тов
{
	return MaxPower;
}

TSet::operator TBitField()
{
	std::printf("\noperator TBitField()");
	return (TBitField)*this;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n 
{

	if ((n < 0) || (n >= _razmer))
		throw "incorrect data";
	return int(n / (sizeof(TELEM) * 8));

}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n  
{

	if ((n < 0) || (n >= _razmer))
		throw "incorrect data";
	return 1 << (n % (8 * sizeof(TELEM) - 1));

}

TSet TSet::operator<<(int k) //сдвиг битов влево
{
	this->BitField = BitField << k;
	return *this;

}


bool TSet::operator==(const TSet& s) // сравнение
{

	return  (BitField == s.BitField);
}


// конструктор преобразования типа

TSet::TSet(const TBitField& bf)
{
	TSet(bf.GetLength());
}



int TSet::IsMember(int Elem) const // элемент множества?
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции





int TSet::operator!=(const TSet& s) // сравнение
{
	return BitField != s.BitField;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	int len = MaxPower;
	if (s.MaxPower > MaxPower)
	{
		len = s.MaxPower;
	}
	TSet temp(len);

	temp.BitField = BitField | s.BitField;
	return temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}

	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}

	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	int len = MaxPower;
	if (s.MaxPower > MaxPower)
	{
		len = s.MaxPower;
	}
	TSet temp(len);
	temp = BitField & s.BitField;
	return temp;
}

TSet TSet::operator~(void) // дополнение
{
	BitField = ~BitField;
	return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	int temp;
	char ch;
	do { istr >> ch; } while (ch != '{');
	do {
		istr >> temp;
		s.InsElem(temp);
		do { istr >> ch; } while ((ch != ',') && (ch != '}'));
	} while (ch != '}');
	return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
	int i, n; char ch = ' ';
	ostr << "{";
	n = s.GetMaxPower();
	for (i = 0; i < n; i++) {
		if (s.IsMember(i)) {
			ostr << ch << ' ' << i;
			ch = ',';
		}
	}
	ostr << " }";
	return ostr;
}
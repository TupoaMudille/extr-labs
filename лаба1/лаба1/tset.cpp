#include "tset.h"
#pragma once
TSet::TSet(int mp) :MaxPower(mp), BitField(mp)
{
	BitField = TBitField(mp);
	MaxPower = mp;
}

// copy
TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField)
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
}

void  TSet::print_array()
{
	BitField.print_array();
}

TSet& TSet::operator=(const TSet& s) // prisvoit
{
	this->BitField = s.BitField;
	this->MaxPower = s.GetMaxPower();
	return *this;
}

int TSet::GetMaxPower(void) const// get max count elem
{
	return MaxPower;
}

TSet::operator TBitField()
{
	std::printf("\noperator TBitField()");
	return (TBitField)*this;
}

int TBitField::GetMemIndex(const int n) const // index mem for bit n
{

	if ((n < 0) || (n >= _razmer))
		throw "incorrect data";
	return int(n / (sizeof(TELEM) * 8));

}

TELEM TBitField::GetMemMask(const int n) const // bit mask for bit n  
{

	if ((n < 0) || (n >= _razmer))
		throw "incorrect data";
	return 1 << (n % (8 * sizeof(TELEM) - 1));

}

TSet TSet::operator<<(int k) //sdvig left
{
	this->BitField = BitField << k;
	return *this;

}


bool TSet::operator==(const TSet& s) // if ravno
{

	return  (BitField == s.BitField);
}


// type converter

TSet::TSet(const TBitField& bf)
{
	TSet(bf.GetLength());
}



int TSet::IsMember(int Elem) const // elem in?
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // elem in
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // throw elem
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}
	BitField.ClrBit(Elem);
}






int TSet::operator!=(const TSet& s) // if ne ravno
{
	return BitField != s.BitField;
}

TSet TSet::operator+(const TSet &s) // with
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

TSet TSet::operator+(const int Elem) // with elem
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}

	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // razn with elem
{
	if (Elem < 0 || Elem >= MaxPower)
	{
		throw std::logic_error("INCORRECT ELEMENT");
	}

	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet &s) // has same something
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

TSet TSet::operator~(void) // inventor
{
	BitField = ~BitField;
	return *this;
}

// input-output

istream &operator>>(istream &istr, TSet &s) // input
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

ostream& operator<<(ostream& ostr, const TSet& s) // output
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

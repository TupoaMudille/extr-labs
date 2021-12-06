#pragma once
#include "tbitfield.h"

class TSet
{
private:
	int MaxPower;       // ������������ �������� ���������
	TBitField BitField; // ������� ���� ��� �������� ������������������� �������

public:
	TSet(int mp);
	TSet(const TSet& s);       // ����������� �����������
	TSet(const TBitField& bf); // ����������� �������������� ����
	operator TBitField();      // �������������� ���� � �������� ����
	// ������ � �����

	void print_array();

	int GetMaxPower(void) const;     // ������������ �������� ���������
	void InsElem(const int Elem);       // �������� ������� � ���������
	void DelElem(const int Elem);       // ������� ������� �� ���������
	int IsMember(int Elem) const; // ��������� ������� �������� � ���������
	TSet operator<<(int k); //����� ����� �����

	bool operator== (const TSet& s); // ���������
	// ���������-������������� ��������

	TSet& operator=(const TSet& s);  // ������������
	
	TSet operator+ (const int Elem); // ����������� � ���������

	int operator!= (const TSet& s); // ���������// ������� ������ ���� �� ���� �� ��������
	TSet operator- (const int Elem); // �������� � ���������
									 // ������� ������ ���� �� ���� �� ��������
	TSet operator+ (const TSet &s);  // �����������
	TSet operator* (const TSet &s);  // �����������
	TSet operator~ (void);           // ����������

	friend istream &operator>>(istream &istr, TSet &bf);
	friend ostream &operator<<(ostream &ostr, const TSet &bf);

};
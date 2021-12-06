#include <iostream>
#pragma once

using namespace std;

typedef int TELEM;

class TBitField
{
private:
	int _razmer;// ����� �������� ���� - ����. �-�� �����
	TELEM* pMem; // ������ ��� ������������� �������� ����
	int  MemLen, Elem; // �-�� ��-��� ��� ��� ������������� ���.����
	int   GetMemIndex(const int n) const; // ������ � p��� ��� ���� n       (#�2)
	TELEM GetMemMask(const int n) const; // ������� ����� ��� ���� n  

	// ������ ����������

public:
	//                                   (#�1)
	TBitField(const TBitField& bf);  // ���������� �����������              (#�1)
	TBitField(int Elem);
	TBitField();

	TBitField& resize(int size);  //���������� resize ������ ��� ����� ����� ������ �� ����� �������

	~TBitField();
	// ������ � �����
	int GetLength(void) const;      // �������� ����� (�-�� �����)           (#�)
	void SetBit(const int i);       // ���������� ���                       (#�4)
	void ClrBit(const int i);       // �������� ���                         (#�2)
	int  GetBit(const int i) const; // �������� �������� ����               (#�1)
	TBitField& operator=(const TBitField& bf); // ������������              (#�3)

	TBitField operator>>(int k); //����� ����� � �����
	TBitField operator<<(int k); //����� ����� � ����
	bool operator==(const TBitField& bf); // ��������� 
	bool operator!=(const TBitField& bf); // ���������
	TBitField operator|(const TBitField& bf); // �������� "���" 
	TBitField operator~(void); //�������� ���������

	TBitField  operator&(const TBitField& bf); // �������� "�"  
	void print_array();
	bool test();
};
#include <iostream>
#pragma once

using namespace std;

typedef int TELEM;

class TBitField
{
private:
	int _razmer;// len bit polya - max count bit
	TELEM* pMem; // memory for len bit polya
	int  MemLen, Elem; // count mem for  bit polya
	int   GetMemIndex(const int n) const; // indx pmem for bit n      (#Î2)
	TELEM GetMemMask(const int n) const; // bit mask for bit n 

	// methods of realization

public:
	//                                (#Î1)
	TBitField(const TBitField& bf);  // copy             (#Ï1)
	TBitField(int Elem);
	TBitField();

	TBitField& resize(int size);  //we use resize every time the new array is not equal to the old one

	~TBitField();
	// ostup into bit   
	int GetLength(void) const;      // get len           (#Î)
	void SetBit(const int i);       // set bit                      (#Î4)
	void ClrBit(const int i);       // clear bit                      (#Ï2)
	int  GetBit(const int i) const; // get sign bit              (#Ë1)
	TBitField& operator=(const TBitField& bf); // prisvoit             (#Ï3)

	TBitField operator>>(int k); //sdvig right
	TBitField operator<<(int k); //sdvig left
	bool operator==(const TBitField& bf); // if ravno
	bool operator!=(const TBitField& bf); // if ne ravno
	TBitField operator|(const TBitField& bf); // or
	TBitField operator~(void); //inventor

	TBitField  operator&(const TBitField& bf); // and
	void print_array();
	bool test();
};

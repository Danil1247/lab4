#pragma once
#include "Monom.h"
#include "MyList.h"

class TPolinom : public TList<TMonom>
{
public:
	TPolinom(int _N);
	TPolinom(const TPolinom& a);
	~TPolinom();

	int GetN();

	TPolinom operator + (const TPolinom& a);
	TPolinom operator - (const TPolinom& a);
	TPolinom operator * (const TPolinom& a);
	TPolinom& operator += (const TMonom a);

	TPolinom& operator = (const TPolinom& a);

	TMonom& operator[](const size_t i);

protected:
	int N;

	void Delete()
	{
	}
};

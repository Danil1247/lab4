#pragma once

class TMonom
{
public:

	TMonom(size_t _n = 0);
	TMonom(double _k, int* _a, size_t _n);
	TMonom(const TMonom& _a);
	TMonom(TMonom&& _a);

	~TMonom();

	void SetN(size_t _n);
	void SetK(double _k);
	void SetA(int* _a);

	double GetK();
	size_t GetN();
	int* GetA();

	int& operator[](const size_t i);

	bool operator > (const TMonom& a);
	bool operator < (const TMonom& a);
	bool operator == (const TMonom& a);

	TMonom& operator =(const TMonom& a);
	TMonom& operator =(TMonom&& a) noexcept; 
protected:

	double K;
	int* A;
	int N;
};

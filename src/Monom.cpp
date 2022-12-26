#include "Monom.h"

TMonom::TMonom(size_t _n)
{
  if (_n == 0)
    A = nullptr;

  K = 0;

  N = _n;

  if (_n < 0)
    throw "error";

  A = new int[N];

  for (size_t i = 0; i < _n; i++)
    A[i] = 0;
}

TMonom::TMonom(double _k, int* _a, size_t _n)
{

  if (_n < 0)
    throw "error";

  if (_n == 0)
    A = nullptr;
  else
    A = new int[_n];

  K = _k;

  for (size_t i = 0; i < _n; i++)
    A[i] = _a[i];

}

TMonom::TMonom(const TMonom& _a)
{
  K = _a.K;

  if (N == 0)
    A = nullptr;
  else
    A = new int[N];


  for (size_t i = 0; i < N; i++)
    A[i] = _a.A[i];
}

TMonom::TMonom(TMonom&& _a)
{
  K = _a.K;
  A = _a.A;
  N = _a.N;

  _a.A = nullptr;
}

TMonom::~TMonom()
{
  if (A != nullptr)
    delete[] A;

  A = nullptr;

}

void TMonom::SetN(size_t _n)
{
  if (A != nullptr)
    delete[] A;

  if (N == 0)
    A = nullptr;
  else
    A = new int[N];

  for (size_t i = 0; i < _n; i++)
    A[i] = 0;
}

void TMonom::SetK(double _k)
{
  K = _k;
}

void TMonom::SetA(int* _a)
{
  for (size_t i = 0; i < N; i++)
    A[i] = _a[i];
}

double TMonom::GetK()
{
  return K;
}

size_t TMonom::GetN()
{
  return N;
}

int* TMonom::GetA()
{
  return A;
}

int& TMonom::operator[](const size_t i)
{
  if ((i < 0) || (i > N))
    throw "error";

  return A[i];
}

bool TMonom::operator>(const TMonom& a)
{
  if (N != a.N)
    throw "error";

  for (size_t i = 0; i < N; i++)
  {
    if (A[i] == a.A[i])
      continue;
    else if (A[i] > a.A[i])
      return true;
    else
      return false;
  }

  return false;
}

bool TMonom::operator<(const TMonom& a)
{
  if (N != a.N)
    throw "error";

  for (size_t i = 0; i < N; i++)
  {
    if (A[i] == a.A[i])
      continue;
    else if (A[i] > a.A[i])
      return false;
    else
      return true;
  }

  return false;
}

bool TMonom::operator==(const TMonom& a)
{
  if (N != a.N)
    throw "error";

  for (size_t i = 0; i < N; i++)
  {
    if (A[i] == a.A[i])
      continue;
    else
      return false;
  }

  return true;
}

TMonom& TMonom::operator=(const TMonom& a)
{
  if (this == &a)
    return *this;

  if (N != a.N)
  {
    if (A != nullptr)
      delete[] A;

    if (N == 0)
      A = nullptr;
    else
      A = new int[N];
  }

  K = a.K;
  N = a.N;

  for (size_t i = 0; i < N; i++)
    A[i] = a.A[i];

  return *this;
}

TMonom& TMonom::operator=(TMonom&& a) noexcept
{
  K = a.K;
  A = a.A;
  N = a.N;

  a.A = nullptr;

  return *this;
}

#include "Polinom.h"

TPolinom::TPolinom(int _N)
{
  if (_N < 0)
    throw "error";

  N = _N;
}

TPolinom::TPolinom(const TPolinom& a): TList::TList(a)
{
  N = a.N;
}

TPolinom::~TPolinom()
{
}

int TPolinom::GetN()
{
  return N;
}

TPolinom TPolinom::operator+(const TPolinom& a)
{
  TPolinom res(N);

  TListNode<TMonom>* i = start;
  TListNode<TMonom>* j = a.start;

  while ((i != nullptr) || (j != nullptr))
  {
    if (i->GetData() == j->GetData())
    {
      TMonom tmp(i->GetData().GetK() + j->GetData().GetK(), i->GetData().GetA(), N);
      res.PushEnd(tmp);
      i = i->GetNext();
      j = j->GetNext();
    }
    else if (i->GetData() > j->GetData())
    {
      res.PushEnd(i->GetData());
      i = i->GetNext();
    }
    else
    {
      res.PushEnd(j->GetData());
      j = j->GetNext();
    }
  }

  if (i == nullptr)
  {
    while (j != nullptr)
    {
      res.PushEnd(j->GetData());
      j = j->GetNext();
    }
  }

  if (j == nullptr)
  {
    while (i != nullptr)
    {
      res.PushEnd(i->GetData());
      i = i->GetNext();
    }
  }

  return res;
}

TPolinom TPolinom::operator-(const TPolinom& a)
{
  TPolinom res(N);

  TListNode<TMonom>* i = start;
  TListNode<TMonom>* j = a.start;

  while ((i != nullptr) || (j != nullptr))
  {
    if (i->GetData() == j->GetData())
    {
      double newK = i->GetData().GetK() - j->GetData().GetK();
      if (newK != 0)
      {
        TMonom tmp(newK, i->GetData().GetA(), N);
        res.PushEnd(tmp);
      }
      
      i = i->GetNext();
      j = j->GetNext();
    }
    else if (i->GetData() > j->GetData())
    {
      res.PushEnd(i->GetData());
      i = i->GetNext();
    }
    else
    {
      res.PushEnd(j->GetData());
      j = j->GetNext();
    }
  }

  if (i == nullptr)
  {
    while (j != nullptr)
    {
      res.PushEnd(j->GetData());
      j = j->GetNext();
    }
  }

  if (j == nullptr)
  {
    while (i != nullptr)
    {
      res.PushEnd(i->GetData());
      i = i->GetNext();
    }
  }

  return res;
}

TPolinom TPolinom::operator*(const TPolinom& a)
{
  TPolinom res(N);

  TListNode<TMonom>* i = start;
  TListNode<TMonom>* j = a.start;

  while (i != nullptr)
  {
    while (j != nullptr)
    {
      int* newA = new int[N];
      for (size_t k = 0; k < N; k++)
      {
        newA[k] = j->GetData()[k] + i->GetData()[k];
      }

      TMonom tmp(i->GetData().GetK() * j->GetData().GetK(), i->GetData().GetA(), N);

      delete[] newA;

      res += tmp;
    }
  }

  return res;
}

TPolinom& TPolinom::operator+=(const TMonom a)
{
  TListNode<TMonom>* i = this->start;

  if (IsEmpty())
    this->PushStart(a);

  TListNode<TMonom>* tmp = new TListNode<TMonom>(a);

  while (i != nullptr)
  {
    if (i->GetData() < a)
    {
      TListNode<TMonom>* p = i->GetPrev();
      if (p == nullptr)
        this->PushStart(a);

      tmp->SetNext(i);
      tmp->SetPrev(p);
      i->SetPrev(tmp);
      p->SetNext(tmp);

      return *this;
    }

    i = i->GetNext();
  }

  this->PushEnd(a);
}

TPolinom& TPolinom::operator=(const TPolinom& a)
{
  if (this == &a)
    return *this;

  Delete();

  TList::TList(a);
}

TMonom& TPolinom::operator[](const size_t i)
{
  return this->Get(i);
}

#pragma once

#include "MyListNode.h"

template <class T>
class TList
{
public:
	TList();
	TList(const TList<T>& _list);
	~TList();

	void PushStart(T _data);
	void PushEnd(T _data);

	T GetStart();
	T GetEnd();

	void DelStart();
	void DelEnd();

	bool IsEmpty();
	bool IsFull();

	int GetSize();

protected:
	TListNode<T>* start;
	TListNode<T>* end;

	int count;
};

template<class T>
inline TList<T>::TList()
{
	start = nullptr;

	end = nullptr;

	count = 0;
}

template<class T>
inline TList<T>::TList(const TList<T>& _list)
{
	if (_list.start == nullptr)
		throw "error";
	else
	{
		start = new TListNode<T>(*(_list.start));

		TListNode<T>* i = _list.start->GetNext();

		TListNode<T>* j = start;

		while (i != nullptr)
		{
			j->SetNext(new TListNode<T>(*i));
			j->GetNext()->SetPrev(j);

			j = j->GetNext();
			i = i->GetNext();
		}

		end = j;

		count = _list.count;
	}
}

template<class T>
inline TList<T>::~TList()
{
	if (start != nullptr)
	{
		TListNode<T>* j = start;

		while (j != nullptr)
		{
			TListNode<T>* tmp = j;

			j = j->GetNext();

			delete tmp;
		}

		start = nullptr;

		end = nullptr;
	}
}

template<class T>
inline void TList<T>::PushStart(T _data)
{
	if (IsFull())
		throw "error arr is full";

	TListNode<T>* tmp = new TListNode<T>(_data);

	tmp->SetNext(start);

	if (start != nullptr)
		start->SetPrev(tmp);

	start = tmp;

	count++;
}

template<class T>
inline void TList<T>::PushEnd(T _data)
{
	if (IsFull())
		throw "error arr is full";

	TListNode<T>* tmp = new TListNode<T>(_data);

	tmp->SetPrev(start);

	if (end != nullptr)
		end->SetNext(tmp);

	end = tmp;

	count++;
}

template<class T>
inline T TList<T>::GetStart()
{
	return start->GetData();
}

template<class T>
inline T TList<T>::GetEnd()
{
	return end->GetData();
}

template<class T>
inline void TList<T>::DelStart()
{
	if (IsEmpty())
		throw "arr is empty";

	TListNode<T>* tmp = start;

	start = start->GetNext();

	if (start != nullptr)
		start->SetPrev(nullptr);

	delete tmp;

	count--;
}

template<class T>
inline void TList<T>::DelEnd()
{
	if (IsEmpty())
		throw "arr is empty";

	TListNode<T>* tmp = end;

	end = end->GetPrev();

	if (end != nullptr)
		end->SetNext(nullptr);

	delete tmp;

	count--;
}

template<class T>
inline bool TList<T>::IsEmpty()
{
	return (count <= 0);
}

template<class T>
inline bool TList<T>::IsFull()
{
	return false;
}

template<class T>
inline int TList<T>::GetSize()
{
	return count;
}

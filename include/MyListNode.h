#pragma once

template<class T>
class TListNode
{
public:
	TListNode();
	TListNode(T _data);
	TListNode(T _data, TListNode<T>* _next, TListNode<T>* _prev);
	TListNode(const TListNode<T>& _list);
	TListNode(const TListNode<T>&& _list);

	T& GetData();
	TListNode<T>* GetNext();
	TListNode<T>* GetPrev();

	void SetData(T _data);
	void SetNext(TListNode<T>* _next);
	void SetPrev(TListNode<T>* _prev);

protected:

	T data;
	TListNode<T>* next;
	TListNode<T>* prev;

};

template<class T>
inline TListNode<T>::TListNode()
{
	next = nullptr;

	prev = nullptr;
}

template<class T>
inline TListNode<T>::TListNode(T _data)
{
	next = nullptr;

	prev = nullptr;

	data = _data;
}

template<class T>
inline TListNode<T>::TListNode(T _data, TListNode<T>* _next, TListNode<T>* _prev)
{
	next = _next;	

	prev = _prev;

	data = _data;
}

template<class T>
inline TListNode<T>::TListNode(const TListNode<T>& _list)
{
	next = nullptr;

	prev = nullptr;

	data = _list.data;
}

template<class T>
inline TListNode<T>::TListNode(const TListNode<T>&& _list)
{
	next = nullptr;

	prev = nullptr;

	data = _list.data;


	_list.next = nullptr;

	_list.prev = nullptr;

	_list.data = 0;
}

template<class T>
inline T& TListNode<T>::GetData()
{
	return data;
}

template<class T>
inline TListNode<T>* TListNode<T>::GetNext()
{
	return next;
}

template<class T>
inline TListNode<T>* TListNode<T>::GetPrev()
{
	return prev;
}

template<class T>
inline void TListNode<T>::SetData(T _data)
{
	data = _data;
}

template<class T>
inline void TListNode<T>::SetNext(TListNode<T>* _next)
{
	next = _next;
}

template<class T>
inline void TListNode<T>::SetPrev(TListNode<T>* _prev)
{
	prev = _prev;
}

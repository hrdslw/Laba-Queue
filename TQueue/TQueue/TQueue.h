#pragma once
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

template <class T>
class TQueue
{

	T* pMem;								
	int MaxSize;
	int	Head;
	int Tail;
	int CurSize;

public:
	TQueue(int _MaxSize) {
		pMem = new T[_MaxSize];
		MaxSize = _MaxSize;
		CurSize = 0;
		Head = 0;
		Tail = -1;
	}

	TQueue(const TQueue& s) {
		MaxSize = s.MaxSize;
		pMem = new T[MaxSize];
		for (int i = 0; i < MaxSize; i++)
			pMem[i] = s.pMem[i];
		CurSize = s.CurSize;
		Head = s.Head;
		Tail = s.Tail;
	}
	~TQueue() { 
		delete[] pMem;
	}

	int Size() { 
		return MaxSize;
	}

	void Clear() {
		//delete[] pMem;
		CurSize = 0;
		Head = 0;
		Tail = -1;
	}
	TQueue <T>& operator= (const TQueue<T>& q) {
		{


			if (MaxSize != q.MaxSize)
			{
				MaxSize = q.MaxSize;
				delete[] pMem;
				pMem = new T[MaxSize];
			}
			CurSize = q.CurSize;
			Head = q.Head;
			Tail = q.Tail;
			if (Tail >= Head)
			{
				for (int i = Head; i <= Tail; i++)
				{
					pMem[i] = q.pMem[i];
				}
			}
			else
			{
				for (int i = Head; i < MaxSize; i++)
				{
					pMem[i] = q.pMem[i];
				}
				for (int i = 0; i <= Tail; i++)
				{
					pMem[i] = q.pMem[i];
				}
			}

			return *this;
		}
	}

	bool operator == (const TQueue& s) {			
		if (MaxSize != s.MaxSize) return false;
		else {
			if (Head != s.Head) return false;
			else {
				if (Tail != s.Tail) return false;
				else {
					for (int i = 0; i < MaxSize; i++) {
						if (pMem[i] != s.pMem[i]) return false;
					}
				}
			}
		}
		return true;
	}

	bool operator != (const TQueue& s) {			 
		if (*this == s) return false;
		else return true;
	}

	bool IsEmpty() {									
		if (CurSize == 0) return true;
		else return false;
	}

	bool IsFull() {									
		if (CurSize == MaxSize) return true;
		else return false;
	}

	void Push(const T& el) {
		//	Tail = Tail % MaxSize; than u can delete next 2 strings
		if (this->IsFull())
			throw ("Queue is full, cant push");
		Tail++;
		if (Tail == MaxSize) 
			Tail = 0;			
		//if (pMem[Tail])
			//throw ("This position is busy, cant push");
		pMem[Tail] = el;				//in pMem[Tail] can be element. Need to add check of execution "can we push here?"
		CurSize++;
	}

	T Pop() {
		if (this->IsEmpty())
			throw("Queue is empty, cant pop");
		T el = pMem[Head];
		Head++;
		if (Head == MaxSize)
			Head = 0;
		CurSize--;
		return el;
	}

	T Front() { return pMem[Head]; }			
	T Back() { return pMem[Tail]; }


	//
	int GetMaxSize() { return MaxSize; }
	int GetTail() { return Tail; };
	int GetHead() { return Head; };
	int GetCurSize() { return CurSize; };

};
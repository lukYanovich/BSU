#pragma once
#include "Queue.h"

class CQueue : public Queue{
public:
	CQueue() : arr(nullptr), first(0), last(0), capacity(0) {}
	CQueue(int a) { arr = new InfoType[a + 1]; first = last = 0; capacity = a; }
	explicit CQueue(const CQueue& Q) { Clone(Q); }
	virtual ~CQueue(); // только сообщение о вызове
	virtual CQueue& operator=(const Queue&);
	virtual void Push(const InfoType& AInfo);
	virtual bool Pop();
	virtual InfoType GetFirst() const;
	virtual bool IsEmpty() const;
	virtual unsigned GetSize() const;
	virtual InfoType& operator[] (unsigned) const;
	virtual const InfoType& GetByIndex(unsigned) const;
	virtual void ForEach(void ItemWork(InfoType)) const;
	virtual void ForEach(void ItemWork(InfoType&));

	void SetCapacity(unsigned a);
private:
	InfoType* arr;
	unsigned first, last, capacity;
	virtual void Erase();
	virtual void Clone(const Queue&);
	bool Check(const unsigned, const unsigned) const;
};
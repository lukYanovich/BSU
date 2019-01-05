#pragma once
#include "Queue.h"

class LQueue : public Queue{
public:
	LQueue() : front(nullptr), rear(nullptr), size(0) {}
	explicit LQueue(const LQueue& Q) { Clone(Q); }
	virtual ~LQueue(); // только сообщение о вызове
	virtual LQueue& operator=(const Queue&);
	virtual void Push(const InfoType& AInfo);
	virtual bool Pop();
	virtual InfoType GetFirst() const;
	virtual bool IsEmpty() const;
	virtual unsigned GetSize() const;
	virtual InfoType& operator[] (unsigned) const;
	virtual const InfoType& GetByIndex(unsigned) const;
	virtual void ForEach(void ItemWork(InfoType)) const;
	virtual void ForEach(void ItemWork(InfoType&));
private:
	struct QItem{
		InfoType info;
		QItem* next;
		QItem(const InfoType Ainfo) : info(Ainfo), next(nullptr) {}
	};
	QItem *front, *rear;
	unsigned size;
	virtual void Erase();
	virtual void Clone(const Queue&);
};
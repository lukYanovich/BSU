#include "LQueue.h"

InfoType& LQueue::operator[] (unsigned a) const{
	if (a >= size)
		throw exception("wrong index.");
	QItem* t = front;
	for (unsigned i(0);; ++i){
		if (i == a)
			return t->info;
		t = t->next;
	}
}

void LQueue::Clone(const Queue& a){
	if (a.IsEmpty())
		return;
	for (unsigned i(0); i < a.GetSize(); ++i)
		Push(a[i]);
}

void LQueue::Erase(){
	if (front == nullptr)
		return;
	if (front == rear){
		delete front;
		front = rear = nullptr;
		size = 0;
		return;
	}
	QItem* t = front;
	while (t->next){
		QItem* a = t;
		t = t->next;
		delete a;
	}
	front = rear = nullptr;
	size = 0;
}

LQueue::~LQueue(){
	//cout << "destructor LQueue" << endl;
}

InfoType LQueue::GetFirst() const{
	return front->info;
}

bool LQueue::IsEmpty() const{
	if (rear == nullptr)
		return true;
	return false;
}

unsigned LQueue::GetSize() const{
	return size;
}

const InfoType& LQueue::GetByIndex(unsigned a) const{
	return (*this)[a];
}

void LQueue::ForEach(void ItemWork(InfoType)) const{
	if (front == nullptr)
		throw exception("Queue is emtpy.");
	QItem* t = front;
	while (t){
		ItemWork(t->info);
		t = t->next;
	}
}

void LQueue::ForEach(void ItemWork(InfoType&)){
	if (front == nullptr)
		throw exception("Queue is emtpy.");
	QItem* t = front;
	while (t){
		ItemWork(t->info);
		t = t->next;
	}
}

void LQueue::Push(const InfoType& a){
	if (front == nullptr){
		QItem* t = new QItem(a);
		front = rear = t;
	}
	else{
		QItem* t = rear;
		t->next = new QItem(a);
		rear = t->next;
	}
	size++;
}

bool LQueue::Pop(){
	if (front == nullptr)
		return false;
	if (front == rear){
		Erase();
		return true;
	}
	QItem* t = front;
	front = front->next;
	delete t;
	t = nullptr;
	size--;
	return true;
}

LQueue& LQueue::operator= (const Queue& Q){
	if (this == &Q)
		return *this;
	Erase();
	Clone(Q);
	return *this;
}
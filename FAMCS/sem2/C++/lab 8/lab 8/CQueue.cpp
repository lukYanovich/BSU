#include "CQueue.h"

InfoType& CQueue::operator[] (unsigned a) const{
	if (a >= capacity)
		throw exception("wrong index.");
	unsigned k;
	if (first + a <= capacity)
		k = first + a;
	else
		k = first - a + last;
	if (k >= last && k < first)
		throw QException(a);
	return arr[k];
}

void CQueue::Clone(const Queue& a){
	if (a.IsEmpty())
		return;
	if (arr == nullptr)
		arr = new InfoType[capacity];
	for (unsigned i(first); i != last; ++i){
		if (i == capacity + 1){
			if (last != 0)
				i = 0;
			else
				break;
		}
		Push(a[i]);
	}
}

void CQueue::Erase(){
	if (arr == nullptr)
		return;
	delete[] arr;
	first = last = 0;
}

CQueue::~CQueue(){
	//cout << "destructor CQueue" << endl;
}

InfoType CQueue::GetFirst() const{
	if (arr == nullptr)
		throw QException("Queue is empty.");
	return arr[first];
}

bool CQueue::IsEmpty() const{
	if (first == last)
		return true;
	return false;
}

unsigned CQueue::GetSize() const{
	return capacity;
}

const InfoType& CQueue::GetByIndex(unsigned a) const{
	return (*this)[a];
}

void CQueue::ForEach(void ItemWork(InfoType)) const{
	if (IsEmpty())
		throw QException("Queue is emtpy.");
	for (unsigned i(first); i != last; ++i){
		if (i == capacity + 1){
			if (last != 0)
				i = 0;
			else
				break;
		}
		ItemWork(arr[i]);
	}
}

void CQueue::ForEach(void ItemWork(InfoType&)){
	if (IsEmpty())
		throw QException("Queue is emtpy.");
	for (unsigned i(first); i != last; ++i){
		if (i == capacity + 1){
			if (last != 0)
				i = 0;
			else
				break;
		}
		ItemWork(arr[i]);
	}
}

void CQueue::Push(const InfoType& a){
	if (last == first){
		arr[last++] = a;
		return;
	}
	if (Check(first, last))
		throw QException(a);
	if (last == capacity){
		if (first != 0){
			arr[last] = a;
			last = 0;
			return;
		}
		else
			throw QException(a);
	}
	arr[last++] = a;
}

bool CQueue::Pop(){
	if (first == last)
		return false;
	if (first == capacity)
		first = 0;
	else
		first++;
	return true;
}

void CQueue::SetCapacity(unsigned a){
	if (a == capacity)
		return;
	if (a < capacity){
		delete[] arr;
		capacity = a;
		arr = new InfoType[a + 1];
		first = last = 1;
		return;
	}
	InfoType* t = new InfoType[a + 1];
	for (unsigned i(0); i < capacity; ++i)
		t[i] = arr[i];
	delete[] arr;
	arr = t;
	capacity = a;
}

bool CQueue::Check(const unsigned First, const unsigned Last) const{
	return (First - Last == 1) ? true : false;
}

CQueue& CQueue::operator= (const Queue& Q){
	if (this == &Q)
		return *this;
	Erase();
	Clone(Q);
	return *this;
}
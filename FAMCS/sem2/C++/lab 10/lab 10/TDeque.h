#pragma once
#include "exception.h"

template<class T> class TDeque{
public:
	TDeque() : front(nullptr), rear(nullptr), size(0) {}
	TDeque(const TDeque<T>& a) { Clone(a); }
	~TDeque() { Erase(); }
	TDeque<T>& operator=(const TDeque<T>&);

	void PushFront(const T&);
	void PushRear(const T&);
	bool PopFront();
	bool PopRear();
	const T GetByIndex(unsigned) const; // получить элемент по индексу
	void SetByIndex(const T, unsigned); // изменить элемент по индексу
	void ForEach(void ItemWork(T)); //было Browse
	void ForEach(void ItemWork(const T)) const;

	bool IsEmpty() const;
	void _delete(unsigned);
private:
	struct Node{
		T info;
		struct Node *next, *prev;
		Node(const T Ainfo) : info(Ainfo), next(nullptr), prev(nullptr) {}
	};
	Node *front, *rear;
	unsigned size;

	void Erase();
	void Clone(const TDeque&);
	void DeleteItem(Node*); // удаление элемента по указателю
	void* PtrByIndex(unsigned) const; // указатель на элемент с заданным индексом
};


template<class T> void TDeque<T>::Erase(){
	if (front == nullptr)
		return;
	if (front == rear){
		delete front;
		front = rear = nullptr;
		size = 0;
		return;
	}
	Node* t = front;
	while (t->next){
		Node* a = t;
		t = t->next;
		delete a;
	}
	front = rear = nullptr;
	size = 0;
}

template<class T> void TDeque<T>::Clone(const TDeque& a){
	if (a.IsEmpty())
		return;
	for (ushort i(0); i < a.size; ++i)
		PushRear(a.GetByIndex(i));
}

template<class T> TDeque<T>& TDeque<T>::operator=(const TDeque<T>& a){
	if (this == &a)
		return *this;
	Erase();
	Clone(a);
	return *this;
}

template<class T> void TDeque<T>::ForEach(void ItemWork(const T)) const{
	if (front == nullptr)
		throw exception("Queue is emtpy.");
	Node* t = front;
	while (t){
		ItemWork(t->info);
		t = t->next;
	}
}

template<class T> void TDeque<T>::ForEach(void ItemWork(T)){
	if (front == nullptr)
		throw exception("Queue is emtpy.");
	Node* t = front;
	while (t){
		ItemWork(t->info);
		t = t->next;
	}
}

template<class T> const T TDeque<T>::GetByIndex(unsigned a) const{
	if (a >= size)
		throw QDequeException(a);
	Node* t = front;
	for (ushort i(0);; ++i){
		if (i == a)
			return t->info;
		t = t->next;
	}
}

template<class T> void TDeque<T>::SetByIndex(const T _A, unsigned a){
	if (a >= size)
		throw QDequeException(a);
	Node* t = front;
	for (ushort i(0);; ++i){
		if (i == a){
			t->info = _A;
			return;
		}
		t = t->next;
	}
}

template<class T> void TDeque<T>::PushFront(const T& a){
	if (front == nullptr){
		Node* t = new Node(a);
		front = rear = t;
	}
	else{
		Node* t = new Node(a);
		t->next = front;
		front->prev = t;
		front = t;
	}
	size++;
}

template<class T> void TDeque<T>::PushRear(const T& a){
	if (front == nullptr){
		PushFront(a);
		return;
	}
	Node* t = new Node(a);
	t->prev = rear;
	rear->next = t;
	rear = t;
	size++;
}

template<class T> bool TDeque<T>::PopFront(){
	if (front == nullptr)
		return false;
	if (front == rear){
		Erase();
		return true;
	}
	Node* t = front;
	front = front->next;
	delete t;
	t = nullptr;
	size--;
	return true;
}

template<class T> bool TDeque<T>::PopRear(){
	if (front == nullptr || front == rear)
		return PopFront();
	Node* t = rear;
	rear = rear->prev;
	delete t;
	t = nullptr;
	rear->next = t;
	size--;
	return true;
}

template<class T> void TDeque<T>::DeleteItem(Node* p){
	if (p == front){
		PopFront();
		return;
	}
	else if (p == rear){
		PopRear();
		return;
	}
	Node* t = front;
	while (t != p){
		if (t == rear)
			return;
		t = t->next;
	}
	Node* temp = t;
	t->prev->next = t->next;
	t->prev = t->prev;
	delete t;
	t = temp = nullptr;
}

template<class T> void* TDeque<T>::PtrByIndex(unsigned a) const{
	if (a >= size)
		throw QDequeException(a);
	Node* t = front;
	for (unsigned i(0);; ++i){
		if (i == a)
			return t;
		t = t->next;
	}
}

/////////////////////////////////////////////////////

template<class T> bool TDeque<T>::IsEmpty() const{
	if (front == nullptr)
		return true;
	return false;
}

template<class T> void TDeque<T>::_delete(unsigned a){
	DeleteItem(static_cast<Node*>(PtrByIndex(a)));
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
///////////////////    специализация шаблона    /////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


template<> class TDeque<char*>{
public:
	TDeque() : front(nullptr), rear(nullptr), size(0) {}
	TDeque(const TDeque<char*>& a) { Clone(a); }
	~TDeque() { Erase(); }
	TDeque<char*>& operator=(const TDeque<char*>&);

	void PushFront(const char*);
	void PushRear(const char*);
	bool PopFront();
	bool PopRear();
	const char* GetByIndex(unsigned) const; // получить элемент по индексу
	void SetByIndex(const char*, unsigned); // изменить элемент по индексу
	void ForEach(void ItemWork(char*)); //было Browse
	void ForEach(void ItemWork(const char*)) const;

	bool IsEmpty() const;
	void _delete(unsigned);
private:
	struct Node{
		char* info;
		struct Node *next, *prev;
		Node(const char* Ainfo){
			info = new char[strlen(Ainfo) + 1];
			strcpy(info, Ainfo);
			next = nullptr;
			prev = nullptr;
		}
	};
	Node *front, *rear;
	unsigned size;

	void Erase();
	void Clone(const TDeque&);
	void DeleteItem(Node*); // удаление элемента по указателю
	void* PtrByIndex(unsigned) const; // указатель на элемент с заданным индексом
};


void TDeque<char*>::Erase(){
	if (front == nullptr)
		return;
	if (front == rear){
		delete front;
		front = rear = nullptr;
		size = 0;
		return;
	}
	Node* t = front;
	while (t->next){
		Node* a = t;
		t = t->next;
		delete[] a->info;
		delete a;
	}
	front = rear = nullptr;
	size = 0;
}

void TDeque<char*>::PushFront(const char* a){
	if (front == nullptr){
		Node* t = new Node(a);
		front = rear = t;
	}
	else{
		Node* t = new Node(a);
		t->next = front;
		front->prev = t;
		front = t;
	}
	size++;
}

void TDeque<char*>::Clone(const TDeque& a){
	if (a.IsEmpty())
		return;
	for (ushort i(0); i < a.size; ++i)
		PushRear(a.GetByIndex(i));
}

TDeque<char*>& TDeque<char*>::operator=(const TDeque<char*>& a){
	if (this == &a)
		return *this;
	Erase();
	Clone(a);
	return *this;
}

void TDeque<char*>::ForEach(void ItemWork(const char*)) const{
	if (front == nullptr)
		throw exception("Queue is emtpy.");
	Node* t = front;
	while (t){
		ItemWork(t->info);
		t = t->next;
	}
}

void TDeque<char*>::ForEach(void ItemWork(char*)){
	if (front == nullptr)
		throw exception("Queue is emtpy.");
	Node* t = front;
	while (t){
		ItemWork(t->info);
		t = t->next;
	}
}

const char* TDeque<char*>::GetByIndex(unsigned a) const{
	if (a >= size)
		throw QDequeException(a);
	Node* t = front;
	for (ushort i(0);; ++i){
		if (i == a)
			return t->info;
		t = t->next;
	}
}

void TDeque<char*>::SetByIndex(const char* _A, unsigned a){
	if (a >= size)
		throw QDequeException(a);
	Node* t = front;
	for (ushort i(0);; ++i){
		if (i == a){
			t->info = const_cast<char*>(_A);
			return;
		}
		t = t->next;
	}
}

void TDeque<char*>::PushRear(const char* a){
	if (front == nullptr){
		PushFront(a);
		return;
	}
	Node* t = new Node(a);
	t->prev = rear;
	rear->next = t;
	rear = t;
	size++;
}

bool TDeque<char*>::PopFront(){
	if (front == nullptr)
		return false;
	if (front == rear){
		Erase();
		return true;
	}
	Node* t = front;
	front = front->next;
	delete[] t->info;
	delete t;
	t = nullptr;
	size--;
	return true;
}

bool TDeque<char*>::PopRear(){
	if (front == nullptr || front == rear)
		return PopFront();
	Node* t = rear;
	rear = rear->prev;
	delete[] t->info;
	delete t;
	t = nullptr;
	rear->next = t;
	size--;
	return true;
}

void TDeque<char*>::DeleteItem(Node* p){
	if (p == front){
		PopFront();
		return;
	}
	else if (p == rear){
		PopRear();
		return;
	}
	Node* t = front;
	while (t != p){
		if (t == rear)
			return;
		t = t->next;
	}
	Node* temp = t;
	t->prev->next = t->next;
	t->prev = t->prev;
	delete[] t->info;
	delete t;
	t = temp = nullptr;
}

void* TDeque<char*>::PtrByIndex(unsigned a) const{
	if (a >= size)
		throw QDequeException(a);
	Node* t = front;
	for (unsigned i(0);; ++i){
		if (i == a)
			return t;
		t = t->next;
	}
}

/////////////////////////////////////////////////////

bool TDeque<char*>::IsEmpty() const{
	if (front == nullptr)
		return true;
	return false;
}

void TDeque<char*>::_delete(unsigned a){
	DeleteItem(static_cast<Node*>(PtrByIndex(a)));
}
#include "Queue.h"

Queue::Queue(const Queue& Q){
	Clone(Q);
}

Queue::~Queue(){
	Erase();
	//cout << "destructor Queue" << endl;
}

Queue& Queue::operator= (const Queue& Q){
	if (this == &Q)
		return *this;
	Erase();
	Clone(Q);
	return *this;
}
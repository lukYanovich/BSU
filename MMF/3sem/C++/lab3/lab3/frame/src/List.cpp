#include "../include/List.h"
#include "../include/MyAux.h"


List::List() {
	create();
}

List::List(const List& o) {
	create();
	auto p = o.first;
	while (p) {
		add(p->info);
		p = p->next;
	}
}



//методы класса

void List::add(const int o) noexcept {
	add(_size, o);
}

void List::add(const size_t index, const int element) {
	if (index == 0 || !first)
		push_front(element);
	else {
		if (index == _size)
			findEnd()->next = make_shared<Node>(element);
		else {
			check(index - 1, "add");
			auto p = first;
			for (size_t i(0); i < index - 1; i++, p = p->next);
			auto temp = p->next;
			p->next = make_shared<Node>(element);
			p->next->next = temp;
		}
		_size++;
	}
}

void List::clear() noexcept {
	if (first) {
		first.reset();
		_size = 0;
	}
}

bool List::contains(const int& o) const noexcept {
	for (auto p = first; p; p = p->next)
		if (p->info == o)
			return true;
	return false;
}

size_t List::indexOf(const int& o) const {
	check("indexOf");
	auto p = first;
	size_t i(0);
	for (; i < _size; i++, p = p->next)
		if (p->info == o)
			return i;
	if (i == _size)
		throw invalid_argument("list hasn't contains \'" + to_string(o) + "\'");
	return NULL;
}

bool List::isEmpty() const noexcept {
	return _size < 1;
}

size_t List::lastIndexOf(const int& o) const {
	check("lastIndexOf");
	size_t i(_size - 1);
	for (; i >= 0; i--)
		if (get(i) == o)
			return i;
	if (i == 0)
		throw invalid_argument("list hasn't contains this element");
	return NULL;
}

void List::remove(const int& o) noexcept {
	if (contains(o))
		remove(indexOf(o));
}

void List::remove(const size_t index) {
	check(index, "remove");
	if (index == 0)
		pop_front();
	else {
		if (index == _size - 1)
			findOfIndex(index - 1)->next.reset();
		else
			findOfIndex(index - 1)->next = findOfIndex(index + 1);
		_size--;
	}
}

void List::removeAll(const int& o) noexcept {
	while (contains(o))
		remove(indexOf(o));
}

void List::set(const size_t index, const int element) {
	check(index, "set");
	findOfIndex(index)->info = element;
}

int List::get(const size_t index) const {
	check(index, "get");
	return findOfIndex(index)->info;
}

int* List::toArray() const {
	check("toArray");
	int* arr = new int[_size];
	auto p = first;
	for (size_t i(0); i < _size; i++, p = p->next)
		arr[i] = p->info;
	return arr;
}

size_t List::size() const noexcept {
	return _size;
}

void List::sort() noexcept {
	if (first && first->next) {
		bool flag = true;
		while (flag) {
			flag = false;
			auto p = first;
			for (; p->next; p = p->next)
				if (p->info > p->next->info) {
					flag = true;
					swap(p->info, p->next->info);
				}
		}
	}
}

List& List::operator=(const List& o) noexcept {
	if (this != &o) {
		first = o.first;
		_size = o._size;
	}
	return *this;
}

istream& operator >> (istream& is, List& o) {
	o.clear();
	while (is.good()) {
		try {
			auto arr = List::read(is);
			switch ((arr[0].c_str())[0]) {

			case 'i':
				if (arr.size() == 2)
					o.add(List::toNumber(arr[1]));
				else if (arr.size() == 3)
					o.add((size_t)List::toNumber(arr[1]), List::toNumber(arr[2]));
				break;

			case 'd':
				if (arr.size() == 2)
					o.remove(List::toNumber(arr[1]));
				else if (arr.size() == 3) {
					if (arr[1] == "i")
						o.remove((size_t)List::toNumber(arr[2]));
					else if (arr[1] == "all")
						o.removeAll(List::toNumber(arr[2]));
				}
				break;

			case 's':
				o.set((size_t)List::toNumber(arr[1]), List::toNumber(arr[2]));
				break;

			default:
				break;
			}
		}
		catch (exception& e) {
			MyAux::printException(e);
		}
	}
	return is;
}

ostream& operator<<(ostream& os, const List& o) {
	if (!o.isEmpty()) {
		auto p = o.first;
		for (; p->next; p = p->next)
			os << p->info << ", ";
		os << p->info;
	}
	return os;
}



//вспомогательные методы

void List::create() noexcept {
	_size = 0;
	first.reset();
}

shared_ptr<Node> List::findEnd() const noexcept {
	auto p = first;
	for (; p->next; p = p->next);
	return p;
}

shared_ptr<Node> List::findOfIndex(const size_t index) const noexcept {
	auto p = first;
	for (size_t i(0); i != index; i++, p = p->next);
	return p;
}

void List::check(const char* nameOfMethod) const {
	check(0, nameOfMethod);
}

void List::check(const size_t index, const char* nameOfMethod) const {
	string message = "List.";
	message += nameOfMethod;
	message += "()";
	if (index >= _size)
		throw out_of_range(message);
	else if (!first)
		throw invalid_argument(message);
}

void List::push_front(const int o) noexcept {
	auto p = make_shared<Node>(o);
	p->next = first;
	first = p;
	_size++;
}

void List::pop_front() noexcept {
	if (_size == 1)
		clear();
	else {
		first = first->next;
		_size--;
	}
}



//aux функции

void List::checkOfEmpty(string str) {
	regex reg("^\\s*$");
	if (regex_match(str, reg))
		throw exception("line is empty");
}

void List::repairArr(vector<string>& arr) {
	for (size_t i(0); i < arr.size(); i++)
		if (arr[i].empty())
			arr.erase(arr.begin() + i--);
}

int List::toNumber(string s) {
	return atoi(s.c_str());
}

vector<string> List::read(istream& is) {
	string str;
	getline(is, str);
	checkOfEmpty(str);
	vector<string> arr;
	boost::split(arr, str, boost::is_any_of(" "));
	repairArr(arr);
	return arr;
}

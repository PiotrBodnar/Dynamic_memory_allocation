#include "List.h"



List::Node * List::find(const size_t idx)
{
	Node * node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next;
	}

	return node;
}

void List::push(const Point & point, const size_t idx) 
{
	if (idx == 0)
	{
		Node * tail = first;
		first = new Node(point); 
		first->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List & list, const size_t idx)
{
	List copy(list);
	Node * it = copy.first;
	if (idx == 0)
	{
		Node * tail = first;
		Node * last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		last->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += list.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

void List::multiply(int scalar)
{
	if (scalar != 1) {
		List copy = *this;
		if (scalar == 0)
		{
			size_t test = size;
			for (int i = 0; i < test; i++)
			{
				pop_front();
			}
		}
		else if (scalar > 1)
		{
			for (int i = 1; i < scalar; i++)
			{
				push(copy, size);
			}
		}
	}
}

List::List() : size(0), first(nullptr){}

List::List(const List & list) : size(list.size), first(nullptr)
{
	Node * it = list.first;
	Node * last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}
List::List(const std::vector<Point>& punkty)
{
	Point p1(1.0, 2.0, 3.0), p2(4.0, 5.0, 6.0);
	push(p1, size);
	push(p2, size);
}

List::~List()
{
	//while(size) pop(0);
	Node* currentNode = first;
	while (currentNode)
	{
		Node* nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	size = 0;
}

List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

List::Error List::pop_back()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(size-1);
	}

	return error;
}

List::Error List::push_back(const Point & Punkt)
{
	List::Error error = List::Error::SUCCESS;

	push(Punkt, size);

	return error;
}

List::Error List::find(Point& Punkt, const std::size_t Numer)
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else if (Numer > (size-1) || Numer < 0)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	else
	{
		Punkt = find(Numer)->point;
	}

	return error;
}

List::Error List::insert(const Point& Punkt, const std::size_t Numer)
{
	List::Error error = List::Error::SUCCESS;

	if (Numer > size || Numer < 0)
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	else
	{
		push(Punkt, Numer);
	}

	return error;
}

size_t List::getSize()
{
	return size;
}

List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List & List::operator=(const List & list)
{
	List copy(list);
	this->~List(); 
	push(copy, 0);
	return *this;
}

List List::operator--(int)
{
	List copy(*this);
	pop_back();
	return copy;
}

List List::operator*(int scalar)
{
	multiply(scalar);
	return *this;
}

Point& List::operator[](const size_t idx)
{
	return find(idx)->point;
}

List List::operator++(int)
{
	List copy(*this);
	while (0 < size)
	{
		pop_front();
	}
	return copy;
}

std::ostream& operator<<(std::ostream& out, const List& l)
{
	Point tmp;
	List copy(l);
	for (size_t i = 0; i < l.size; i++)
	{
		//tmp = copy[i];
		//copy[7] = Point(0,1,2);
		copy.find(tmp, i);
		//tmp = copy.find(i)->point;
		out << tmp.x << " " << tmp.y << " " << tmp.z << std::endl;
	}
	return out;
}



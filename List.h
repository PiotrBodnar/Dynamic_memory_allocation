// Adam Geppert, Piotr Bodnar AiR Grupa 7

#pragma once
#include <vector>
#include "Point.h"
#include <iostream>

class List
{
	size_t size;
	struct Node
	{
		Point point;
		Node * next;
		Node(const Point & p) : point(p.x, p.y, p.z), next(nullptr){}
	};
	Node * first;

	Node * find(const size_t);
	void push(const Point &, const size_t);
	void push(const List &, const size_t);
	void pop(const size_t);
	void multiply(int);
	

public:
	List();
	List(const List&); 
	List(const std::vector<Point>&);
	~List();

	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};

	Error pop_front();
	Error pop_back();
	Error push_back(const Point &);
	Error insert(const Point &, const std::size_t); 
	Error find(Point&, const std::size_t);
	size_t getSize();


	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List operator--(int);
	List operator*(int);
	Point& operator[](const size_t);
	List operator++(int);
	friend std::ostream& operator<<(std::ostream& out, const List& l);
	
};

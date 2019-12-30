#pragma once
#include "List.h"
template <class T, class Container = List<T>>
class Queue
{
public:
	Queue() : container() { }
	void push(T data) { container.push_back(data); }
	void pop() { container.pop_front(); }
	const T& front() const { return container.front(); }
	const T& back() const { return container.back(); }
	bool empty() const { return container.empty(); }
	int size() const { return container.size(); }
	void clear() { container.clear(); }
private:
	Container container;
};

#pragma once
#include "List.h"
template <class T, class Container = List<T>>
class Deque
{
public:
	Deque() : container() { }
	void push_front(T data) { container.push_front(data); }
	void push_back(T data) { container.push_back(data); }
	void pop_front() { container.pop_front(); }
	void pop_back() { container.pop_back(); }
	const T& front() const { return container.front(); }
	const T& back() const { return container.back(); }
	bool empty() const { return container.empty(); }
	int size() const { return container.size(); }
	void clear() { container.clear(); }
private:
	Container container;
};

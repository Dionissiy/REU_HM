#pragma once
#include "List.h"
template <typename T, typename Container = List<T>>
class Stack
{
public:
	Stack() : container() {} 
	void push(const T& data) { container.push_back(data); }
	void pop() { container.pop_back(); }
	const T& top() const { return container.back(); }
	bool empty() { return container.empty(); }
	int size() { return container.size(); }
	void clear() { container.clear(); }
private:
	Container container;
};

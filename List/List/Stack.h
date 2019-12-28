#pragma once
#include "List.h"
template <typename T, typename Container = List<T>>
class Stack
{
public:
	Stack() : container() {} 
	void push(const T& data);
	void pop();
	const T& top() const;
	bool empty();
	int size();
private:
	Container container;
};

template<typename T, typename Container>
inline void Stack<T, Container>::push(const T& data)
{
	container.push_back(data);
}

template<typename T, typename Container>
inline void Stack<T, Container>::pop()
{
	container.pop_back();
}

template<typename T, typename Container>
inline const T& Stack<T, Container>::top() const
{
	return container.back();
}

template<typename T, typename Container>
inline bool Stack<T, Container>::empty()
{
	return container.empty();
}

template<typename T, typename Container>
inline int Stack<T, Container>::size()
{
	return container.size();
}

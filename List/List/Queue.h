#pragma once
#include "List.h"
template <class T, class Container = List<T>>
class Queue
{
public:
	void push(T data);
	void pop();
	const T& front() const;
	const T& back() const;
	bool empty() const;
	int size() const;
private:
	Container container;
};

template<class T, class Container>
inline void Queue<T, Container>::push(T data)
{
	container.push_back(data);
}

template<class T, class Container>
inline void Queue<T, Container>::pop()
{
	container.pop_front();
}

template<class T, class Container>
inline const T& Queue<T, Container>::front() const
{
	return container.front();
}

template<class T, class Container>
inline const T& Queue<T, Container>::back() const
{
	return container.back();
}

template<class T, class Container>
inline bool Queue<T, Container>::empty() const
{
	return container.empty();
}

template<class T, class Container>
inline int Queue<T, Container>::size() const
{
	return container.size();
}

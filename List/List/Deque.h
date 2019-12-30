#pragma once
#include "List.h"
template <class T, class Container = List<T>>
class Deque
{
public:
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	const T& front() const;
	const T& back() const;
	bool empty() const;
	int size() const;
private:
	Container container;
};

template<class T, class Container>
inline void Deque<T, Container>::push_front(T data)
{
	container.push_front(data);
}

template<class T, class Container>
inline void Deque<T, Container>::push_back(T data)
{
	container.push_back(data);
}

template<class T, class Container>
inline void Deque<T, Container>::pop_front()
{
	container.pop_front();
}

template<class T, class Container>
inline void Deque<T, Container>::pop_back()
{
	container.pop_back();
}

template<class T, class Container>
inline const T& Deque<T, Container>::front() const
{
	return container.front();
}

template<class T, class Container>
inline const T& Deque<T, Container>::back() const
{
	return container.back();
}

template<class T, class Container>
inline bool Deque<T, Container>::empty() const
{
	return container.empty();
}

template<class T, class Container>
inline int Deque<T, Container>::size() const
{
	return container.size();
}

#pragma once
template <typename T>
class List
{
	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node(const T& value);
	};

	Node* head;
	Node* tail;
	size_t m_size;

public:
	class Iterator
	{
		Node* node;
		friend class List;
		Iterator(Node* node) : node(node) { }
	public:
		Iterator(const Iterator& other) : node(other.node) { }
		bool operator==(const Iterator& other) const
		{
			if (this == &other)
				return true;

			return node == other.node;
		}
		bool operator!=(const List<T>::Iterator& other) const
		{
			return !operator==(other);
		}

		T& operator*() const
		{
			return node->data;
		}

		T& operator*()
		{
			return node->data;
		}

		Iterator& operator++()
		{
			if (node)
				node = node->next;
			return *this;
		}
		Iterator& operator--()
		{
			if (node)
				node = node->prev;
			return *this;
		}

		const Iterator operator++(int)
		{
			Iterator temp(*this);
			if (node)
				node = node->next;
			return temp;
		}
		const Iterator operator--(int)
		{
			Iterator temp(*this);
			if (node)
				node = node->prev;
			return temp;
		}
	};

	List();
	int size() const;
	bool empty() const;
	void push_back(const T& value);
	void push_front(const T& value);
	bool pop_back();
	bool pop_front();
	void clear();
	const T& front() const;
	T& front();
	const T& back() const;
	T& back();

	Iterator insert(const Iterator pos, const T& value)
	{
		if (pos.node == nullptr)
		{
			push_back(value);
			return Iterator(nullptr);
		}

		Node* temp = new Node(value);
		temp->next = pos.node;
		temp->prev = pos.node->prev;

		if (pos.node->prev != nullptr)
			pos.node->prev->next = temp;
		else
			head = temp;

		pos.node->prev = temp;

		++m_size;
		return Iterator(temp);
	}

	Iterator erase(const Iterator pos)
	{
		if (pos.node == nullptr)
			return end();

		if (pos.node->prev != nullptr)
			pos.node->prev->next = pos.node->next;
		else
			head = head->next;

		if (pos.node->next != nullptr)
			pos.node->next->prev = pos.node->prev;
		else
			tail = tail->prev;

		Node* temp = pos.node->next;
		pos.node->~Node();
		delete pos.node;

		--m_size;
		return Iterator(temp);
	}

	Iterator begin() const
	{
		return Iterator(head);
	}
	Iterator end() const
	{
		return Iterator(nullptr);
	}
	Iterator rbegin() const
	{
		return Iterator(tail);
	}

	~List();
};

template<typename T>
inline List<T>::Node::Node(const T& value) : data(value), prev(nullptr), next(nullptr)
{
}

template<typename T>
inline List<T>::List() : head(nullptr), tail(nullptr), m_size(0)
{
}

template<typename T>
inline int List<T>::size() const
{
	return this->m_size;
}

template<typename T>
inline bool List<T>::empty() const
{
	return m_size == 0;
}

template<typename T>
inline void List<T>::push_back(const T& value)
{
	if (head == nullptr)
	{
		tail = head = new Node(value);
	}
	else
	{
		Node* tmp = new Node(value);
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
	++m_size;
}

template<typename T>
inline void List<T>::push_front(const T& value)
{
	if (head == nullptr)
	{
		tail = head = new Node(value);
	}
	else
	{
		Node* tmp = new Node(value);
		head->prev = tmp;
		tmp->next = head;
		head = tmp;
	}
	++m_size;
}

template<typename T>
inline bool List<T>::pop_back()
{
	if (head == nullptr)
		return false;
	
	if (tail != head)
	{
		tail = tail->prev;
		delete tail->next;
	}
	else
	{
		delete tail;
		tail = head = nullptr;
	}
	--m_size;
	return true;
}

template<typename T>
inline bool List<T>::pop_front()
{
	if (head == nullptr)
		return false;

	if (tail != head)
	{
		head = head->next;
		delete head->prev;
	}
	else
	{
		delete head;
		tail = head = nullptr;
	}
	--m_size;
	return true;
}

template<typename T>
inline void List<T>::clear()
{
	while (pop_front());
}

template<typename T>
inline const T& List<T>::front() const
{
	return head->data;
}

template<typename T>
inline T& List<T>::front()
{
	return head->data;
}

template<typename T>
inline const T& List<T>::back() const
{
	return tail->data;
}

template<typename T>
inline T& List<T>::back()
{
	return tail->data;
}

template<typename T>
inline List<T>::~List()
{
	clear();
}



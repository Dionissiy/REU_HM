#pragma once
template <typename T>
class ForwardList
{
	struct Node
	{
		T data;
		Node* next;

		Node(const T& value);
		~Node();
	};

	Node* head;
	size_t m_size;

public:
	class Iterator
	{
		Node* node;
		friend class ForwardList;
	public:
		Iterator(Node* node) : node(node) { }
		Iterator(const Iterator& other) : node(other.node) { }
		bool operator==(const Iterator& other) const
		{
			if (this == &other)
				return true;

			return node == other.node;
		}
		bool operator!=(const Iterator& other) const
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

		const Iterator operator++(int)
		{
			Iterator temp(*this);
			if (node)
				node = node->next;
			return temp;
		}
	};

	ForwardList();
	~ForwardList();
	void clear() noexcept;
	int size() const;
	bool empty() const;
	void push_front(const T& value);
	bool pop_front();
	const T& front() const;
	T& front();

	Iterator insert_after(const Iterator pos, const T& value)
	{
		Node* temp = pos.node->next;
		pos.node->next = new Node(value);
		pos.node->next->next = temp;

		++m_size;

		return Iterator(pos.node->next);
	}

	Iterator erase_after(const Iterator pos, const T& value)
	{
		if (pos.node->next == nullptr)
			return end();

		Node* temp = pos.node->next->next;

		pos.node->next->~Node();
		delete pos.node->next;

		pos.node->next = temp;

		return Iterator(pos.node->next);
	}

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(nullptr); }
};

template<typename T>
inline ForwardList<T>::ForwardList() : head(nullptr),  m_size(0)
{
}

template<typename T>
inline ForwardList<T>::~ForwardList()
{
	clear();
}

template<typename T>
inline void ForwardList<T>::clear() noexcept
{
	if (empty())
		return;

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;

		temp->~Node();
		delete temp;
	}

	m_size = 0;
}

template<typename T>
inline int ForwardList<T>::size() const
{
	return m_size;
}

template<typename T>
inline bool ForwardList<T>::empty() const
{
	return m_size == 0;
}

template<typename T>
inline void ForwardList<T>::push_front(const T& value)
{
	Node* temp = head;
	head = new Node(value);
	head->next = temp;
	++m_size;
}

template<typename T>
inline bool ForwardList<T>::pop_front()
{
	if (head == nullptr)
		return false;

	Node* temp = head;
	head = head->next;

	temp->~Node();
	delete temp;
	
	--m_size;

	return true;
}

template<typename T>
inline const T& ForwardList<T>::front() const
{
	return head->data;
}

template<typename T>
inline T& ForwardList<T>::front()
{
	return head->data;
}

template<typename T>
inline ForwardList<T>::Node::Node(const T& value) : data(value), next(nullptr)
{
}

template<typename T>
inline ForwardList<T>::Node::~Node()
{
	data.~T();
}

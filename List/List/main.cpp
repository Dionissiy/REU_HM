#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

using namespace std;

int main()
{
	int n;
	cin >> n;

	Deque<int> stack;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		stack.push_front(x);
	}
	
	cout << "stack size = " << stack.size() << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << stack.front() << ' ';
		stack.pop_front();
	}
	cout << endl;

	cout << "stack size = " << stack.size() << endl;

	return 0;
}
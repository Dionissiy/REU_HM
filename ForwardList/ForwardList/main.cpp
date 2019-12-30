#include "ForwardList.h"
#include <iostream>

using namespace std;

int main()
{
	ForwardList<int> list;

	const int n = 5;

	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		list.push_front(x);
	}

	auto it = list.begin();
	++it;
	list.insert_after(it, 777);

	while(!list.empty())
	{
		cout << list.front() << ' ';
		list.pop_front();
	}
	
	cout << endl;
	return 0;
}
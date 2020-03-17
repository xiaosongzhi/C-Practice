#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int>& d)
{
	//iteratorÆÕÍ¨µü´úÆ÷
	//reverse_iterator ÄæĞòµü´úÆ÷
	//const_iterator Ö»¶Áµü´úÆ÷
	deque<int>::const_iterator it;
	for (it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	cout << "==================" << endl;
}

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
d.push_front(40);

	deque<int>d2(d.begin(), d.end());

d2.push_back(100);

	printDeque(d2);

	printDeque(d);

	sort(d2.begin(), d2.end());

	printDeque(d2);

	if (d2.empty())
	{
		cout << "d2 is empty" << endl;
	}
	else
	{
		cout << "d2 is not empty" << endl;
	}

	d2.pop_back();
	d2.pop_front();

	printDeque(d2);
}
//

int main()
{
	test01();
	system("pause");
	return 0;
}
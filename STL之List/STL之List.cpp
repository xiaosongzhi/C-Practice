// STL之List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

void printList(list<int> &L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
bool compare(int a, int b)
{
	return a > b;//此时表示逆序
}
/*
list 翻转排序
reverse()//翻转链表，比如list包含1,3,5元素，翻转之后就是5,3,1
sort()//list排序
*/
void test01()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);

	printList(L);
	L.reverse();
	printList(L);
	//所有不支持随机访问的迭代器不可以用系统提供的算法
	//如果不支持用系统提供的算法，那么这个类内部会提供
	//sort(L.begin(),L.end());
	L.sort();//默认从小到大
	printList(L);
	L.sort(compare);//使用一个回调函数
	printList(L);
}
//存储自定义类型
bool myComparePerson(Person& p1,Person& p2)
{
	if (p1.m_age < p2.m_age)
		return true;
	else
		return false;
}
void test02()
{
	list<Person>L;
	Person p1("zhangsan",15);
	Person p2("lisi", 17);
	Person p3("wangwu", 16);
	Person p4("zhaoliu", 13);
	Person p5("suanqi", 18);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);

	//对于自定义类型数据，必须指定排序规则
	L.sort(myComparePerson);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << it->m_name << " " << it->m_age << endl;
	}
}
int main()
{
	test01();
	test02();
	system("pause");
    return 0;
}


// STL֮List.cpp : �������̨Ӧ�ó������ڵ㡣
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
	return a > b;//��ʱ��ʾ����
}
/*
list ��ת����
reverse()//��ת��������list����1,3,5Ԫ�أ���ת֮�����5,3,1
sort()//list����
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
	//���в�֧��������ʵĵ�������������ϵͳ�ṩ���㷨
	//�����֧����ϵͳ�ṩ���㷨����ô������ڲ����ṩ
	//sort(L.begin(),L.end());
	L.sort();//Ĭ�ϴ�С����
	printList(L);
	L.sort(compare);//ʹ��һ���ص�����
	printList(L);
}
//�洢�Զ�������
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

	//�����Զ����������ݣ�����ָ���������
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


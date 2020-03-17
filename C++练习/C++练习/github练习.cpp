#include <iostream>
#include <time.h>
using namespace std;

void prim(int m, int n)
{
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	p1++;
	p = reinterpret_cast<char*>(p1);
	cout << p;
}
enum str
{
	x1,
	x2,
	x3 = 10

}x;

class CTest
{
public:
	CTest() :m_chData('\0'), m_nData(0)
	{
	}
	virtual void mem_fun() {}
private:
	char m_chData;
	int m_nData;
	static char s_chData;
};
char CTest::s_chData = '\0';

//下面的程序可以从0....n-1中随机等概率的输出m个不重复的数。这里我们假设n远大于m

/********************************************************************************************************
需满足三个条件：
(1)输出m个数,即cout<<i<<endl;语句执行m次
rand()%(n-i)>0,故当m<0时,rand()%(n-1)<m不成立,循环结束,所以第二个空应为m--
(2)不重复
由于i一直增长,所以不会输出重复值
(3)随机等概率
rand()函数保证随机
当i=0时，rand%(n-i)取值范围为0~n-1，总共n个数，只要rand()%(n-i)<m输出i=0的概率就为m/n。（小于号的原因是从0开始，取到m-1就总共m个数）。
当i=1时，rand%(n-i)取值范围为0~n-2，总共n-1个数，当i=0输出时，执行m--，当i=0未输出时，m的值不变，根据条件概率公式，输出i=1的概率
p=(m/n)*((m-1)/(n-1))+(1-m/n)*(m/(n-1))=m/n。
以此类推，每个数被输出的概率为m/n。
原理可参考抽签顺序和概率无关。
********************************************************************************************************/
void knuth(int n, int m)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < n; i++)
	{	
		
		if (rand() % (n - i) < m)	//此处保障的是等概率
		{	
			cout << "rand() % (n - i) =" << rand() % (n - i) << " i =" << i <<endl;
			m--;					// m--保障的是输出m个数
		}
	}
	cout << endl;
}

//取质因数
void primData(int m, int n)
{
	if (m > n)
	{
		while (m%n)
			n++;
		cout << "n =" << n << endl;
	}
}

//当数组作为函数的参数时会退化为指针
void example(char acWelcome[]) {
	printf("%d", sizeof(acWelcome));	//输出为4
	return;
}

//全局变量和静态局部变量的构造顺序
/*
C c;	//c的构造先于D
void construct()
{
	A*pa = new A();
	B b;
	static D d;
	delete pa;
}
这道题主要考察的知识点是 ：全局变量，静态局部变量，局部变量空间的堆分配和栈分配

其中全局变量和静态局部变量时从 静态存储区中划分的空间，
二者的区别在于作用域的不同，全局变量作用域大于静态局部变量（只用于声明它的函数中），
而之所以是先释放 D 在释放 C的原因是， 程序中首先调用的是 C的构造函数，然后调用的是 D 的构造函数，析构函数的调用与构造函数的调用顺序刚好相反。
*/


int main()
{	
	//cout << sizeof(CTest) << endl;
	//prim(4, 5);
	//cout << x << endl;
	//cout << "nice to meet you" << endl;
	//knuth(10,20);
	primData(10,5);
	char str[] = "hello world";
	cout << "sizeof(str)=" <<sizeof(str) << endl;// 12
	example(str);
	while (1);
	return 0;
}
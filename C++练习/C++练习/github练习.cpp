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

//����ĳ�����Դ�0....n-1������ȸ��ʵ����m�����ظ��������������Ǽ���nԶ����m

/********************************************************************************************************
����������������
(1)���m����,��cout<<i<<endl;���ִ��m��
rand()%(n-i)>0,�ʵ�m<0ʱ,rand()%(n-1)<m������,ѭ������,���Եڶ�����ӦΪm--
(2)���ظ�
����iһֱ����,���Բ�������ظ�ֵ
(3)����ȸ���
rand()������֤���
��i=0ʱ��rand%(n-i)ȡֵ��ΧΪ0~n-1���ܹ�n������ֻҪrand()%(n-i)<m���i=0�ĸ��ʾ�Ϊm/n����С�ںŵ�ԭ���Ǵ�0��ʼ��ȡ��m-1���ܹ�m��������
��i=1ʱ��rand%(n-i)ȡֵ��ΧΪ0~n-2���ܹ�n-1��������i=0���ʱ��ִ��m--����i=0δ���ʱ��m��ֵ���䣬�����������ʹ�ʽ�����i=1�ĸ���
p=(m/n)*((m-1)/(n-1))+(1-m/n)*(m/(n-1))=m/n��
�Դ����ƣ�ÿ����������ĸ���Ϊm/n��
ԭ��ɲο���ǩ˳��͸����޹ء�
********************************************************************************************************/
void knuth(int n, int m)
{
	srand((unsigned int)time(0));

	for (int i = 0; i < n; i++)
	{	
		
		if (rand() % (n - i) < m)	//�˴����ϵ��ǵȸ���
		{	
			cout << "rand() % (n - i) =" << rand() % (n - i) << " i =" << i <<endl;
			m--;					// m--���ϵ������m����
		}
	}
	cout << endl;
}

//ȡ������
void primData(int m, int n)
{
	if (m > n)
	{
		while (m%n)
			n++;
		cout << "n =" << n << endl;
	}
}

//��������Ϊ�����Ĳ���ʱ���˻�Ϊָ��
void example(char acWelcome[]) {
	printf("%d", sizeof(acWelcome));	//���Ϊ4
	return;
}

//ȫ�ֱ����;�̬�ֲ������Ĺ���˳��
/*
C c;	//c�Ĺ�������D
void construct()
{
	A*pa = new A();
	B b;
	static D d;
	delete pa;
}
�������Ҫ�����֪ʶ���� ��ȫ�ֱ�������̬�ֲ��������ֲ������ռ�Ķѷ����ջ����

����ȫ�ֱ����;�̬�ֲ�����ʱ�� ��̬�洢���л��ֵĿռ䣬
���ߵ���������������Ĳ�ͬ��ȫ�ֱ�����������ھ�̬�ֲ�������ֻ�����������ĺ����У���
��֮���������ͷ� D ���ͷ� C��ԭ���ǣ� ���������ȵ��õ��� C�Ĺ��캯����Ȼ����õ��� D �Ĺ��캯�������������ĵ����빹�캯���ĵ���˳��պ��෴��
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
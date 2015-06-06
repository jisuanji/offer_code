#include <iostream>
using namespace std;

class A;
A * arr[2];

class A
{
public :
	virtual int sum(int n)
	{
		return 0;
	}
};

class B: public A
{
public :
	int sum(int n)
	{
		return arr[!!n]->sum(n-1)+n;
	}
};

int getSum(int n)
{
	A a;
	B b;
	arr[0]=&a;
	arr[1]=&b;
	return b.sum(n);
}

//void main()
//{
//	cout<<getSum(5)<<endl;
//}

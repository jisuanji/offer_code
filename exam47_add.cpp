#include <iostream>
using namespace std;

int add(int n1, int n2)
{
	int sum;
	int carry;
	do{
		sum=n1^n2;
		carry=(n1&n2)<<1;
		n1=sum;
		n2=carry;
	}while(n2!=0);
	return sum;
}

//void main()
//{
//	cout<<"23 + 45 = "<<add(23, 45)<<endl;
//	cout<<"1 + 0 = "<<add(1, 0)<<endl;
//	cout<<"3 + 2 = "<<add(3, 2)<<endl;
//}
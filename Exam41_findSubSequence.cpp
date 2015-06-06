#include <iostream>
using namespace std;

void printfNumbers(int low, int high)
{
	for(int i=low; i<=high; i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
}

void printSubSequece(int n)
{
	int s=1;
	int b=2;
	int sum=b+s;
	while(s<b)
	{
		if(sum==n)
		{
			printfNumbers(s,b);
			b++;
			sum+=b;
		}
		if(sum<n)
		{
			b++;
			sum+=b;
		}
		else 
		{
			sum-=s;
			s++;
		}
	}
}

//void main()
//{
//	printSubSequece(100);
//}
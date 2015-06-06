#include <iostream>
using namespace std;

class UglyNumber
{
public:

	bool isSortUglyNumber(int number)
	{
		while(number%2==0)
			number/=2;
		while(number%3==0)
			number/=3;
		while(number%5==0)
			number/=5;
		return number==1 ? true : false;
	}

	int sortFindUglyNumber(int n)
	{
		//int * foundUglyNumbers = new int[n];

		int i=0;
		int cur=1;
		while(i<n)
		{
			if(isSortUglyNumber(cur))
			{
				i++;
			}
			cur++;
		}
		return cur-1;
	}

	int minThree(int n1, int n2, int n3)
	{
		return min(min(n1, n2), n3);
	}

	int accFindUglyNumber(int n)
	{
		if(n<=0)
			return 0;

		int * accUglynumbers = new int[n];		
		accUglynumbers[0]=1;

		int *p2;
		int *p3;
		int *p5;
		int minNumber;
		p2=p3=p5=accUglynumbers;
		int nextIndexUglyNumber=1;
		
		while(nextIndexUglyNumber<n)
		{
			minNumber=minThree((*p2)*2, (*p3)*3, (*p5)*5);
			accUglynumbers[nextIndexUglyNumber]=minNumber;

			while((*p2) * 2 <= minNumber)
				p2++;
			while((*p3) * 3 <= minNumber)
				p3++;
			while((*p5) * 5 <= minNumber)
				p5++;
			
			++nextIndexUglyNumber;
		}

		int ret=accUglynumbers[n-1];
		delete []accUglynumbers;
		return ret;
	}
};

//void main()
//{
//	UglyNumber ugly;
//
//	//cout<<ugly.sortFindUglyNumber(1500)<<endl;
//	cout<<ugly.accFindUglyNumber(2)<<endl;
//	cout<<ugly.accFindUglyNumber(3)<<endl;
//	cout<<ugly.accFindUglyNumber(5)<<endl;
//	cout<<ugly.accFindUglyNumber(6)<<endl;
//}

#include <iostream>
using namespace std;

void findTwoNumber(int nums[], int n)
{
	if(n<=1)
		return;
	int diff=0;
	for(int i=0; i<n; i++)
	{
		diff=diff^nums[i];
	}

	int nTh=1;
	for(int i=0; i<32; i++)
	{
		if(diff&nTh)
			break;
		else
			nTh<<=1;
	}

	int arr1_result=0;
	int arr2_result=0;

	for(int i=0; i<n; i++)
	{
		if(nums[i]&nTh)
			arr1_result=arr1_result^nums[i];
		else
			arr2_result=arr2_result^nums[i];
	}
	cout<<arr1_result<<endl;
	cout<<arr2_result<<endl;
}

//void main()
//{
//	int aa[]={1,1,3,4,5,
//			  7,7,8,9,0,
//			  4,5,8,9,0,
//			  6,6,2};
//
//	findTwoNumber(aa, 18);
//}
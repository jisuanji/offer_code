#include <iostream>
using namespace std;

int getFirtIndex(int nums[], int low, int high, int target)
{
	if(low>high)
		return -1;
	int mid;
	int ret;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(nums[mid]==target)
			break;
		else if(nums[mid]<target)
			low=mid+1;
		else 
			high=mid-1;
	}
	if(low>high)
		return -1;
	else
	{
		ret=getFirtIndex(nums, low, mid-1, target);
		if(ret!=-1)
			return ret;
		else
			return mid;
	}
}

int getLastIndex(int nums[], int low, int high, int target)
{
	if(low>high)
		return -1;
	int mid;
	int ret;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(nums[mid]==target)
			break;
		else if(nums[mid]<target)
			low=mid+1;
		else 
			high=mid-1;
	}
	if(low>high)
		return -1;
	else
	{
		ret=getLastIndex(nums, mid+1, high, target);
		if(ret!=-1)
			return ret;
		else
			return mid;
	}
}

int getTimesInArr(int nums[], int n, int target)
{
	if(nums==NULL || n<=0)
		return 0;
	int left, right;
	left=getFirtIndex(nums, 0, n-1, target);
	right=getLastIndex(nums, 0, n-1, target);
	if(left!=-1 && right!=-1)
		return right-left+1;
	else
		return 0;
}

//void main()
//{
//	int aa[]={1,2,3,3,4,
//			  4,4,4,5,6,
//			  6,7,7,7,8,
//			  9,9};
//	cout<<getTimesInArr(aa, 17, 10)<<endl;
//}
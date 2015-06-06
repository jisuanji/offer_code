#include <iostream>
#include <algorithm>
using namespace std;

int compare44(const void * data1, const void * data2)
{
	return *(int*)data1 - *(int*)data2;
}

bool isContinuous(int * nums, int len)
{
	if(len<=0 || nums==NULL)
		return false;

	qsort(nums, len, sizeof(int), compare44);

	int numberOfZere=0;
	for(int i=0; i<len && nums[i]==0; i++)
		numberOfZere++;

	int start=numberOfZere+1;
	int gaps=0;
	for(; start<len; start++)
	{
		if(nums[start]==nums[start-1])
			return false;
		gaps+=nums[start]-nums[start-1]-1;
	}
	return gaps==numberOfZere ? true : false;
}

//void main()
//{
//
//}
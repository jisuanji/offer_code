#include <iostream>
#include <vector>
using namespace std;

class MoreThanHalf
{
public:
	int moreData(vector<int> &datas)
	{
		if(datas.size()==0)
			return 0;
		int size=datas.size();
		int result=datas[0];
		int times=1;
		for(int i=1; i<size; i++)
		{
			if(datas[i]==result)
				times++;
			else
			{
				times--;
				if(times==0)
				{
					result=datas[i];
					times=1;
				}
			}
		}
		
		if(!isMoreThanHalf(datas, result))
			return 0;

		return result;
	}

	bool isMoreThanHalf(vector<int>& vec, int num)
	{
		int times=0;
		for(int i=0; i<vec.size(); i++)
		{
			if(vec[i]==num)
				times++;
		}
		if(times<(vec.size()>>2+1))
			return false;
		else
			return true;
	}

};

//void main()
//{
//	int aa[]={1,2,22,2,2,
//			  2,2,2,4,4,5,
//			  6,4,2,2,2,3,
//			  4,5,4,5,4,2,
//			  6,2,2,2,2,2,
//			  2,2,7};
//	vector<int> vec(aa, aa+32);
//	MoreThanHalf more;
//	cout<<more.moreData(vec)<<endl;
//}
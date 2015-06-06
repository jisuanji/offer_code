#include <iostream>
#include <set>
#include <functional>
#include <vector>
//#include <algorithm>
using namespace std;

vector<int> GetLessKNumbers(vector<int> & data, int k)
{
	vector<int> ret;
	if(k<=0 || data.size()==0 || k>data.size())
		return ret;
	ret.resize(k);
	multiset<int, greater<int>> mul;
	for(int i=0; i<k; i++)
		mul.insert(data[i]);

	multiset<int>::iterator ito;
	for(int i=k; i<data.size(); i++)
	{
		ito=mul.begin();
		if(*ito>data[i])
		{
			mul.erase(ito);
			mul.insert(data[i]);
		}
	}
	
	int i;
	for(i=k-1, ito=mul.begin(); ito!=mul.end() && i>=0; ito++,i--)
	{
		ret[i]=(*ito);
	}

	return ret;
}
//
//void main()
//{
//	int aa[]={2,3,5,7,8,
//			  1,2,6,4,3,
//			  2,7,56,34,23,
//			  1,2,54,6};
//	vector<int> vec(aa, aa+19);
//	vector<int> data;
//
//	data=GetLessKNumbers(vec, 10);
//	for(int i=0; i<data.size(); i++)
//	{
//		cout<<data[i]<<"\t";
//	}
//	cout<<endl;
//}
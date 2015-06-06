#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char g_combine1[40];
char g_combine2[40];

int compare(const void * str1, const void * str2)
{
	strcpy(g_combine1, (char *)str1);
	strcat(g_combine1, (char *)str2);

	strcpy(g_combine2, (char *)str2);
	strcat(g_combine2, (char *)str1);
	return strcmp(g_combine1, g_combine2);
}

bool cmp(string & str1, string & str2)
{
	string st1;
	string st2;

	st1=str1;
	st1+=str2;
	
	st2=str2;
	st2+=str1;

	return st1.compare(st2.c_str())<0 ? true : false;
}

string sortArray(vector<int> & vec)
{
	string ret;
	if(vec.size()==0)
		return ret;
	
	vector<string> data_str(vec.size());
	char tmp_char[20];

	for(int i=0; i<vec.size(); i++)
	{
		sprintf(tmp_char, "%d", vec[i]);
		data_str[i]+=tmp_char;
	}

	//qsort(&data_str[0], data_str.size(), sizeof(string), compare);
	sort(data_str.begin(), data_str.end(), cmp);

	for(int i=0; i<data_str.size(); i++)
		ret+=data_str[i];
	return ret;
}

//void main()
//{
//	int aa[]={3,32,31};
//	vector<int> vec(aa, aa+3);
//	string ret;
//	ret=sortArray(vec);
//	cout<<ret.c_str()<<endl;
//}
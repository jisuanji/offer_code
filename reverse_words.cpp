#include <iostream>
using namespace std;

void reverse(string &s, int low, int high){
    char tmp;
    while(low<high)
    {
        tmp=s[low];
        s[low]=s[high];
        s[high]=tmp;
        low++;
        high--;
    }
}

void reverseWords(string &s) {
    int idx=0;
    int i=0;
    int len=s.size();
        
    //remove all spaces
    while(i<len)
    {
        while(i<len && s[i]==' ') i++;
		if(i==len)
			break;
        while(i<len && s[i]!=' ') s[idx++]=s[i++];
		
		if(i<len)
			s[idx++]=' ';
    }

	if(idx==0)
	{
		s="";
		return ;
	}

	if(s[idx-1]==' ')
		s.resize(idx-1);
	else
		s.resize(idx);

	len=s.size();
    reverse(s, 0, len-1);
        
    int l=0, r=0;
    while(r<len)
    {
        while(r<len && s[r]!=' ') r++;
        reverse(s, l, r-1);
        l=r+1;
        r++;
    }
}

//void main()
//{
//	string s="abc";
//	reverseWords(s);
//	cout<<s.c_str()<<endl;
//}
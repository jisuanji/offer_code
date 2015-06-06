#include <iostream>
using namespace std;

class AddDataNoSignal
{
public:
	AddDataNoSignal(){
		++N;
		sum+=N;
	};
	int GetNum()
	{
		return sum;
	}

private:
	static int N;
	static int sum;
};

int AddDataNoSignal::N=0;
int AddDataNoSignal::sum=0;

int returnSum(int n)
{
	AddDataNoSignal *datas=new AddDataNoSignal[n];
	int ret=datas->GetNum();
	delete datas;
	return ret;
}

//void main()
//{
//	cout<<returnSum(6)<<endl;
//}
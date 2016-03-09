/*with temp.variable*/
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cout<<"X ";
	cin>>a;
	if(a<=1 || a>=10000000)
		return -1;
	else
	{
		cout<<"Y ";
		cin>>b;
		if(b<=1 || b>=10000000)
			return -1;
		else
		{
			int t;
			t=a;
			a=b;
			b=t;
			cout<<"X "<<a<<"     "<<"Y "<<b<<endl;
		}
	}
	return 0;
}

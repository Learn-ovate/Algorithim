/* Reference passing */
#include<iostream>
using namespace std;
void change(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
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
			change(a,b);
			cout<<"X "<<a<<"     "<<"Y "<<b<<endl;
		}
	}
	return 0;
}

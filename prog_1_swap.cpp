#include<iostream>
#include<cstdlib>

using namespace std;

main()
{
	int x,y,temp;
	cout<<"enter x and y (between 1 and 10000000): ";
	cin>>x>>y;
	if((x<1 && x>10000000)||(y<1 && y>10000000))	
	{
		cout<<"entered no is wrong\n";
		exit(1);
	}
	temp=x;
	x=y;
	y=temp;
	
	cout<<"After swapping...\n";
	cout<<"x:" <<x<<endl<<"y:"<<y<<endl;
	
}


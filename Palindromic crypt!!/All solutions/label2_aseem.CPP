#include<iostream.h>
#include<conio.h>

int x,y;

void method1();
void method2();
void method3();

void main()
{
	clrscr();
	cout<<"Enter the values of x and y : ";
	cin>>x>>y;
	cout<<"\n\n1st method:\n";
	method1();
	cout<<"\n\n2nd method:\n";
	method2();
	cout<<"\n\n3rd method:\n";
	method3();
	getch();

}

void method1()
{
	cout<<"Initially "<<"x= "<<x<<" and y= "<<y<<endl;
	int temp;
	temp=x;
	x=y;
	y=temp;
	cout<<"Finally "<<"x= "<<x<<" and y= "<<y<<endl;
}

void method2()
{
	cout<<"Initially "<<"x= "<<x<<" and y= "<<y<<endl;
	x=x+y;
	y=x-y;
	x=x-y;
	cout<<"Finally "<<"x= "<<x<<" and y= "<<y<<endl;
}

void method3()
{
	cout<<"Initially "<<"x= "<<x<<" and y= "<<y<<endl;
	x=x*y;
	y=x/y;
	x=x/y;
	cout<<"Finally "<<"x= "<<x<<" and y= "<<y<<endl;
}
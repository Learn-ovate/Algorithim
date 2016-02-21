#include<stdio.h>
#include<conio.h>

void swap(float x,float y)
{
	float temp;
	temp=x;
	x=y;
	y=temp;
	printf("\n First Number is %f",x);
	printf("\n Second Number is %f",y);
}

void main()
{
	float a,b;
	clrscr();
	printf("\n Enter First Number: ");
	scanf("%f",&a);
	printf("\n Enter Second Number: ");
	scanf("%f",&b);
	swap(a,b);
	getch();
}
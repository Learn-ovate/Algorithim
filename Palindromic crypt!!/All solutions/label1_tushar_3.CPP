#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	float info;
	struct node *next;
}node;

node* a1;
node* a2;




void swap()
{
	float temp;
	temp=a1->info;
	a1->info=a2->info;
	a2->info=temp;
}

void main()
{
	float a,b;
	clrscr();
	printf("\n Enter First Number: ");
	scanf("%f",&a);
	a1=(node*)malloc(sizeof(a));
	a1->info=a;
	a1->next=NULL;
	printf("\n Enter Second Number: ");
	scanf("%f",&b);
	a2=(node*)malloc(sizeof(b));
	a2->info=b;
	a2->next=NULL;
	swap();
	printf("\n First Number is %f",a1->info);
	printf("\n Second Number is %f",a2->info);
	getch();
}
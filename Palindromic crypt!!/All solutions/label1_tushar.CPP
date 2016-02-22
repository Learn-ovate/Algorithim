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
node* temp;

void swapref_l()
{
	temp=a1;
	a1=a2;
	a2=temp;
}

void swapval_l()
{
	float temp;
	temp=a1->info;
	a1->info=a2->info;
	a2->info=temp;
}


void swapref(float *x,float *y)
{
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void swapvar(float x,float y)
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
	int ch;
	clrscr();
	printf("\n 1. Swap by Reference");
	printf("\n 2. Swap by Value");
	printf("\n 3. Swap by Linked List value");
	printf("\n 4. Swap by Linked List Address");
	printf("\n Enter your choice: ");
	scanf("%d",&ch);
	printf("\n Enter First Number: ");
	scanf("%f",&a);
	printf("\n Enter Second Number: ");
	scanf("%f",&b);

	switch(ch)
	{
		case 1:	swapref(&a,&b);
			printf("\n First Number is %f ",a);
			printf("\n Second Number is %f ",b);
			break;
		case 2:	swapvar(a,b);
			break;
		case 3:	a1=(node*)malloc(sizeof(a));
			a1->info=a;
			a1->next=NULL;
			a2=(node*)malloc(sizeof(b));
			a2->info=b;
			a2->next=NULL;
			swapval_l();
			printf("\n First Number is %f",a1->info);
			printf("\n Second Number is %f",a2->info);
			break;
		case 4:	a1=(node*)malloc(sizeof(a));
			a1->info=a;
			a1->next=NULL;
			a2=(node*)malloc(sizeof(b));
			a2->info=b;
			a2->next=NULL;
			swapref_l();
			printf("\n First Number is %f",a1->info);
			printf("\n Second Number is %f",a2->info);
			break;
	}
	getch();
}


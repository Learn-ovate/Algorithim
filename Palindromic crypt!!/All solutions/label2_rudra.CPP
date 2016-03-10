#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20

typedef struct stack
{
	char a[max];
	int top;
}stack;
stack s;
stack s1;

char pop()
{
	char n;
	n=s.a[s.top];
	s.top=s.top-1;
	return n;
}

void push(char x)
{
	s.top=s.top+1;
	s.a[s.top]=x;
}

char pop1()
{
	char n;
	n=s1.a[s1.top];
	s1.top=s1.top-1;
	return n;
}

void push1(char x)
{
	s1.top=s1.top+1;
	s1.a[s1.top]=x;
}

int precedence(char x)
{

	int prevalue;
	if(x=='+')
		prevalue=1;
	else if(x=='-')
		prevalue=1;
	else if(x=='*')
		prevalue=2;
	else if(x=='/')
		prevalue=2;
	else if(x=='^')
		prevalue=3;
	else if(x=='$')
		prevalue=3;
	else
		prevalue=0;
	return prevalue;
}

void main()
{
	int retry,prehand,prestack,count=0,i,temp;
	char x;
	clrscr();
	s.top=-1;
	s1.top=-1;
	printf("Enter the equation in postfix:");

	while ((x=getchar()) != '\n')
	{
//		printf("\n::  %c  ::",x);

		if(isalpha(x))
		{
			push(x);
			count++;
		}
		else
		{

			do
			{
				if(x=='(')
				{
					push1(x);
				}
				else if(x==')')
				{
					while(temp !='(')
					{
						temp=pop1();
						if (temp=='(' || temp==')')
						{

						}
						else
						{
							push(temp);
							count++;
						}
					}
				}
				else
				{
				retry=0;
				prehand=precedence(x);
				temp=pop1();
//				printf("\n temp= %c",temp);
				prestack=precedence(temp);
//				printf("\n Prehand = %d",prehand);
//				printf("\n Prestack = %d",prestack);
				if(prehand<=prestack)
				{
					push(temp);
					retry=1;
					count++;
				}
				else
				{
					push1(temp);
					push1(x);
				}
//				printf("\n Retry = %d ",retry);
				}
			}while(retry==1);

		}
	}

//	printf("\n Count = %d",count);

	printf("\n The answer of the postfix expression is : ");
	for(i=0;i<=count;i++)
	{
		printf("%c ",s.a[i]);
	}
	while(s1.top != (-1) || temp!= '(')
	{
		temp=pop1();
		if (temp=='(' || temp==')')
		{

		}
		else
			printf("%c ",temp);
	}



	getch();

}
//infix to postfix conversion

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
struct stck
{
	char item[MAX];
	int top;
};

void push(struct stck *,char);
char pop(struct stck *);
void display(struct stck);
int prior(char);

int main()
{
	struct stck s;
	int i=0,j=0;
	char in[MAX],out[MAX];
	s.top=-1;
	printf("\n Enter the string(infix) =\n");
	scanf("%s",in);
	while(in[i]!='\0')
	{
		if(isalpha(in[i]))
		{
			out[j]=in[i];
			j++;
		}
		else
		{
			if(s.top==-1)
			{
				push(&s,in[i]);
			}
			else
			{
				if(prior(in[i]) < prior(s.item[s.top]))
				{
					while(prior(in[i]) < prior(s.item[s.top]))
					{
						out[j]=pop(&s);
						j++;
					}
					if(prior(in[i]) == prior(s.item[s.top]))
					{
						out[j]=pop(&s);
						j++;
					}
					push(&s,in[i]);
				}
				else if(prior(in[i]) == prior(s.item[s.top]))
				{
					if(prior(in[i])==1 || prior(in[i])==2)
					{
						out[j]=pop(&s);
						j++;
						push(&s,in[i]);
					}
					else //prior(in[i]==3)
					{
						push(&s,in[i]);
					}
				}
				else
				{
					push(&s,in[i]);
				}
			}
		}
		i++;
	}
	printf("\n");
	display(s);
	while(s.top!=-1)
	{
		out[j]=pop(&s);
		j++;
	}out[j]='\0';
	printf("\nOutput(postfix) = %s\n",out);
	return 0;
}

void push(struct stck *s,char a)
{
	if(s->top==MAX-1)
	{
		printf("\n Overflow");
		return;
	}
	s->item[++(s->top)]=a;
}
char pop(struct stck *s)
{
	if(s->top==-1)
	{
		printf("\n Underflow");
		return ;
	}
	return s->item[s->top--];
}
void display(struct stck s)
{
	while(s.top!=-1)
	{
		printf("%c",s.item[s.top--]);
	}
}
int prior(char a)
{
	if(a=='+' || a=='-')
		return 1;
	else if(a=='*' || a=='/')
		return 2;
	else if(a=='$')
		return 3;
}

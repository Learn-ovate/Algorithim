#define MAX 50
#include<stdio.h>
#include<ctype.h>

struct stack
{
	int top;
	int item[MAX];
};

void push(struct stack *, char);
int pop(struct stack *);
int peep(struct stack *);
int empty(struct stack *);
int preced(char , char );
int priority(char ,char *);

main()
{
	char infix[50], postfix[50], symb, temp;
	struct stack s;
	int i=0,j=0;
	
	s.top=-1;
	printf("\nEnter IINFIX expresion: \n");
	scanf("%s",infix);
	
	while(infix[i]!='\0')
	{
		symb=infix[i];
		if((65<=symb && symb<=90) || (97<=symb && symb<=122))
		{
			postfix[j]=symb;
			j++;
		}
		else
		{
			while(!empty(&s) && preced(peep(&s),symb))
			{
				postfix[j]=pop(&s);
				j++;
			}
			
			if(empty(&s) || symb!=')')
			{
				push(&s,symb);
			}
			else
				temp=pop(&s);
		}
		
		i++;
	}
	
	while(!empty(&s))
	{
		postfix[j]=pop(&s);
		j++;
	}
	postfix[j]='\0';
	
	printf("\npostfix: \n%s\n", postfix);
	
	
}


int empty(struct stack *ps)
{
	if(ps->top==-1)
		return 1;
	return 0;
	
}


void push(struct stack *ps, char ch)
{
	 ps->top++;
	 ps->item[ps->top]=ch;
}


int pop(struct stack *ps)
{
	int x;
	x=ps->item[ps->top];
	ps->top--;
	return x;
}


int peep(struct stack *ps)
{
	int x;
	x=ps->item[ps->top];
	return x;
}

int preced(char stc, char symb)
{
	int p1,p2;
	char j1,j2;
	
	if(stc=='(')
		return 0;
		
	else if(symb==')')
		return 1;

	else if(symb=='(')
		return 0;
		
	else
	{
		p1=priority(stc,&j1);
		p2=priority(symb,&j2);
		
		if(p1>p2)
			return 1;
		else if(p1<p2)
			return 0;
		else
		{
			if(j1=='l')
				return 1;
			else
				return 0;
			
		}
	}
	
}

int priority(char c,char *j)
{
	*j='l';
	switch(c)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '$': *j='r';
			return 3;
		
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
typedef int bool;
 
#define TRUE 1
#define FALSE 0
#define MAX 100
 
typedef struct {
	int top;
	char items[MAX];
} stack;
 
void push(stack *s, char c);
char pop(stack *s);
char peek(stack *s);
bool empty(stack *s);
void itop(char *infix, char *postfix);
bool preced(char stk, char cur);
int prior(char op, char *j);
void print(stack *s);
 
int main(void)
{
	char inf[500];
	char post[500];
	scanf("%s", inf);
	itop(inf, post);
	puts(post);
	return 0;
}
 
void push(stack *s, char c)
{
	if (s->top == MAX - 1)
	{
		exit(1);
	}
    s->top += 1;
	s->items[s->top] = c;
 
}
 
char pop(stack *s)
{
	if (s->top == -1)
	{
		exit(1);
	}
    char r = s->items[s->top];
    s->top -= 1;
	return r;
}
 
char peek(stack *s)
{
	if (s->top == -1)
	{
		exit(1);
	}
	return s->items[s->top];
}
 
bool empty(stack *s)
{
	if (s->top == -1) return TRUE;
	return FALSE;
}
 
void itop(char *infix, char *postfix)
{
	stack s;
	s.top = -1;
    int i, j = 0;
	for (i = 0; infix[i] != '\0'; i++)
	{
		char symb = infix[i];
		if (isalnum(symb))
		{
			postfix[j] = symb;
			j++;
		}
 
		else
		{
			while(!empty(&s) && preced(peek(&s), symb))
			{
				postfix[j] = pop(&s);
				j++;
			}
 
            if (empty(&s) || symb != ')')
            {
                push(&s, symb);
            }
 
			else pop(&s);
 
		}
 
	}
    while(!empty(&s))
	{
		postfix[j] = pop(&s);
		j++;
	}
	postfix[j] = '\0';
}
 
bool preced(char stk, char cur)
{
	if (stk == '(') return FALSE;
	else if (cur == '(') return FALSE;
	else if (cur == ')') return TRUE;
 
	char jus;
 
	int p_stk = prior(stk, &jus);
	int p_cur = prior(cur, &jus);
 
	if (p_stk < p_cur) return FALSE;
	else if (p_stk > p_cur) return TRUE;
 
	else
	{
		if (jus == 'L') return TRUE;
		else return FALSE;
	}
}
 
int prior(char op, char *j)
{
	*j = 'L';
	switch (op)
	{
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
		case '^':
			*j = 'R';
			return 3;
			break;
	}
	return 0;
}
 
void print(stack *s)
{
    int i = s->top;
    while(i-- >= 0)
    {
        printf("%c", s->items[i]);
    }
}
 

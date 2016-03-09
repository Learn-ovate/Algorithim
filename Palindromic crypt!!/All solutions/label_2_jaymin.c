#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
struct stack
{
    char data[MAX];
    int top;
};

int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '/' || x == '*')
        return 2;
}
char pop(struct stack *s)
{
    if(s->top==-1)
    {
        exit(1);
    }
    char x;
    x = s->data[s->top];
    (s->top)--;
    return x;
}
void push(struct stack *s,char x)
{
    if(s->top==MAX-1)
        exit(0);
    (s->top)++;
    s->data[s->top] = x;
}
char top(struct stack *s)
{
        return (s->data[s->top]);
}

int main()
{
    struct stack s;
    char x,temp,infix[MAX],postfix[MAX];
    int i=0,j=0;
    s.top = -1;
    printf("\nenter a infix expression - ");
    scanf("%s",&infix);
    for(i=0;infix[i]!='\0';i++)
    {
        temp=infix[i];
        if(isalnum(temp))
        {
            postfix[j++]=temp;
        }
        else
        {
            if(temp=='(')
            {
                push(&s,'(');
            }
            else
            {
                if(temp==')')
                {
                    while((x=pop(&s))!='(')
                        postfix[j++]=x;
                }
                    else
                    {
                        while(priority(temp)<=priority(top(&s))&&!(s.top == -1))
                        {
                            x=pop(&s);
                            postfix[j++]=x;
                        }
                        push(&s,temp);
                    }
                }
            }
        }

    while(!(s.top==-1))
    {
        x=pop(&s);
        postfix[j++]=x;
    }

    postfix[j]='\0';
    for(i=0;i<strlen(postfix);i++)
    {
        printf("%c",postfix[i]);
    }
    return 0;
}

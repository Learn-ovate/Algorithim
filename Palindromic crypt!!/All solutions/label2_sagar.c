#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int top;
    char str[25];
} stack;

void intopost(stack *,char[],char[]);
int prec(char );

int main()
{
    stack s;
    int c,i;
    char postfix[25],string[25];

    s.top=-1;

    printf("Enter INFIX expression:");
    scanf("%s",string);

    intopost(&s,string,postfix);

    printf("\nPOSTFIX expression is:\t%s\n",postfix);

    return 0;
}

void intopost(stack *s,char string[25],char ans[25])
{
    int j=-1,i,mod=1,c=0;
    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]=='(')
        {
            c++;
            s->str[++s->top]=string[i];
        }

        if(string[i]==')')
        {
            while(s->str[s->top]!='(')
                ans[++j]=s->str[s->top--];
            s->top--;
        }

        if(isalnum(string[i]))
            ans[++j]=string[i];

        else if(!isalnum(string[i]) && s->top==-1)
            s->str[++s->top]=string[i];

        else if(!isalnum(string[i]) && prec(string[i])>prec(s->str[s->top]))
            s->str[++s->top]=string[i];

        else if(!isalnum(string[i]) && prec(string[i])<prec(s->str[s->top]))
        {
            ans[++j]=s->str[s->top--];
            s->str[++s->top]=string[i];
        }
    }
    while(s->top!=-1)
        ans[++j]=s->str[s->top--];
    ans[(++j) - c]='\0';
}

int prec(char c)
{
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    if(c=='(' || c==')')
        return 0;
}

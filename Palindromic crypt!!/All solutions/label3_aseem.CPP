#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50            	//size of stack

char s[MAX];
int top=-1;       
 
void push(char elem)				//push function
{
    s[++top]=elem;
}

char pop()					//pop function
{                      
    return(s[top--]);
}
 
int pr(char elem)			//function for checking priority
{                 
    switch(elem)
    {
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}

int isoperator(char elem)			//function for checking priority
{                 
    switch(elem)
    {
    case '(':
	case ')':
    case '+':
    case '-':
    case '*':
    case '/': return 1;
	default: return 0;
    }
}

void main()
{
    clrscr();
    char infx[MAX],prfx[MAX],ch,elem;
    int i=0,k=0;
    printf("\t\tINFIX TO PREFIX\n\nEnter the Infix Expression:");
    scanf("%s",infx);
    strrev(infx);
    while( (infx[i]) != '\0')
    {
		ch=infx[i];
	if(ch == ')')
			push(ch);
	else
	    if(isoperator(ch)==0)
				prfx[k++]=ch;
	    else
		if( ch == '(')
		{
		    while( s[top] != ')')
			prfx[k++]=pop();
		    elem=pop();
		}
		else if(isoperator(ch)==1)
		{
		    while( pr(s[top]) >= pr(ch) )
			prfx[k++]=pop();
		    push(ch);
		}
		i++;
    }
    while( top!=-1)     /* Pop from stack till empty */
	prfx[k++]=pop();
    prfx[k]='\0';          /* Make prfx as valid string */
    strrev(prfx);
    strrev(infx);
    printf("\n\nPrefix Experession is: %s\n",prfx);
    getch();
}
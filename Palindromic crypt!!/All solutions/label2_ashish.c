//Name : Ashish Musani
//Github Id : ashishmusani

//Fully parenthesized infix to postfix conversion
//Input should be of the form : (a+((b*c)*(d+e)))) <-- extra bracket at end is required


#include <stdio.h>
#define n 100

int top=-1;
int rank=0;

void PUSH(char s[], char X)
{
    if(top==n-1)
    {
        printf("----------------\nStack overflow!\n");
        return;
    }

    top++;
    s[top] = X;
    return;
}

int RANK(char t)
{
    switch(t)
    {
    case '+':
        return -1;
    case '-':
        return -1;
    case '*':
        return -1;
    case '/':
        return -1;
    case '^':
        return -1;
    default:
        return 1;
    }
}

int F(char t)
{
    switch(t)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 3;
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int G(char t)
{
    switch(t)
    {
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 4;
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    default:
        return 8;
    }
}


char POP(char s[])
{
    if(top<0)
    {
        printf("----------------\nStack underflow!\n");
        return -9999999;
    }

    top--;
    return s[top+1];
}

void main()
{
    char stack[50];
    char expression[100];
    int count;
    char temp;

    printf("Enter infix expression : ");
    scanf("%s", &expression);

    PUSH(stack, '(');

    for(count=0;count<strlen(expression);count++)
    {
        if (top<0)
        {
            printf("Invalid expression.\n");
            exit (0);
        }

        while(F(expression[count])<G(stack[top]))
        {
            temp = POP(stack);
            printf("%c",temp);
            rank+= RANK(temp);
            if (rank<1)
            {
                printf("Invalid Expression.\n");
                exit (0);
            }
        }

        if (F(expression[count])!=G(stack[top]))
            PUSH(stack,expression[count]);
        else
            POP(stack);
    }
}

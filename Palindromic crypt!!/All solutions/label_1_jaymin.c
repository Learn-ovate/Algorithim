#include<stdio.h>
#include<stdlib.h>
void swap_by_temp_var(int a,int b)
{
    int t;  //temporary variable
    t = a;
    a = b;
    b = t;
    displayit(a,b);
}
void swap_without_temp_var(int a,int b)
{
    a = a+b;
    b = a-b;
    a = a-b;
    displayit(a,b);
}
void swap_by_pointers(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b =temp;
}
void displayit(int a,int b)
{
    printf("a is %d \t b is %d",a,b);
}
void display(int *a,int *b)
{
    printf("a is %o \t b is %d",*a,*b);
}
int main()
{
    int a,b,ch;
    do{

        printf("\n\n===for swapping===\n");
        printf("1)swap using temporary variable\n");
        printf("2)swap without temporary variable\n");
        printf("3)swapping with pointers\n4)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nenter a and b - \n" );
                scanf("%d",&a);
                scanf("%d",&b);
                printf("\nbefore swapping\n");
                displayit(a,b);
                printf("\nafter swapping\n");
                swap_by_temp_var(a,b);
                break;
            case 2:
                printf("\nenter a and b - \n" );
                scanf("%d",&a);
                scanf("%d",&b);
                printf("\nbefore swapping\n");
                displayit(a,b);
                printf("\nafter swapping\n");
                swap_without_temp_var(a,b);
                break;
            case 3:
                printf("\nenter a and b - \n" );
                scanf("%d",&a);
                scanf("%d",&b);
                printf("\nbefore swapping\n");
                display(&a,&b);
                printf("\nafter swapping\n");
                swap_by_pointers(&a,&b);
                display(&a,&b);
                break;
            case 4: exit(1);
        }
    }while(ch>0 && ch<=3);
return 0;
}

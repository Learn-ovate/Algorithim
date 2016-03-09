#include<stdio.h>

int main()
{
    long int x,y;
    int temp;

    printf("Enter value of x between 1 and 10000000\n");
    scanf("%d",&x);
    if(x<1 ||  x>10000000)
        {
            printf("Enter valid input\n");
            exit(1);
        }
    else
    {
            printf("Enter the value of y between 1 and 10000000\n");
            scanf("%d",&y);
             if(y<1 ||  y>10000000)
            {
                printf("Enter valid input\n");
                exit(1);
            }
            else
            {
                    temp=x;
                    x=y;
                    y=temp;
            }
    }

    printf("X=%ld and y=%ld",x,y);

    return 0;
}

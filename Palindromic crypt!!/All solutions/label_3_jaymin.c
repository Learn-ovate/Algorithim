#include <stdio.h>
int palindrom_prime(int n)
{
    int c = 0,flag=0,reverse=0, rem,temp=n,answer,i;
     while(temp!=0)
    {
        rem=temp%10;
        reverse=(reverse*10)+rem;
        temp=temp/10;
    }
    if(reverse==n)
    {
        for (i = 1; i <= n; i++) {
          if (n % i == 0) {
             c++;
          }
        }
        if (c == 2) {
            answer = n;
            return 1;
        }
        return 0;
    }
    else
        return 0;

}
int main() {
    int j,n,i;
    printf("Enter any number n:");
    scanf("%d", &n);
    if(n>=1 && n<=15000)
    {
        for(i=n;i<15000;i++)
        {
            if(palindrom_prime(i)==1)
            {
                j=i;
                break;
            }
            else
                continue;

        }
    }
    printf("%d",j);
    j = j>>5;
    printf("  %d",j);
  return 0;
}

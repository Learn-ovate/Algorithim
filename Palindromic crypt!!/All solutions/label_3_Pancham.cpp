#include<stdio.h>
#include<conio.h>
#include<math.h>
#define TRUE 1
void main()
{
  int temp,reverse=0,rem=0,a,i,num;
  clrscr();
  printf("Enter a number: ");
  scanf("%d",&num);
  while(TRUE)
  {
    num++;
    temp=num;
    while(temp!=0)
    {
      rem=temp%10;
      reverse=reverse*1+rem;
      temp=temp/10;
    }
    if(reverse==num)
    {
      i=(int)sqrt(num);
      
      for(a=2;a<=2;a++)
      {
        if(num%a==0)
          break;
      }
      if(a==i+1)
        break;
      }
      reverse=0;
}
printf("%d, %d",num,num>>5);
getch();
}
      

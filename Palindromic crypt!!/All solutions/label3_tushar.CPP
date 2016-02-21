#include<stdio.h>
#include<conio.h>

void main()
{
	int no,mainflag,palflag,primeflag,i,i1,i2,sum,temp,j,countprime=0,countpal=0;
	int final,ans=1,ans1=1,ch,ch1;
	clrscr();
	printf("\n Enter the number: ");
	scanf("%d",&no);
	mainflag=0;
	i=no;
	while(mainflag!=1)
	{
		i1=i;
		sum=0;
		palflag=0;
		while(i1!=0)
		{
			temp=i1%10;
			i1=i1/10;
			sum=(sum*10)+temp;
		}
		if(sum==i)
		{
			countpal++;
			palflag=1;
		}

		i2=i;
		primeflag=0;
		for(j=2;j<i2;j++)
		{
			if(i2%j==0)
			{
				primeflag=1;
				break;
			}
		}
		if(primeflag==0)
			countprime++;

		if (primeflag==0 && palflag==1)
		{
			mainflag=1;
		}
		i++;
	}
	ch=no;
	ch1=i-1;
	while(ch!=0)
	{
		temp=ch%10;
		ch=ch/10;
		ans=ans*temp;
	}
	while(ch1!=0)
	{
		temp=ch1%10;
		ch1=ch1/10;
		ans1=ans1*temp;
	}

	if(ans>ans1)
	{
		final=ans-ans1;
	}
	else
	{
		final=ans1-ans;
	}



	printf("\n The number is %d.",i-1);
	printf("\n Second Logic is %d.",final);


	getch();
}
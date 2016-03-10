#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

int isprime(int a)
{
int b,flag=1;
for(b=2;b<a;b++)
{
	if(a%b==0)
	{
	      flag=0;
	      break;
	}
}
if(flag==1)
return 1;
else
return 0;
}

void main()
{
	clrscr();
	int in,temp1=0,temp2=0;
	cin>>in;
	while(1)
	{
		temp1=in;
		temp2=0;
		cout<<temp1<<endl;
		while(temp1!=0)
		{
			//cout<<temp1<<" "<<temp2<<endl;
			temp2=(temp2*10)+temp1%10;
			temp1=temp1/10;
			//cout<<temp1<<" "<<temp2<<endl;
		}
		if(temp2==in)
		{
			if(isprime(in)==1)
			{
				//cout<<endl<<in;//output line 1
				//i am not able to figure out the encryption method :((
				exit(1);
			}
			else
				in++;
		}
		else
			in++;
	}
}

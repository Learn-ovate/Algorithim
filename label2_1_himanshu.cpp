#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

class st
{
	int top,j=-1;
	char arr[100],ans[100],sta[100];
public:
	st(void)
	{	top=-1;}
	void push(char a)
	{
		if(top==MAX-1)
			cout << "Stack is Overflow Now";	
		else
		{	sta[++top]=a;}
	}
	void ins()
	{	cin >> arr;}
	void display()
	{	//cout << "Answer is " << ans;
		int i;
		for(i=0;i<j;i++)
		{cout << ans[i];}
	}
	void post()
	{	int i=0;
		char k;
		for(i=0;i<strlen(arr);i++)
		{	
			k=arr[i];
			if(isalnum(k))
			{	ans[++j]=k; 
			}
			else if(k=='(' || k==')' || k=='+' || k=='-' || k=='/' || k=='*')
			{	if(k=='(')
					push(k);
				else if(k=='/' || k=='*')
				{
					if(sta[top]=='/' || sta[top]=='*')
					{	ans[++j]=sta[top--];
						push(k);
					}
					else
						push(k);
				}
				else if(k=='-' || k=='+')
				{
					if(sta[top]=='+' || sta[top]=='-' || sta[top]=='/' || sta[top]=='*')
					{	ans[++j]=sta[top--];
						push(k);
					}
				else
						push(k);
				}
				else if(k==')')
				{
					do{
						if(sta[top]!='(')
						{	ans[++j]=sta[top--];}

					  }while(sta[top]!='(');
				}
			}
			else
			{	push(k);}

			
		}
		while(top!=-1)
			{	if(sta[top]!='('){ans[++j]=sta[top];}top--; }
		ans[++j]='/0'; 
	} 
};

int main()
{	st stac;
	stac.ins();
	stac.post();
	stac.display();
	return 0;
}	

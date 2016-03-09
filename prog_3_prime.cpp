#include<iostream>

using namespace std;

main()
{
	int N, M, no, n1, r, i, temp1, temp2, x;
	
	cout<<"Enter N (1 ≤ N ≤ 15000): ";
	cin>>N;
	no=N;
	
	while(no!=1500)
	{
			//check palindrome....
			n1=no;
			r=0;
			while(n1!=0)
			{
				r=r*10;
				r=r+(n1%10);
				n1=n1/10;
			}
			
			if(no==r)
			{
				temp1=no;
			}
		
		
		
		
			//check prime.....
			int flag=0;
			for(i=2; i<(no/2); i++)
			{
				if((no%i)==0)
				{
					flag=1;
					break;
				}
				
			}		
			if(flag==0)
			{
				temp2=no;
				
			}
		
		
		//check palindrome==prime
		if(temp1==temp2)  
		{
			M=temp1;
			break;
		}
		no++;
		
	}
	
	x=M>>5;
	cout<<"\n\noutput: "<<M <<", " <<x<<endl;
	
	
	
}

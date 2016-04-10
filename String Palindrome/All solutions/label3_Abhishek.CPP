/*String Palindrome by Abhishek Shah*/

/*Not in working condition yet*/

#include<string.h>
#include<iostream>
#define max 5
int  main()
{
	int n;
	char stra[max],strb[max],stemp[max];//string A,B and subs of B
	char sfull[(2*max)],soriginal[(2*max)];//subs of A and concated
	int lenfull;
	cin>>n;
	while(n>0)
	{
		cin>>stra;
		cin>>strb;

		int len=strlen(stra);
		int len2=strlen(strb);
		int  flag=0;

		for(int i=1;i<=len;i++) //no of letters of 1st substring
		{
			delete sfull;
			char *sfull=new char[(2*max)];
			for(int j = 0;j<(len-i+1);j++)//1st letter of 1st substring
			{
				int count = 0;
				for(int  k=j,l=0;count<i;k++,l++)//making of 1st substring
				{
					sfull[l]=stra[k];
					count++;
				}
				cout<<sfull<<endl;
				strcpy(soriginal,sfull);

				for(int p=1;p<len2;p++)//no of lett. of 2nd subst.
				{
					delete stemp;
					char *stemp=new char[max];
					for(int q=0;q<(len2-p+1);q++)//1st let. of 2nd sub
					{
						int count2=0;
						for(int r=q,l=0;count2<p;r++,l++)//got 2nd subs.
						{
							stemp[l]=strb[r];
							count2++;
						}
					}
				}
				strcat(soriginal,stemp);
				char stemp2[(2*max)];
				strcpy(stemp2,soriginal);
				strrev(stemp2);
				if(strcmpi(stemp2,soriginal)==0)
				flag=1;
			}
			if(flag==1)
			break;
		}
		n--;
		if(flag==1)
		break;
	}
return 0;
}
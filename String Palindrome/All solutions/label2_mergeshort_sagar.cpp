#include<iostream>
using namespace std;

void Sort(int *,int,int);
void Merge(int *,int,int,int);

int main()
{
    int a[10],i,n;
 	cout<<"How many numbers?: ";
 	cin>>n;
 	cout<<"Enter the numbers:";
 	for(i=0;i<n;i++)
 	{
 	cin >> a[i];
 	}
 	Sort(a,0,n-1);
 	cout<<"In ascending order is:"<<endl;
 	for(i=0;i<n;i++)
 	{
    cout<<a[i]<<endl;
 	}
}
void Sort(int *a,int l,int r)
{
	if(l<r)
	{
    int m=(l+r)/2;
    Sort(a,l,m);
    Sort(a,m+1,r);
    Merge(a,l,m,r);
    }
}

void Merge(int *a,int l,int m,int r)
{
	int i,j,tmp;
	for(i=l;i<r;i++)
	{
    for(j=i+1;j<=r;j++)
    {
    if(a[i]>a[j])
    {
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    }
    }
    }
}

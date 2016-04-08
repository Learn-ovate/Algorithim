/* Created By Himanshu Patel */



#include<iostream>
using namespace std;


void MergeSort(int *,int,int);
void Merge(int *,int,int,int);

int main()
{
	int arr[10];
	int i;
	int n;
	cout << "Enter the Total number of variables:";
	cin >> n;
	cout << "Enter the numbers:";
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	MergeSort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		cout <<  arr[i] << endl;
	}


}

void MergeSort(int *arr,int l,int r)
{
	
	if(l<r)
	{
		int m=(l+r)/2;
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		Merge(arr,l,m,r);

	}
}

void Merge(int *arr,int l,int m,int r)
{
	int i,j,tmp;
	for(i=l;i<r;i++)
	{
	
		for(j=i+1;j<=r;j++)
		{
			if(arr[i]>arr[j])
			{	
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;

			}
		}
	}

}

#include<iostream>
using namespace std;
int a[10],l,u,i,j;
void quick(int *,int,int);
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
int part(int low,int high,int *a)
{
     int i,h=high,l=low,p,t;  //p==pivot
     p=a[low];
     while(low<high)
     {
                    while(a[l]<p)
                    {
                                   l++;
                    }
                    while(a[h]>p)
                    {
                                   h--;
                    }
                    if(l<h)
                    {
                                t=a[l];
                                a[l]=a[h];
                                a[h]=t;
                    }
                    else
                    {
                        t=p;
                        p=a[l];
                        a[l]=t;
                        break;
                    }
     }
     return h;
}

void quick(int l,int h,int *a)
{
  int index,i;
  if(l<h)
  {
          index=part(l,h,a);
          quick(l,index-1,a);
          quick(index+1,h,a);
  }
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

int main()
{
    int ch ;
    int a[20], i, b[20];
    cout << "1) quick sort 2) merge sort :";
    cin >> ch;
    switch(ch)
    {
        case 1:
           int a[100],n,l,h,i;
            cout<<"Enter number of elements:";
            cin>>n;
            cout<<"Enter the elements (Use Space As A Separator):";
            for(i=0;i<n;i++)
            cin>>a[i];
            cout<<"\nInitial Array:\n";
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<"\t";
            }
            h=n-1;
            l=0;
            quick(l,h,a);
            cout<<"\nAfter Sorting:\n";
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<"\t";
            }
            break;
        case 2:
            cout<<"enter  the elements\n";
                for (i = 0; i < 5; i++)
                {
                    cin>>a[i];
                }
            mergesort(a, 0, 4);
            cout<<"\nsorted array\n";
                for (i = 0; i < 5; i++)
                {
                    cout<<a[i]<<" ";
                }
            break;
    }
    return 0;
}


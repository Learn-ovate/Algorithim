#include<iostream>
using namespace std;
int ispalim(int i)
{
    int j=i,sum=0,temp=0;
    while(j!=0)
    {
        sum*=10;
        temp=j%10;
        sum=sum+temp;
        j=j/10;
    }
    if(sum==i)
        return 1;
    else
        return 0;
}
int isprime(int i)
{
    int flag=0;
    for(int j=1;j<=i;j++)
    {
        if(i%j==0)
            flag++;
    }
    if(flag<=2)
        return 1;
    else
        return 0;

}
int isprimepalim(int i)
{
    if(isprime(i) && ispalim(i))
        return 1;
    return 0;
}
int main()
{
    int n,j;
    cout<<"\n Enter the N =";
    cin>>n;
    if(n>=1 && n<=15000)
    {
        for(int i=n;i<=15000;i++)
        {
            if(isprimepalim(i))
            {
                j=i;
                break;
            }
        }
    }
    cout<<"\n"<<j<<" "<<(j>>5)<<endl;
    return 0;
}

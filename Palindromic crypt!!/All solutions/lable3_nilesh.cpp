#include<iostream>
using namespace std;

int ans(int );

int main()
{
        int n1,n2;
        cin>>n1;
        
        n2=ans(n1);
        
        cout<<n2<<endl;
        
        return 0;
}

int isprime(int n)
{
        int flag=1;
        
        for(int i=2;i<=n/2;i++)
        {
                if(n%i==0)
                {
                        flag=0;
                        break;
                }
        }
        return flag;
}

int ispalondrome(int n)
{
        int rev=0,temp=n;
        while(n!=0)
        {
                rev*=10;
                rev+=n%10;
                n=n/10;       
        }        
        if(temp==rev)
                return 1;
        return 0;
}

int ans(int n)
{
        int i;
        
        for(i=0;!(isprime(n+i) && ispalondrome(n+i));i++);
        
        return n+i;
}

#include<iostream>
using namespace std;

int main()
{
        long int x,y;
        
        cin>>x>>y;
        
        long int temp;
        
        temp=x;
        x=y;
        y=temp;
        
        cout<<x<<" "<<y<<endl;
        
        return 0; 
}

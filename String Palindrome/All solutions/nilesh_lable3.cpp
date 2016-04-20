#include<iostream>
using namespace std;

int main()
{
        int T , *ans;
        cin>>T;
        ans=new int[T];
        
        int i,j,k;
        
        for(i=0;i<T;i++)
        {
                int flag=0;
                char s1[15],s2[15];
                cin>>s1>>s2;
                
                for(j=0;s1[j]!='\0';j++)
                {
                        for(k=0;s2[k]!='\0';k++)
                        {
                           if(s1[j]==s2[k])
                           {
                                flag=1;
                                break;
                           }     
                        }
                        if(flag==1)
                        {
                                ans[i]=1;
                                break;
                        }
                }
        }
        
        for(i=0;i<T;i++)
        {
                if(ans[i]==1)
                        cout<<"Yes"<<endl;
                else
                        cout<<"No"<<endl;
        }       
        return 0;
}

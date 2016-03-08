#include<string.h>
#include<iostream>
using namespace std;

//#define 10 10;

class stack
{
        char data[10];
        int top;
        
        public:
                stack()
                {
                        top=-1;
                }
                
                void push(char );
                char pop();
                int isempty();
                int isfull();               
};

int stack::isempty()
{
        if(top!=-1)
                return 0;
        return 1;
}

int stack::isfull()
{
        if(top!=10-1)
                return 0;
        return 1;        
}


void stack::push(char c)
{
        data[++top]=c;
}

char stack::pop()
{
        char c=data[top--];
        
        return c;
}

int main()
{
        stack s;
        int flag=1;
        cout<<"Enter a string having different combination of different brackets:"<<endl;
        
        char input[10];
        cin>>input;
               
        for(int i=0;i<strlen(input);i++)
        {
                if(input[i]=='(' || input[i]=='{' || input[i]=='[')
                        s.push(input[i]);
                else
                {
                        char c=s.pop();
                        if((input[i]==')' && c=='(') || (input[i]=='}' && c=='{') || (input[i]==']' && c=='['))
                                continue;
                        else
                        {
                                flag=0;
                                break;
                        }                   
                }                                       
        }       

        if(flag==1 && s.isempty())
                cout<<"String is valid"<<endl;
        else
                cout<<"String is not valid"<<endl;
        
                return 0;        
}

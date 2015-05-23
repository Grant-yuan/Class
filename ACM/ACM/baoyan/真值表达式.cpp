#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
stack<int> s;
int n,l;
char str[100];
int ans[20];
void slove()
{
    int top=1;
    while(!s.empty()) s.pop();
    char s1,s2,n1,n2;
    for(int i=0;i<l;i++)
    {
        if(str[i]=='a')
        {
            s2=s.top();s.pop();
            s1=s.top();s.pop();
            if(s1=='0'||s2=='0') s.push('0');
            else s.push('1');
        }
        else if(str[i]=='o')
        {
            s2=s.top();s.pop();
            s1=s.top();s.pop();
            if(s1=='0'&&s2=='0') s.push('0');
            else s.push('1');
        }
        else if(str[i]=='i')
        {
            s2=s.top();s.pop();
            s1=s.top();s.pop();
            if(s1=='1'&&s2=='0') s.push('0');
            else s.push('1');
        }
        else if(str[i]=='e')
        {
            s2=s.top();s.pop();
            s1=s.top();s.pop();
            if(s1==s2) s.push('1');
            else s.push('0');
        }
        else if(str[i]=='n')
        {
            s1=s.top();s.pop();
            if(s1=='0') s.push('1');
            else s.push('0');
        }
        else{
            char c=ans[top++]+'0';
            s.push(c);
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("%c\n",s.top());
}
void dfs(int point)
{
    if(point>n) {slove();print();return;}
    for(int i=0;i<2;i++)
    {
        ans[point]=i;
        dfs(point+1);
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    l=strlen(str);
    dfs(1);
    return 0;
}

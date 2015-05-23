#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
char a[10007];
int main()
{
    //freopen("in.txt","r",stdin);
    int ans=0;
   cin.getline(a,10002);
    int l=strlen(a);
    for(int i=0;i<l;i++)
        if(a[i]==' '&&i>0&&a[i-1]!=' ') ans++;
    cout<<ans<<endl;
}

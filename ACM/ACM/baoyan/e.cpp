#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
char a[300],b[300],c[300];
int ff()
{
    int l1=strlen(a),l2=strlen(b);
    int j=0;
    for(int i=0;i<l1;i++)
    {
        j=0;
        while(a[i+j]==b[j]){
            j++;
            if(j==l2) return i;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>a;cin>>b;cin>>c;
    int point=ff();
    int i;
    for(i=0;i<point;i++)
    {
        printf("%c",a[i]);
    }
    for(i=0;i<strlen(c);i++) printf("%c",c[i]);
    for(i=point+strlen(b);i<strlen(a);i++)
        printf("%c",a[i]);
    cout<<endl;
}

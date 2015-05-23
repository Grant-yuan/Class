#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include <cctype>
#include<vector>
using namespace std;
const int maxn=1000000;
int n,m;
vector<int> G[maxn+7];
void scan_d( int & x )
{
     char ch = getchar();     while ( !isdigit(ch) ) ch = getchar();
     x = 0;
     do
     {
         x = x * 10 + ch - '0';
         ch = getchar();
     } while ( isdigit(ch) );
}
void insert_value(int qq)
{
    int t=qq%1000;
    G[t].push_back(qq);
}
int find_value(int qq)
{
    int res=0;
    int t=qq%1000;
    int l=G[t].size();
    for(int i=0;i<l;i++)
    {
        if(G[t][i]==qq){
            res+=1;
            G[t][i]=-1;
        }
    }
    return res;
}
int main()
{
    int left,right,mid,qq,ans;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<maxn+7;i++) G[i].clear();
        for(int i=0;i<n;i++)
        {
            //scan_d(qq);
            scanf("%d",&qq);
            insert_value(qq);
        }
        for(int i=0;i<m;i++)
        {
            //scan_d(qq);
            scanf("%d",&qq);
            ans=find_value(qq);
            printf("%d\n",ans);
        }
    }
    return 0;
}

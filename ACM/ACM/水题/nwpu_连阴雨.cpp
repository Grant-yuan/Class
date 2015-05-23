#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
char mat[1007][1007];
int q[1000007];
int next[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
bool flag[1007][1007];
bool t;
bool can(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<m&&!flag[i][j]&&mat[i][j]!='.') return 1;
    return 0;
}
void bfs(int point)
{
    int top=0,base=0,l,r,ll,rr;
    q[top++]=point;
    while(base<top){
        l=q[base]/m;r=q[base]%m;
        for(int i=0;i<8;i++)
        {
            ll=l+next[i][0];rr=r+next[i][1];
            if(can(ll,rr)){
                t=1;
                flag[ll][rr]=1;
                q[top++]=ll*m+rr;
            }
        }
        base++;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
    int i,j;char c;
    t=0;
    for(int i=0;i<n;i++)
    {
        c=getchar();
        for(int j=0;j<m;j++)
    {

            c=getchar();
            mat[i][j]=c;

    }
    }
    memset(flag,0,sizeof(flag));
    long long ans=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
    {
        if(!flag[i][j]&&mat[i][j]!='.')
        {
            t=0;
            flag[i][j]=1;
            ans++;
            bfs(i*m+j);
        }
    }
    cout<<ans<<endl;}
    return 0;
}

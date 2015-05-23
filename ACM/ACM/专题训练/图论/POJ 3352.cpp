#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
const int maxn=1007;
int n,m,low[maxn],sum,degree[maxn],mp[maxn][maxn];
vector<int> G[maxn];

void dfs(int u,int fa)
{
    int l=G[u].size();
    low[u]=sum++;
    for(int i=0;i<l;i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        if(!low[v]){
            dfs(v,u);
        }
        low[u]=min(low[u],low[v]);
    }
}
int tarjan()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            if(low[i]!=low[G[i][j]]) degree[low[i]]++;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
        if(degree[i]==1) res++;
    return res;
}
int main()
{
    int cnt=1,a,b;
    while(~scanf("%d%d",&n,&m)){
        memset(low,0,sizeof(low));
        memset(degree,0,sizeof(degree));
        memset(mp,0,sizeof(mp));
        for(int i=0;i<=n;i++) G[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            if(mp[a][b]>0) continue;
            mp[a][b]++;mp[b][a]++;
            G[a].push_back(b);G[b].push_back(a);
        }
        sum=1;
        dfs(1,-1);
        int ans=tarjan();
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}

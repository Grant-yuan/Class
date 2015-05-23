//无向图的割点
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int maxn=107;
int n;
vector<int> G[maxn];
int ans,low[maxn],pre[maxn],sum,root;
bool iscut[maxn];
void dfs(int u,int fa)
{
    int lowu;
    low[u]=pre[u]=sum++;
    int l=G[u].size();
    int child=0;
    for(int i=0;i<l;i++)
    {
        int v=G[u][i];
        if(!pre[v]){
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(u==root&&child==2) iscut[u]=1;
            if(low[v]>=pre[u]&&u!=root){
                iscut[u]=1;
            }
        }
        else if(u!=v)
        {
            low[u]=min(low[u],pre[v]);
        }
    }
}
int main()
{
    char c;int m,a,b;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<maxn;i++) G[i].clear();
        while(1){
            scanf("%d",&m);
            if(m==0) break;
             while((c=getchar())!='\n')
            {
                scanf("%d",&b);
                G[m].push_back(b);
                G[b].push_back(m);
            }
        }
        memset(pre,0,sizeof(pre));
        memset(iscut,0,sizeof(iscut));
        memset(low,0,sizeof(low));
        ans=0,sum=1,root=1;
        if(n==1||n==2){printf("0\n");continue;}
        dfs(1,-1);
        for(int i=0;i<=n;i++) if(iscut[i]) ans++;
        printf("%d\n",ans);
    }
}

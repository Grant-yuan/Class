#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
const int maxn=11007;
vector<int> G[maxn];
int pre[maxn],ans,root,sum,n,m,cnt[maxn];
int tarjan(int u,int fa)
{
    int lowu=pre[u]=sum++;
    int l=G[u].size();
    int child=0;
    for(int i=0;i<l;i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        if(!pre[v]){
            child++;
            int lowv=tarjan(v,u);
            lowu=min(lowv,lowu);
            if((u==root&&child>1)||(u!=root&&pre[u]<=lowv)){
                cnt[u]++;
            }
        }
        else lowu=min(lowu,pre[v]);
    }
    return lowu;
}
int main()
{
    int a,b;
    while(1){
        for(int i=0;i<maxn;i++) G[i].clear();
        scanf("%d%d",&n,&m);
        if(n==0) break;
        if(m==0){printf("%d\n",n-1);continue;}
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int t=0;ans=0;
        memset(pre,0,sizeof(pre));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            if(!pre[i]){
                t++;root=i;
                sum=1;
                tarjan(i,-1);
            }
            ans=max(ans,cnt[i]);
        }
        printf("%d\n",t+ans);
    }
    return 0;
}

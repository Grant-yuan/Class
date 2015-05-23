#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;
const int maxn=1007;
vector<int> G[maxn];
int pre[maxn],ans,root,sum,cnt[maxn];
bool isroot[maxn];
int tarjan(int u,int fa)
{
    int lowu=pre[u]=sum++;
    int l=G[u].size();
    int child=0;
    for(int i=0;i<l;i++)
    {
        int v=G[u][i];
        if(!pre[v]){
            child++;
            int lowv=tarjan(v,u);
            lowu=min(lowv,lowu);
            if(u==root&&child>1||u!=root&&pre[u]<=lowv){
                cnt[u]++;
            }
        }
        else if(v!=fa) lowu=min(lowu,pre[v]);
    }
    return lowu;
}
int main()
{
    int a,b,tt=1;
    bool first=0;
    while(1){
        if(first) printf("\n");
        else first=1;
        for(int i=0;i<maxn;i++) G[i].clear();
        scanf("%d",&a);
        if(a==0) break;
        scanf("%d",&b);
        G[a].push_back(b);G[b].push_back(a);
        while(1){
            scanf("%d",&a);
            if(a==0) break;
            scanf("%d",&b);
            G[a].push_back(b);G[b].push_back(a);
        }
       memset(pre,0,sizeof(pre));
       memset(cnt,0,sizeof(cnt));
       memset(isroot,0,sizeof(isroot));
       for(int i=1;i<=1000;i++)
       {
           if(!pre[i]&&G[i].size()>0){
              root=i;
              isroot[i]=1;
              sum=1;
              tarjan(i,-1);
           }
       }
       printf("Network #%d\n",tt++);
       bool flag=0;
       for(int i=1;i<=maxn;i++)
       {
           if(cnt[i]&&isroot[i]) {flag=1;printf("  SPF node %d leaves %d subnets\n",i,cnt[i]+1);}
           else if(cnt[i]&&!isroot[i]) {flag=1;printf("  SPF node %d leaves %d subnets\n",i,cnt[i]+1);}
       }
       if(!flag) printf("  No SPF nodes\n");
    }
    return 0;
}

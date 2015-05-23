#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn=100007;
struct node
{
    int from,to;
};
node edge[100007*2];
int next1[100007*2],first[maxn],pre[maxn],top;
int n,m,sum,ans[maxn],anstop;
void addedge(int u,int v)
{
    edge[sum].from=u;edge[sum].to=v;
    next1[sum]=first[u];first[u]=sum;sum++;
    edge[sum].from=v;edge[sum].to=u;
    next1[sum]=first[v];first[v]=sum;sum++;
}
int tarjain(int u,int fa)
{
    int lowu=pre[u]=top++,child=0;
    for(int i=first[u];i!=-1;i=next1[i])
    {
        int v=edge[i].to;
        if(!pre[v]){
            child++;
            int lowv=tarjain(v,u);
            lowu=min(lowv,lowu);
            if(pre[u]<lowv){
                ans[anstop++]=i;
            }
        }
        else if(pre[v]<lowu&&v!=fa){
            lowu=min(lowu,pre[v]);
        }
    }
    return lowu;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;string s1,s2;int cnt;
    cin>>t;
    while(t--){
        memset(next1,-1,sizeof(next1));
        memset(first,-1,sizeof(first));
        memset(pre,0,sizeof(pre));
        map<string,int> mp1;
        map<int,string> mp2;
        cin>>n>>m;
        cnt=1;anstop=0,sum=0;
        for(int i=1;i<=m;i++)
        {
            cin>>s1>>s2;
            if(mp1[s1]==0) mp1[s1]=cnt,mp2[cnt]=s1,cnt++;
            if(mp1[s2]==0) mp1[s2]=cnt,mp2[cnt]=s2,cnt++;
            addedge(mp1[s1],mp1[s2]);
        }
        top=1;
        tarjain(1,-1);
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(!pre[i]) flag=0;
        }
        if(!flag){cout<<"0"<<endl;continue;}
        sort(ans,ans+anstop);
        cout<<anstop<<endl;
        int k;
        for(int i=0;i<anstop;i++)
        {
            k=ans[i];
            k=min(k,k^1);
            cout<<mp2[edge[k].from].c_str()<<" "<<mp2[edge[k].to].c_str()<<endl;
        }
    }
    return 0;
}

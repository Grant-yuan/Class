#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int maxn=1007;
const int inf=0x3f3f3f3;
struct node
{
    int to;
};
vector<node> G[maxn];
int root,ans[maxn],n;
bool flag[maxn];
char value[maxn];
void init()
{
    for(int i=0;i<maxn;i++) G[i].clear();
    memset(value,0,sizeof(value));
    memset(flag,0,sizeof(flag));
    memset(ans,0,sizeof(ans));
    root=-1;
}
void input()
{
    int a,b;node n1;
    for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            n1.to=b;
            G[a].push_back(n1);
            n1.to=a;
            G[b].push_back(n1);
        }
        scanf("%d",&root);
        scanf("%s",value+1);
}
char dfs(int point,int father)
{
    int l=G[point].size();
    if(l==1&&point!=root) {return value[point];}
    stack<char> str;
    while(!str.empty()) str.pop();
    for(int i=0;i<l;i++)
    {
        if(G[point][i].to==father) continue;
        if(!flag[G[point][i].to])
            str.push(dfs(G[point][i].to,point));
    }
    if(str.size()==1) value[point]=str.top();
    else if(str.size()==3){
        char a=str.top();str.pop();
        char b=str.top();str.pop();
        char c=str.top();str.pop();
        if(b=='+') value[point]=(a-'0')+(c-'0')+'0';
        else if(b=='-') value[point]=(a-'0')-(c-'0')+'0';
        else if(b=='*') value[point]=(a-'0')*(c-'0')+'0';
    }
    return value[point];
}
int main()
{
    int a,b;
    while(~scanf("%d",&n)){
        init();
        input();
        flag[root]=1;
        dfs(root,-1);
        int res=value[root]-'0';
        printf("%d\n",res);
    }
    return 0;
}
/*
10
1 2
1 3
1 4
2 5
4 6
4 7
4 8
6 9
8 10
1
EE+E3E*E45
10
1 2
1 3
1 4
2 5
2 6
2 7
5 8
7 9
4 10
1
EE*EE+E345
*/

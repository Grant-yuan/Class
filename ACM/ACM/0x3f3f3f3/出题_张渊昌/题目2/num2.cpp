#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int Max = 10050;
int MaxTime[Max];
int main(){
    freopen("num2.in","r",stdin);
    FILE *fp;
    fp=fopen("num2.out","w");
    int n, i, t, k, cnt, ans = 0;
    while(~scanf("%d", &n)){
    memset(MaxTime,0,sizeof(MaxTime));
    for(i = 1; i <= n; i ++){
        scanf("%d%d", &t, &cnt);
        MaxTime[i] = t;
        while(cnt --){
            scanf("%d", &k);
            MaxTime[i] = max(MaxTime[i], t + MaxTime[k]);
        }
        ans = max(ans, MaxTime[i]);
    }
    fprintf(fp,"%d\n", ans);}
    return 0;
}

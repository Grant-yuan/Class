#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<math.h>
using namespace std;
const int inf=0x3f3f3f3;
const int maxn=150000;
long long n,w,h;
long long ans;
long long num[maxn+7];
int main()
{
    int sum;
    while(~scanf("%lld%lld%lld",&n,&w,&h)){
        memset(num,0,sizeof(num));
        ans=w*h;sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[50000+i]);
            sum+=num[50000+i];
        }
        if(sum<w*h){printf("-1\n");continue;}
        long long ans1=0,ans2=0;
        for(int i=50001-w;i<=50000;i++)
        {
            if(num[i]>=h){
                ans1+=(num[i]-h);
            }
            else
            {
                ans2+=(h-num[i]);
            }
        }
        ans=min(ans,max(ans1,ans2));
        for(int i=50001;i<=50000+n+w;i++)
        {
            if(num[i-w]>=h){
                    ans1-=(num[i-w]-h);
                }
            else{
                    ans2-=(h-num[i-w]);
                }
            if(num[i]>=h){
                ans1+=(num[i]-h);
            }
            else
            {
                ans2+=(h-num[i]);
            }
            ans=min(ans,max(ans1,ans2));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

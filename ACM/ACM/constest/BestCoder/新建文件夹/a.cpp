#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
long long ans;
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m)){
        long long ans=m*n;
        long long tt=m+n;
        long long gg=max(ans,tt);
        for(long long i=2;i*i<=gg;i++)
        {
            while(tt%i==0&&ans%i==0){
                tt=tt/i;
                ans=ans/i;
            }
        }
        printf("%I64d/%lld\n",ans,tt);
    }
    return 0;
}

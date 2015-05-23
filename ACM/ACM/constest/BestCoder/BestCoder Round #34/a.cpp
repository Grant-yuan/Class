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
int m,n;
int ans;
int main()
{
    while(~scanf("%d%d",&n,&m)){
       ans=inf;
       int sum;
       int a,b;
       for(int i=0;i<m;i++)
       {
           scanf("%d%d",&a,&b);
           if(n%a==0){
            sum=n/a*b;
           }
           else{
            sum=(n/a+1)*b;
           }
           ans=min(ans,sum);
       }
       cout<<ans<<endl;
    }
    return 0;
}

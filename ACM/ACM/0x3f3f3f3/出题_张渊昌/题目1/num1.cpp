#include<stdio.h>
int main()
{
   freopen("data1.txt","r",stdin);
   FILE *fp;
   fp=fopen("output11.txt","w");
    int cas,n,max;
    scanf("%d",&cas);
    while(cas--)
    {
        long long sum;
        sum=max=0;
        scanf("%d",&n);
        while(n--)
        {
            int num;
            scanf("%d",&num);
            if(max<num) max=num;
            sum+=num;
        }
        if(2*max-sum<=1) fprintf(fp,"Yes\n");
        else fprintf(fp,"No\n");
    }
    return 0;
}

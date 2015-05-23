#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include <cctype>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int maxn=1000000;
int h[maxn+7],n,m,q;
vector<int> G[maxn+7];
void scan_d( int & x )
{
     char ch = getchar();     while ( !isdigit(ch) ) ch = getchar();
     x = 0;
     do
     {
         x = x * 10 + ch - '0';
         ch = getchar();
     } while ( isdigit(ch) );
}
int main()
{
    int left,right,mid,ans1,ans2,t,l;
    bool flag;
    while(~scanf("%d%d",&n,&m)){
        //set<int> st;
        //set<int>::iterator it1;
        for(int i=0;i<maxn+7;i++) G[i].clear();
        for(int i=0;i<n;i++) //scanf("%d",&h[i]);
            scan_d(h[i]);
        sort(h,h+n);
        for(int i=0;i<m;i++)
        {
            //scanf("%d",&q);
            //printf("qq:%d\n",q);
            scan_d(q);
            /*it1=st.find(q);
            if(it1!=st.end()) {printf("0\n");continue;}
            st.insert(q);*/
            t=q%maxn;l=G[t].size();flag=0;
            for(int i=0;i<l;i++) if(G[t][i]==q) {flag=1;break;}
            if(flag==1) {printf("0\n");continue;}
            G[t].push_back(q);
            left=0;right=n;
            ans1=ans2=-1;
            while(left<right){
                mid=(left+right)>>1;
                //printf("mid1:%d\n",mid);
                if(h[mid]>=q){
                    if(h[mid]==q) ans1=mid;
                    right=mid-1;
                }
                else left=mid;
            }
            if(ans1==-1) {printf("0\n");continue;}
            ans2=0;
            for(int j=ans1;j<n;j++)
            {
                if(h[j]==q) ans2++;
                else break;
            }
            printf("%d\n",ans2);
        }
    }
    return 0;
}

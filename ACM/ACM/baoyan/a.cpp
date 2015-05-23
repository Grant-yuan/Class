#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c;
int ans;
int main()
{
      cin>>a>>b>>c;
        ans=a;
        if(a>b) ans=b;
        if(c<ans) ans=c;
        cout<<ans<<endl;

    return 0;
}

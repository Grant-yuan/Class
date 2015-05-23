#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int m,t;
int str;
int mat[107][107];
int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
        for(int j=0;j<t;j++)
    {
        scanf("%d",&mat[i][j]);
    }
    cin>>n>>m;
    cin>>str;
    if(str==0){
        if(m-1>=0&&mat[n][m-1]==0) printf("Y\n");
        else printf("N\n");
    }
    else if(str==1){
       if(n+1<t&&mat[n+1][m]==0) printf("Y\n");
        else printf("N\n");
    }
    else if(str==2){
       if(m+1<t&&mat[n][m+1]==0) printf("Y\n");
        else printf("N\n");
    }
    else if(str==3){
           if(n-1>=0&&mat[n-1][m]==0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}

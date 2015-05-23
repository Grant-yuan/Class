#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int m,t;
char str;
int main()
{
    cin>>t;
    cin>>n>>m;
    cin>>str;
    if(str=='w'){
        if(n==0) printf("N\n");
        else printf("Y\n");
    }
    else if(str=='s'){
          if(n==t-1) printf("N\n");
        else printf("Y\n");
    }
    else if(str=='a'){
          if(m==0) printf("N\n");
        else printf("Y\n");
    }
    else if(str=='d'){
          if(m==t-1) printf("N\n");
        else printf("Y\n");
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[200];
int l,l1,l2,l3;
char c1,c2,c3;
int main()
{
    while(~scanf("%s",s)){
        l=strlen(s);
        if(l%3!=0){
            printf("NO\n");
        }
        else{
            l1=1;l2=l3=0;c1=c2=c3='A';
            c1=s[0];int i=1;
            while(i<l&&s[i]==s[i-1]) l1++,i++;
            if(i<l) l2++,c2=s[i];
            i++;
            while(i<l&&s[i]==s[i-1]) l2++,i++;
            if(i<l) l3++,c3=s[i];i++;
            while(i<l&&s[i]==s[i-1]) l3++,i++;
            if(l1==l2&&l2==l3&&c1!=c3&&c2!=c1&&c2!=c3&&i==l) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

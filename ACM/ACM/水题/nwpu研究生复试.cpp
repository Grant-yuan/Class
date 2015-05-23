#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int a[6],num;
};
int top,base;
node q[10000];
int n,aa[6];
int ans;
bool ff;
bool flag[666666];
bool judge(int point)
{
    return !flag[point];
}
int get_num(int aa[])
{
    return aa[0]+aa[1]*10+aa[2]*100+aa[3]*1000+aa[4]*10000+aa[5]*100000;
}
void get1()
{
     aa[1]=q[base].a[0];
     aa[4]=q[base].a[1];
     aa[3]=q[base].a[4];
     aa[0]=q[base].a[3];
     aa[2]=q[base].a[2];
     aa[5]=q[base].a[5];
}
void get2()
{
     aa[0]=q[base].a[0];
     aa[3]=q[base].a[3];
     aa[1]=q[base].a[4];
     aa[2]=q[base].a[1];
     aa[5]=q[base].a[2];
     aa[4]=q[base].a[5];
}
bool can()
{
    for(int i=0;i<6;i++)
        if(q[base].a[i]!=i+1) return 0;
    return 1;
}
void paste(int a1[],int a2[])
{
    for(int i=0;i<6;i++) a1[i]=a2[i];
}
void bfs()
{
    while(base<top){
        if(can()){ans=q[base].num;ff=1;return;}
        get1();
        int point=get_num(aa);
        if(judge(point)){
            flag[point]=1;
            q[top].num=q[base].num+1;
            paste(q[top++].a,aa);
        }
        get2();
        point=get_num(aa);
        if(judge(point)){
            flag[point]=1;
            q[top].num=q[base].num+1;
            paste(q[top++].a,aa);
        }
        base++;
    }
}
int main()
{
    node n1;
    scanf("%d",&n);
    while(n--){
        for(int i=0;i<6;i++) scanf("%d",&q[0].a[i]);
        ff=0;
        top=base=0;q[0].num=0;top=1;
        memset(flag,0,sizeof(flag));
        int point=get_num(q[0].a);
        //cout<<point<<endl;
        flag[point]=1;
        bfs();
        if(!ff) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}

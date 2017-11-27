#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1001000;
int n,vis[maxn];
struct node{
    LL x,y;
}req[maxn],res[maxn];
LL getdis(node &A,node &B,node &C){
    return (B.x-A.x)*(C.x-A.x)+(B.y-A.y)*(C.y-A.y);
}
LL work(node &A,node &B,node &C){
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
int check(){
    int cnt=0;
    for(int i=3;i<=n;i++)if(work(req[1],req[2],req[i])!=0)res[++cnt]=req[i];
    for(int i=3;i<=cnt;i++)
    if(work(res[1],res[2],res[i])!=0)
        return 0;
    node A,B,C;
    A.x=req[2].x-req[1].x,A.y=req[2].y-req[1].y;
    B.x=res[2].x-res[1].x,B.y=res[2].y-res[1].y;
    C.x=C.y=0;
    return cnt<2||work(C,A,B)==0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&req[i].y),req[i].x=i;
    int flg=0;
	for(int i=3;i<=n&&!flg;i++)if(work(req[i-2],req[i-1],req[i])!=0)flg=1;
    if(!flg)return 0*printf("NO\n");
    if(check())return 0*printf("YES\n");
    swap(req[1],req[3]);
    if(check())return 0*printf("YES\n");
    swap(req[2],req[3]);
    if(check())return 0*printf("YES\n");
    puts("NO");
}


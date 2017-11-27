#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+107;
int A[maxn],res[maxn];
struct node
{
    int w,id;
}s[maxn];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int cmpp(int x,int y){
    return x>y;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    sort(A+1,A+1+n,cmpp);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i].w);
        s[i].id=i;
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++)res[s[i].id]=A[i];
    for(int i=1;i<=n;i++)printf("%d ",res[i]);
}


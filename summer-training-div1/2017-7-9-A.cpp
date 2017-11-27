#include<bits/stdc++.h>
using namespace std;
const int maxn=1000007;
struct {
    int l,r,loca;
}tr[maxn*40];
int tot,A[maxn],rt[maxn];
void pushup(int x){
	tr[x].loca=min(tr[tr[x].l].loca,tr[tr[x].r].loca);
}
void insert(int &x,int l,int r,int a,int b){
	tr[++tot]=tr[x];
	x=tot;
    if(l==r){
    	tr[x].loca=b;
    	return ;
    } 
    int mid=(l+r)>>1;
    if(a<=mid) 
		insert(tr[x].l,l,mid,a,b);
    else 
		insert(tr[x].r,mid+1,r,a,b);
    pushup(x);
}
int query(int x,int l,int r,int a){
    if(l==r)return l;
    int mid=(l+r)/2;
    if(tr[tr[x].l].loca<a) 
		return query(tr[x].l,l,mid,a);
	else 
		return query(tr[x].r,mid+1,r,a); 
}
int main(){
	int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        insert(rt[i]=rt[i-1],0,1000001,A[i],i);
    }
    scanf("%d",&m);
    while(m--){
    	int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",query(rt[b],0,1000001,a));
    }
}             

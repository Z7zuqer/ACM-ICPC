#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int A[maxn],B[maxn];
struct node{
	int l,r,idx;
}req[maxn];
int cmp(node m,node n){
	if(m.l==n.l)return m.r<n.r;
	return m.l<n.l;
}
int vis[maxn],res[maxn],ans=0;
void add(int x){
	vis[x]++;
	if(vis[x]==B[x])ans++;
}
void del(int x){
	vis[x]--;
	if(vis[x]+1==B[x])ans--;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),B[i]=A[i];
	for(int i=1;i<=m;i++)scanf("%d%d",&req[i].l,&req[i].r),req[i].idx=i;
	sort(req+1,req+1+m,cmp);
	sort(B+1,B+1+n);
	int cnt=unique(B+1,B+1+n)-B-1;
	for(int i=1;i<=n;i++)A[i]=upper_bound(B+1,B+1+cnt,A[i])-B-1;
	//for(int i=1;i<=n;i++)cout<<A[i]<<" "<<B[i]<<endl;
	int L=1,R=0;
	for(int i=1;i<=m;i++){
		while(R<req[i].r)add(A[++R]);
		while(L>req[i].l)add(A[--L]);
		while(R>req[i].r)del(A[R--]);
		while(L<req[i].l)del(A[L++]);
		res[req[i].idx]=ans;
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
}



#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int tr[maxn];
struct node{
	int x,y,z,cnt,ans,idx;
}A[maxn];
struct NODE{
	int x,y,z,idx;
}r[maxn];
int precmp(NODE m,NODE n){
	if(m.x!=n.x)return m.x<n.x;
	if(m.y!=n.y)return m.y<n.y;
	return m.z<n.z;
}
void add(int x,int v){
	while(x<maxn){
		tr[x]+=v;
		x+=x&-x;
	}
}
int getans(int x){
	int ans=0;
	while(x){
		ans+=tr[x];
		x-=x&-x;
	}
	return ans;
}
int cdqcmp(node m,node n){
	if(m.y==n.y)return m.z<n.z;
	return m.y<n.y;
}
void cdq(int l,int r){
	if(l>=r)return ;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	sort(A+l,A+1+mid,cdqcmp);sort(A+1+mid,A+r+1,cdqcmp);
	int L=l,R=mid+1;
	while(R<=r){
		while(L<=mid&&A[L].y<=A[R].y){
			add(A[L].z,A[L].cnt);
			L++;
		}
		A[R].ans+=getans(A[R].z);
		//cout<<A[R].ans<<" "<<A[R].idx<<endl;
		R++;
	}
	for(int i=l;i<=mid;i++)add(A[i].z,-A[i].cnt);
}
int res[maxn];
int anscmp(node m,node n){
	return m.idx<n.idx;
}
int main(){
	int n,m;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(tr,0,sizeof tr);
		memset(res,0,sizeof res);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].z),r[i].idx=i;
		sort(r+1,r+1+n,precmp);
		int num=0,cnt=0;
		r[n+1].x=100001;
		for(int i=1;i<=n;i++){
			cnt++;
			if(r[i].x!=r[i+1].x||r[i].y!=r[i+1].y||r[i].z!=r[i+1].z){
				A[++num]={r[i].x,r[i].y,r[i].z,cnt,0,i};
				res[r[i].idx]=num;
				cnt=0;
			}
			else res[r[i].idx]=-1;
		}
		for(int i=n;i>=1;i--)
			if(res[r[i].idx]==-1)
				res[r[i].idx]=res[r[i+1].idx];
		cdq(1,num);
		sort(A+1,A+1+num,anscmp);
		//for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)printf("%d\n",A[res[i]].ans);
	}
}
/*
3 3 3
2 3 3 
2 3 1 
3 1 1 
3 1 2 
1 3 1 
1 1 2 
1 2 2 
1 3 2 
1 2 1
*/


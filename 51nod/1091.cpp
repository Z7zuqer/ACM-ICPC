#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}A[50010]; 
int cmp(node m,node n){
	if(m.r==n.r)return m.l>n.l;
	return m.r>n.r;
}
int cal(int i,int j){
	if(A[j].l>A[i].r)return 0;
	return min(A[i].r,A[j].r)-max(A[i].l,A[j].l);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&A[i].l,&A[i].r);
	}
	sort(A+1,A+1+n,cmp);
	int l=A[1].l,r=A[1].r,ans=0; 
	for(int i=1;i<n;i++)
		ans=max(cal(i,i+1),ans);
	cout<<ans<<endl;
}



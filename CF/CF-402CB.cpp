#include<bits/stdc++.h>
using namespace std;
int n,k; 
struct node{
	int a,b,c;
}A[200100];
int cmp(node m,node n){
	return m.c>n.c;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i].a);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i].b);
		A[i].c=A[i].b-A[i].a;
	}
	sort(A+1,A+1+n,cmp);
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=A[i].a;
	}
	//cout<<ans<<endl;
	int flg=0;
	for(int i=k+1;i<=n;i++){
		if(A[i].c>=0)ans+=A[i].a;
		else ans+=A[i].b;
	}
	cout<<ans<<endl;
}



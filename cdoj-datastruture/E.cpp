#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int ord[maxn],c[maxn];
int A[maxn],B[maxn];
void add(int x,int v){
	while(x<=maxn){
		c[x]+=v;
		x+=x&-x;
	}
}
int getans(int x){
	int ans=0;
	while(x){
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)scanf("%d",&B[i]);
	for(int i=1;i<=n;i++)ord[B[i]]=i;
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=i-getans(ord[A[i]])-1;
		add(ord[A[i]],1);
	}
	cout<<ans<<endl;
}



#include<bits/stdc++.h>
using namespace std;
int A[100000+107],L,R;
int work(int l,int r){
	if(l==r)return max(A[l],0);
	int mid=(l+r)>>1;
	int lmx=work(l,mid);
	int rmx=work(mid+1,r);
	int midmxl=0,midmxr=0,tmp=0;
	for(int i=mid;i>=l;i--){
		tmp+=A[i];
		midmxl=max(midmxl,tmp);
	}
	tmp=0;
	for(int i=mid+1;i<=r;i++){
		tmp+=A[i];
		midmxr=max(midmxr,tmp);
	}
	return max(midmxl+midmxr,max(lmx,rmx));
}
int main(){
	int n;
	//cin>>n;
	int T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		printf("Case %d:\n%d %d %d\n",cas++,work(1,n),L,R);
	}
	//cout<<qpow(n,n)<<endl;
}



#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100100],B[100100];
int n,m;
LL cal(LL k){
	LL ans=0;
	for(int i=1;i<=n;i++)if(A[i]<k)ans+=k-A[i];
	for(int i=1;i<=m;i++)if(B[i]>k)ans+=B[i]-k;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	for(int i=1;i<=m;i++)scanf("%I64d",&B[i]);
	LL l=1,r=1e10,minm=cal(A[1]),res=1e9;
	while(l<r){
		LL mid=(l+r)>>1;
		LL rmid=(mid+r)>>1;
		LL calmid=cal(mid);
		LL calrmid=cal(rmid);
		if(calmid>calrmid){
			l=mid;
			if(calrmid<minm){
				minm=calrmid;
				res=rmid;
			}
		}
		else {
			r=rmid;
			if(calmid<minm){
				minm=calmid;
				res=mid;
			}
		}
	}
	printf("%I64d\n",minm);
}



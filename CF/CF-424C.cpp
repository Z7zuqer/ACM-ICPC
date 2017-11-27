#include<bits/stdc++.h>
using namespace std;
int A[10100],B[10100],C[10100];
int bi(int l,int r,int k){
	while(l<=r){
		int mid=(l+r)>>1;
		if(C[mid]>k)r=mid-1;
		else if(C[mid]<k)l=mid+1;
		else return mid;
	}
	if(C[r]!=k)return -1;
	return 1;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)C[i]=C[i-1]+A[i];
	for(int i=1;i<=k;i++)scanf("%d",&B[i]);
	sort(C+1,C+1+n);
	int u=unique(C+1,C+1+n)-C-1;
	int ans=u;
	for(int i=1;i<=u;i++){
		int d=B[1]-C[i];
		for(int j=1;j<=k;j++){
			if(bi(1,u,B[j]-d)==-1){
				ans--;
				break;
			}
		}
	}
	cout<<ans<<endl;
}

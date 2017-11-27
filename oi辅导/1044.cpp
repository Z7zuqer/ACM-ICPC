#include<bits/stdc++.h>
using namespace std;
int A[100100],n;
int lower(int x){
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(A[mid]<=x)l=mid+1,res=mid;
		else r=mid-1;
	}
	return A[res];
}
int upper(int x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(A[mid]>=x)r=mid;
		else l=mid+1;
	}
	return A[r];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int m;
	scanf("%d",&m);
	while(m--){
		int x;
		scanf("%d",&x);
		int minv=lower(x);
		int maxv=upper(x);
		if(abs(x-minv)>abs(x-maxv))printf("%d\n",maxv);
		else printf("%d\n",minv);
	}
}



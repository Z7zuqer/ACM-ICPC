#include<bits/stdc++.h>
using namespace std;
int A[5010];
int work(int l,int r,int k){
	//cout<<l<<" "<<r<<endl;
	if(l==r)return 1;
	int minv=1e9;
	for(int i=l;i<=r;i++)minv=min(minv,A[i]-k);
	int sum=minv;
	for(int i=l;i<=r;){
		if(A[i]-k>minv){
			int R=i;
			while(R<=r&&A[R]-k>minv)R++;R--;
			sum+=work(i,R,minv+k);
			i=R+1;
		}
		else i++;
	}
	return min(r-l+1,sum);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	printf("%d\n",work(1,n,0));
}



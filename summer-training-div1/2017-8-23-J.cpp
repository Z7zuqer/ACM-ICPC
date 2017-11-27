#include<bits/stdc++.h>
using namespace std;
int A[200200],B[200200],C[200200];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		A[x]=i;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		B[x]=i;
	}
	int cnt=0;
	memset(C,-1,sizeof C);
	for(int i=(n-1)*2;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			int k=i-j;
			if(k<0||k>=n)break;
			int posa=A[j];
			int posb=B[k];
			//cout<<i<<" "<<posa<<" "<<posb<<endl;
			if(C[(posa+posb)%n]==-1){
				C[(posa+posb)%n]=i;
				cnt++;
			}
			if(cnt==n)break;
		}
		if(cnt==n)break;
	}
	for(int i=0;i<n;i++)printf("%d ",C[i]);printf("\n");
}

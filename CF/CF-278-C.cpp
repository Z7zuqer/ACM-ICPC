#include<bits/stdc++.h>
using namespace std;
int A[5],B[5],h,a,d;
int check(int i,int j,int k){
	if(j-B[3]<=0)return 0;
	int t1=B[1]/(j-B[3]);if(B[1]%(j-B[3]))t1++;
	if(B[2]-k<=0)return 1;
	int t2=i/(B[2]-k);if(i%(B[2]-k))t2++;
	if(t1>=t2)return 0;
	return 1;
}
int main(){
	for(int i=1;i<=3;i++)scanf("%d",&A[i]);
	for(int i=1;i<=3;i++)scanf("%d",&B[i]);
	scanf("%d%d%d",&h,&a,&d);
	int maxv=1e9;
	for(int i=A[1];i<=2000;i++)
		for(int j=A[2];j<=200;j++)
			for(int k=A[3];k<=200;k++)
				if(check(i,j,k))
					maxv=min(maxv,(i-A[1])*h+(j-A[2])*a+(k-A[3])*d);
	cout<<maxv<<endl;
			
}

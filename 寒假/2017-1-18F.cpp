#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL L,T,va,vb,n;
LL A[1000010],B[1000010];
int main(){
	cin>>L>>T>>va>>vb;
	scanf("%d",&n);
	int a,b,c;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)A[b]+=c;
		if(a==2)B[b]+=c;
	}
	LL sum=0;
	LL t1=0,t2=0;
	for(int i=0;i<T;i++){
		int v=0;
		if(A[i])t1=max(t1,A[i]);
		if(B[i])t2=max(t2,B[i]);
		if(t1)t1--;
		else v=va;
		if(t2)t2--;
		else v+=vb;
		sum+=v;
	} 
	cout<<sum/L<<endl;
}



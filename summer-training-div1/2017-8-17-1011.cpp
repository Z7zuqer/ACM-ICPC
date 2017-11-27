#include<bits/stdc++.h>
using namespace std;
int A[1010],B[1010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		long long sum1=0;
		long long sum2=0;
		long long sum3=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
		}
		for(int i=1;i<=n;i++){
			char s[2];
			scanf("%s",s);
			if(s[0]=='L')sum2-=A[i];
			if(s[0]=='N')sum1+=A[i];
			if(s[0]=='D')sum3+=A[i];
		}
		if(sum1>=k&&k>0)puts("yes");
		else if(sum2<=k&&k<0)puts("yes");
		else {
			if(k>0&&sum1+sum3>=k)puts("yes");
			else if(k<0&&sum2-sum3<=k)puts("yes");
			else puts("no");
		}
	}
}

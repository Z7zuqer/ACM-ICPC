#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int work(int k){
	int cnt=0;
	int last=sqrt(k);
	for(int i=2;i<=last;i++){
		if(k%i)continue;
		int flg=mp[i];
		if(flg==0)flg=1;
		while(k%i==0){
			k/=i;
			cnt+=flg;
		}
		if(k==1)return cnt;
	}
	if(k>1)
		if(mp[k]==-1)return cnt-1;
		else return cnt+1;
	return cnt;
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int A[5010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		mp[x]=-1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=work(A[i]);
	for(int i=n;i>=2;i--){
		int GCD=A[1],cnt=0;
		for(int j=2;j<=i;j++)GCD=gcd(GCD,A[j]);
		if((cnt=work(GCD))<0)
			for(int j=1;j<=i;j++)A[j]/=GCD,ans-=cnt;
	}
	int cnt=work(A[1]);
	if(cnt<0)ans-=cnt; 
	printf("%d\n",ans);
}

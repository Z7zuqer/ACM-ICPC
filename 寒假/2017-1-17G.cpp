#include<bits/stdc++.h>
using namespace std;
#define LL long long
int M[16],n,m;
int A[16];
LL ans; 
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
void dfs(int now){
	if(now>m){
		LL k=1;
		int siz=0; 
		for(int i=1;i<=m;i++){
			if(A[i]){
				siz++;
				k=lcm(k,M[i]);
			}
			if(k>n)return ;
		}
		if(!siz)return ;
		//cout<<k<<" "<<(siz%2==0?"-":"")<<n/k<<endl;
		//for(int i=1;i<=n;i++)
		//	if(i%k==0)cout<<i<<" ";cout<<endl;
		if(siz%2==0)ans-=n/k*(1LL<<(siz-1));//,cout<<-1*(n/k)<<endl;
		else ans+=n/k*(1LL<<(siz-1));//,cout<<n/k<<endl;
		return ;
	}
	A[now]=0;
	dfs(now+1);
	A[now]=1; 
	dfs(now+1);
}
int main(){ 
	//freopen("C://Users//Duhao//Desktop//input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d",&M[i]);
		dfs(1);
		cout<<ans<<endl;
	}
}



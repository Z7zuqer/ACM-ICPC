#include<bits/stdc++.h>
using namespace std;
int num[37],len,q;
long long dp[35][11][3];
unsigned long long fac[37];
void init(){
	fac[0]=1;
	fac[1]=1;
	for(int i=2;i<=18;i++)fac[i]=fac[i-1]*10LL;//,cout<<fac[i]<<endl;
}
long long dfs(int pre,int now,int equa,long long a){
	if(pre==0)return now==q;
	if(dp[pre][now][equa]!=-1)return dp[pre][now][equa];
	long long ans=0;
	if(now==q&&!equa)ans+=fac[pre+1];
	if(now==q&&equa)ans+=a%fac[pre+1]+1;
	int en=equa?num[pre-1]:9;
	//cout<<ans<<endl;
	for(int i=0;i<=en;i++)ans+=dfs(pre-1,i,equa&&(i==num[pre-1]),a);
	return dp[pre][now][equa]=ans;
}
long long getans(long long a){
	if(a<=0)return 0;
	len=0;
	memset(num,0,sizeof(num));
	memset(dp,-1,sizeof(dp));
	long long tmp=a;
	while(a){
		num[len++]=a%10;
		a/=10;
	}
	long long ans=0;
	for(int i=0;i<=num[len-1];i++)ans+=dfs(len-1,i,i==num[len-1],tmp);
	return ans;
}
int main(){
	long long a,b;
	init();
	int t;
	scanf("%d",&t); 
	while(t--){
		//memset(dp,-1,sizeof(dp));
		scanf("%lld%lld%d",&a,&b,&q);
		printf("%lld\n",getans(b)-getans(a-1));
	}
}

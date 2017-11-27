#include<bits/stdc++.h>
using namespace std;
long long dp[20][15];
void pre(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=9;i++)dp[1][i]=1;
	for(int i=2;i<=15;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2)
					dp[i][j]+=dp[i-1][k];
}
long long work(long long n){
	int num[17],len=0;
	while(n){
		num[++len]=n%10;
		n/=10;
	}
	num[len+1]=0;
	long long ans=0;
	for(int i=1;i<len;i++)
		for(int j=1;j<=9;j++)
			ans+=dp[i][j];
	//cout<<ans<<endl;
	for(int i=1;i<num[len];i++)
		ans+=dp[len][i];
	//cout<<ans<<endl;
	for(int i=len-1;i>0;i--){
		for(int j=0;j<num[i];j++)
			if(abs(j-num[i+1])>=2)ans+=dp[i][j];
		if(abs(num[i]-num[i+1])<2)break;
	}
	return ans;
}
int main(){
	pre();//cout<<work(1)<<endl;
	long long a,b;
	cin>>a>>b;
	cout<<work(b+1)-work(a)<<endl;
} 

#include<bits/stdc++.h>
using namespace std;
int next(int n,int k){
	if(!k)return 0;
	int num[110],len=0;
	long long tmp=(long long)k*(long long)k;
	while(tmp)num[len++]=tmp%10,tmp/=10;//,cout<<num[len-1]<<endl;
	int ans=0;
	if(n>len)n=len;
	for(int i=0;i<n;i++){
		ans*=10;
		ans+=num[--len];
	}
	return ans;
}
int main(){
	int n,k,t;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&k);
		int k1=k,k2=k,maxm=k;
		do{
			k1=next(n,k1);maxm=max(maxm,k1);
			k2=next(n,k2);maxm=max(maxm,k2);
			k2=next(n,k2);maxm=max(maxm,k2);
		}while(k1!=k2);
		cout<<maxm<<endl;
	}
}

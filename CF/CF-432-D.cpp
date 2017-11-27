#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[1001000],cnt[1001000];
LL pre[1001000];
int main(){
	int n;
	LL x,y;
	scanf("%d%I64d%I64d",&n,&x,&y);
	LL div=x/y;
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),cnt[A[i]]++,pre[A[i]]+=A[i];
	for(int i=1;i<=1000000;i++)pre[i]+=pre[i-1],cnt[i]+=cnt[i-1];
	long long ans=1e18;
	//cout<<div<<endl;
	for(int i=2;i<=1000000;i++){
		long long sum=0;
		int res=0,rem=0;
		for(int j=i;j<=1000000;j+=i){
			res+=cnt[j]-cnt[j-i];
			//cout<<res<<endl;
			if(div>i-1){
				rem+=cnt[j]-cnt[j-i];
				sum+=y*((cnt[j-1]-cnt[j-i])*j-pre[j-1]+pre[j-i]);
			}
			else {
				rem+=cnt[j]-cnt[j-div-1];
				sum+=y*((cnt[j-1]-cnt[j-div-1])*j-pre[j-1]+pre[j-div-1]);
				sum+=x*(cnt[j-div-1]-cnt[j-i]);
			}
		}
		//cout<<res<<" "<<sum<<" "<<rem<<endl;
		if(sum<ans&&res==n&&rem>0)ans=sum;
	}
	printf("%I64d\n",ans);
}



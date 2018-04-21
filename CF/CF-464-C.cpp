#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int s,f;
	scanf("%d%d",&s,&f);
	LL nowsum=0,maxv=0;
	int ans=0;
	for(int i=s;i<f;i++)nowsum+=A[i];
	maxv=nowsum;
	int mins_id=f-1,plus_id=s-1;
	if(mins_id==0)mins_id=n;
	if(plus_id==0)plus_id=n;
	for(int i=1;i<n;i++){
		nowsum-=A[mins_id];
		nowsum+=A[plus_id];
		if(nowsum>maxv){
			maxv=nowsum;
			ans=i;
		}
		mins_id--;if(mins_id==0)mins_id=n;
		plus_id--;if(plus_id==0)plus_id=n;
	}
	cout<<ans+1<<endl;
}



#include<bits/stdc++.h>
using namespace std;
#define LL long long
int num[100100];
int main(){
	int n;
	scanf("%d",&n);
	int maxm=0;
	LL ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		maxm=max(maxm,num[i]);
	}
	maxm++;
	int cnt=0;
	for(int i=n;i>=1;i--){
		if(num[i]==0||num[i]==maxm-1){
			maxm--;
		}
		else {
			ans+=
		}
	}
	cout<<ans<<endl;
}



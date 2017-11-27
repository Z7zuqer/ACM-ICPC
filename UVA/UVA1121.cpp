#include<bits/stdc++.h>
using namespace std;
int a[100010];
int res[100010];
int main(){
	int n,s,x;
	while(cin>>n>>s){
		for(int i=1;i<=n;i++){
			cin>>x;
			a[i]=a[i-1]+x;
		}
		int maxm=n+1,sum=0,wh=1;
		for(int i=1;i<=n;i++){
			if(a[wh-1]>a[i]-s)continue;
			while(a[wh]<=a[i]-s)wh++;
			maxm=min(maxm,i-wh+1);
		}
		if(maxm==n+1)cout<<0<<endl;
		else cout<<maxm<<endl;
	}
}



#include<bits/stdc++.h>
using namespace std;
int a[20020];
int r[20020];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(!n&&!m)break;
		for(int i=1;i<=n;i++)scanf("%d",&r[i]);
		sort(r+1,r+1+n);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+m);
		int wh=1,ans=0;
		for(int i=1;i<=m;i++){
			if(a[i]>=r[wh])ans+=a[i],wh++;
			if(wh>n)break;
		}
		if(wh>n)cout<<ans<<endl;
		else cout<<"Loowater is doomed!"<<endl;
	}
} 

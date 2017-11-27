#include<bits/stdc++.h>
using namespace std;
int ans,n;
int sea[77];
void dfs(int now){
	if(now>8)ans++;
	for(int i=1;i<=n;i++){
		int nxt=(i+1)%n;if(nxt==0)nxt=n;
		int pre=(i-1+n)%n;if(pre==0)pre=n;
		//cout<<nxt<<" "<<pre<<endl;
		if(sea[i]==-1&&sea[pre]==-1&&sea[nxt]==-1){
			sea[i]=1;
			dfs(now+1);
			sea[i]=-1;
		}
	}
}
int divv;
void dfs2(int now){
	if(now>8)ans++;
	for(int i=1;i<=n;i++){
		int nxt=(i+1)%n;if(nxt==0)nxt=n;
		int pre=(i-1+n)%n;if(pre==0)pre=n;
		//cout<<nxt<<" "<<pre<<endl;
		int opp;
		if(i>divv)opp=i-divv;
		else opp=divv+i;
		if(sea[i]==-1&&sea[pre]==-1&&sea[nxt]==-1&&sea[opp]==-1){
			sea[i]=1;
			dfs2(now+1);
			sea[i]=-1;
		}
	}
}
int main(){	
	memset(sea,-1,sizeof sea);
	for(n=17;n<=25;n++){
		ans=0;
		if(n&1)dfs(1);
		else divv=n/2,dfs2(1);
		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}



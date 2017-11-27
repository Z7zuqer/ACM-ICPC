#include<bits/stdc++.h>
using namespace std;
char s[100100]; 
int vis[100100];
vector<int>v;
int main(){
	int sta,n;
	scanf("%d%d%s",&n,&sta,s+1);
	int k=sta;
	for(int i=1;i<=n;i++){
		if(n-i+1<=i)break;
		if(s[n-i+1]!=s[i])
			v.push_back(i),vis[i]=1,vis[n-i+1]=1;
	}
	int ans=0,res=0;
	while(res<v.size()){
		if(vis[sta]){
			vis[sta]=vis[n-sta+1]=0;
			ans+=min(min(abs(s[n-sta+1]-s[sta]),1+abs(s[sta]-'z')+abs(s[n-sta+1]-'a')),1+abs(s[sta]-'a')+abs(s[n-sta+1]-'z'));
			if(++res>=v.size())break;
			ans++;
			sta=(sta+1)%n;if(sta==0)sta=n;
		}
		else {
			ans++;
			sta=(sta+1)%n;if(sta==0)sta=n;
		}
	}
	int maxv=ans;ans=0;sta=k;res=0;
	for(auto i:v)vis[i]=vis[n-i+1]=1;
	while(res<v.size()){
		if(vis[sta]){
			vis[sta]=vis[n-sta+1]=0;
			ans+=min(min(abs(s[n-sta+1]-s[sta]),1+abs(s[sta]-'z')+abs(s[n-sta+1]-'a')),1+abs(s[sta]-'a')+abs(s[n-sta+1]-'z'));
			if(++res>=v.size())break;
			ans++;
			sta=(sta-1+n)%n;if(sta==0)sta=n;
		}
		else {
			ans++;
			sta=(sta-1+n)%n;if(sta==0)sta=n;
		}
	}
	printf("%d\n",min(maxv,ans));
}



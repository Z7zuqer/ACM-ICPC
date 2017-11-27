#include<bits/stdc++.h>
using namespace std;
int tim[100100];// in size
char s[15],r[5];
map<string,int>mp;
int c[100100],n;
void add(int x,int v){
	while(x<=n+5){
		c[x]+=v;
		x+=x&-x;
	}
}
int getans(int x){
	int ans=0;
	while(x){
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(tim,0,sizeof tim);
		memset(c,0,sizeof c);
		mp.clear();
		int in=0,out=0,ans=0,cnt=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s%s",r,s);
			if(r[0]=='i'){
				int k=mp[(string)s];
				if(!k)mp[(string)s]=k=cnt++;
				add(i,1);
				tim[k]=i;
			}
			if(r[0]=='o'){
				int k=mp[(string)s];
				add(tim[k],-1);
				if(getans(tim[k]-1)==0)ans++;
			}
		}
		cout<<ans<<endl;
	}
}



#include<bits/stdc++.h>
using namespace std;
int n;
int A[27];
char s[1010];
map<int,int>mp;
int bitcount(int x){
	return x==0?0:bitcount(x/2)+(x&1);
}
int main(){
	while(scanf("%d",&n)==1){
		mp.clear();
		memset(A,0,sizeof(A));
		for(int i=0;i<n;i++){
			scanf("%s",s);
			for(int j=0;s[j];j++)A[i]^=(1<<(s[j]-'A'));
		}
		int n1=n/2,n2=n-n1;
		for(int i=0;i<(1<<n1);i++){
			int x=0;
			for(int j=0;j<n1;j++)if(i&(1<<j))x^=A[j];
			if(!mp[x]||bitcount(i)>bitcount(mp[x]))mp[x]=i;
		}
		int ans=0;
		//cout<<ans<<endl;
		for(int i=0;i<(1<<n2);i++){
			int x=0;
			for(int j=0;j<n2;j++)if(i&(1<<j))x^=A[j+n1];
			if(mp[x]&&bitcount(ans)<bitcount(i)+bitcount(mp[x]))ans=(i<<n1)^mp[x];
		}
		cout<<bitcount(ans)<<endl;
		for(int i=0;i<n;i++)if(ans&(1<<i))cout<<i+1<<" ";
		cout<<endl;
		//cout<<endl;
	}
}



#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10;
int n,nextn[maxn<<1];
char s[maxn<<1];
int dfs(int l,int r,int flg){
	if(nextn[l]>=r){
		if(s[l]=='A')return 1;
		return -1;
	}
	if(((r-l+1)%2==0)&&((r-l+1)/2)%2==1)return 0;
	int A=dfs(l,(l+r)/2,!flg);
	int B=dfs((l+r)/2+1,r,!flg);
	if(flg){
		if(A==-1||B==-1)return -1;
		if(A==0||B==0)return 0;
		return 1;
	}
	if(!flg){
		if(A==1||B==1)return 1;
		if(A==0||B==0)return 0;
		return -1;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s%s",s,s+n);
	for(int i=n*2-1;i>=0;i--){
		if(s[i]==s[i+1])nextn[i]=nextn[i+1];
		else nextn[i]=i;
		//cout<<s[i]<<endl;
	}
	int res=dfs(0,2*n-1,0);
	if(res==1)cout<<"Alice"<<endl;
	else if(res==-1)cout<<"Bob"<<endl;
	else cout<<"Draw"<<endl;
}



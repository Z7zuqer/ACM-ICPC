#include<bits/stdc++.h>
using namespace std;
#define LL long long
char s[77];
int num;
char tmp[128];
void pre(int k){
	num=0;
	while(k){
		tmp[num++]='0'+k&1;
		k>>=1;
	}
}
int main(){
	freopen("semipal.in","r",stdin);
	freopen("semipal.out","w",stdout);
	int T;
	int n;
	LL k;
	scanf("%d",&T);
	while(T--){
		num=0;
		memset(s,0,sizeof(s));
		memset(tmp,0,sizeof(tmp));
		cin>>n>>k;
		int flg=0;
		LL x=1LL<<(n-2);
		if(k>x){
			flg=1;
			k-=x;
			k--;
		}
		else {
			k--;	
		}
		if(flg==1)
			cout<<'b';
		else 
			cout<<'a';
		for(int i=n-3;i>=0;i--){
			if(k&(1LL<<i))
				cout<<'b';
			else 
				cout<<'a';
		}
		if(flg==1)
			cout<<'b';
		else 
			cout<<'a';
		cout<<endl;
	}
}



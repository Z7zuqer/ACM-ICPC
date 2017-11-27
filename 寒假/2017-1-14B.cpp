#include<bits/stdc++.h>
using namespace std;
int num[11]={6,2,5,5,4,5,6,3,7,6};
char s[100010];
int main(){
	int n;
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d%s",&n,s);
		int cnt=0;
		for(int i=0;s[i];i++)cnt+=num[s[i]-'0'];
		
		for(int i=1;i<=n;i++){
			if(cnt>=6&&(n-i)*2<=cnt-6&&(n-i)*7>=cnt-6)cout<<9,cnt-=6;
			else if(cnt>=7&&(n-i)*2<=cnt-7&&(n-i)*7>=cnt-7)cout<<8,cnt-=7;
			else if(cnt>=3&&(n-i)*2<=cnt-3&&(n-i)*7>=cnt-3)cout<<7,cnt-=3;
			else if(cnt>=5&&(n-i)*2<=cnt-5&&(n-i)*7>=cnt-5)cout<<5,cnt-=5;
			else if(cnt>=4&&(n-i)*2<=cnt-4&&(n-i)*7>=cnt-4)cout<<4,cnt-=4;
			else cout<<1,cnt-=2;
		}
		cout<<endl;
	}
}



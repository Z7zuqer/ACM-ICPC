#include<bits/stdc++.h>
using namespace std;
char s1[110],s2[110]; 
int main(){
	int t,cas=1;
	cin>>t;
	while(t--){
		scanf("%s%s",s1,s2);
		int len=strlen(s1);
		int c1=0,c0=0,res=0;
		int b1=0,b0=0;
		for(int i=0;i<len;i++){
			if(s1[i]!='?'&&s1[i]!=s2[i]){
				if(s1[i]=='0')c0++;
				if(s1[i]=='1')c1++;
			}
			else if(s1[i]=='?'){
				if(s2[i]=='0')b0++;
				if(s2[i]=='1')b1++;
			}
		}
		printf("Case %d: ",cas++);
		int ans=min(c0,c1);
		if(c0>=c1)c0-=c1,c1=0;
		else c1-=c0,c0=0;
		if(c0){
			cout<<c0+ans+b0+b1<<endl;
		}
		else if(c1){
			if(c1>b1)cout<<"-1"<<endl;
			else cout<<ans+c1+b0+b1<<endl;
		}
		else cout<<ans+b0+b1<<endl;
	}
}



#include<bits/stdc++.h>
using namespace std;
char s[101010];
string get(int sta,int end){
	string r="";
	for(int i=sta;i<=end;i++)r+=s[i];
	return r;
}
int main(){
	gets(s);
	int now=0,end=strlen(s);
	int minv=1e9;
	string ans="";
	while(now<end){
		int pre=now;
		while(s[now]!=' '&&s[now]!='.'&&now<end)now++;
		string res=get(pre,now-1);
		//cout<<res<<endl;
		if(res.size()<minv)ans=res,minv=res.size();
		if(s[now]=='.')break;
		now++;
	}
	cout<<ans<<endl;
}



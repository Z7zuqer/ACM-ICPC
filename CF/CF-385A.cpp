#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
	string s;
	cin>>s;
	int len=s.length(),ans=0;
	for(int i=0;i<len;i++){
		string tmp="";
		for(int j=0;j<len;j++)tmp+=s[(i+j)%len];
		if(!mp[tmp]){
			ans++;
			mp[tmp]=1;
		}
	}
	cout<<ans<<endl;
} 

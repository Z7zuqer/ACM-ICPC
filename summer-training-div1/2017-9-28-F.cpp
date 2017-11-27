#include<bits/stdc++.h>
using namespace std;
string mul(string k){
	string ans="[";
	ans+=k;
	ans+="]";
	return ans;
}
string add(string k){
	k+='1';
	return k;
}
string res;
void dfs(int now){
	if(now==0)return ;
	if(now==2){
		res='1';
		res+='1';
		return ;
	}
	if(now&1){
		dfs(now-1);
		res=add(res);
	}
	else {
		dfs(now/2);
		res=mul(res);
		//cout<<res<<" "<<now<<endl;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	res="";
	//res=add(res);
	dfs(n);
	cout<<res<<endl;
}



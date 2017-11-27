#include<bits/stdc++.h>
using namespace std;
int n,m;
map<pair<string,int> ,int>mp;
map<string,int>mpp;
map<int,string>mppp;
int maxv[100100],cnt[100100];
int main(){
	ios_base::sync_with_stdio(false);
	cin>>m>>n;
	int name=0;
	for(int i=1;i<=m;i++){
		int a,b;
		string s;
		cin>>a>>b>>s;
		mp[{s,b}]++;
		if(!mpp[s]){
			mpp[s]=++name;
			mppp[name]=s;
		}
	}
	map<pair<string,int> ,int>::iterator it=mp.begin();
	for(;it!=mp.end();it++){
		string s=it->first.first;
		int times=it->second;
		int idx=it->first.second;
		int k=mpp[s];
		if(maxv[k]<times){
			maxv[k]=times;
			cnt[k]=idx;
		}
		else if(maxv[k]==times){
			cnt[k]=min(cnt[k],idx);
		}
	}
	for(int i=1;i<=name;i++){
		cout<<mppp[i]<<" "<<cnt[i]<<endl;
	}
}



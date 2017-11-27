#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
vector<int>v;
int main(){
	int t;
	cin>>t;
	while(t--){
		mp.clear();
		v.clear();
		int n,x,mx=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			mp[x]++;
			mx=max(mx,x);
		}
		int flg=0;
		map<int,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second>=2)v.push_back(it->first),flg=1;
		}
		if(flg){
			for(int i=0;i<v.size()-1;i++)cout<<v[i]<<" ";
			cout<<v[v.size()-1]<<endl;
		}
		if(!flg)cout<<"none"<<endl;
	}
} 

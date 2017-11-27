#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
map<int,string>pm;
int whe[209][101],whee[209][101];
int main(){
	int T;
	cin>>T;
	//sync_with_stdio(false);
	while(T--){
		int n,q,cnt=1;
		memset(whe,0,sizeof(whe));
		memset(whee,0,sizeof whee);
		mp.clear();pm.clear();
		cin>>n>>q;
		int c;
		cin>>c;
		string name;
		for(int i=1;i<=c;i++){
			cin>>name;
			mp[name]=i;pm[i]=name;
		}
		for(int i=1;i<=q;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>name;
				whee[mp[name]][i]=1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=q;j++){
				int x;
				cin>>x;
				whe[i][j]=x;
			}
		for(int i=1;i<=n;i++){
			int flg=0,ans=0;
			for(int j=1;j<=c;j++){
				int tmp=1;
				for(int r=1;r<=q;r++){
					if(whe[i][r]!=whee[j][r]){
						tmp=0;
						break;
					}
				}
				if(tmp){
					flg++;
					ans=j;
				}
			}
			if(flg==1)cout<<pm[ans]<<endl;
			else cout<<"Let's go to the library!!"<<endl;
		}	
	}
}



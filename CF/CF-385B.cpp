#include<bits/stdc++.h>
using namespace std;
int n,m;
char mp[510][510];
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	int l=1e9+1,r=0,u=0,d=1e9+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(mp[i][j]=='X'){
				l=min(l,j);
				r=max(r,j);
				u=max(u,i);
				d=min(d,i);
			}
		}
	for(int i=d;i<=u;i++)
		for(int j=l;j<=r;j++){
			if(mp[i][j]!='X'){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	cout<<"YES"<<endl;
}

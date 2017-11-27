#include<bits/stdc++.h>
using namespace std;
int n,A[100010]; 
map<int,int>mp;
int main(){
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=n;i++){
			if(!mp[A[i]])mp[A[i]]=1;
			else{
				ans++;
				mp.clear();
				mp[A[i]]=1;
			}
		}
		if(mp.size())ans++,mp.clear();
		printf("%d\n",ans);
	}
}



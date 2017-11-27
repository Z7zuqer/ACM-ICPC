#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char s[110];
	int ans=0,pre=-1,k=0;
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		int flg=0;
		for(int j=0;j<n;j++)
			if(s[j]=='0'){
				flg=1;
				break;
			}
		if(flg){
			k++;
		}
		else {
			ans=max(ans,k);
			k=0;
		}
	}
	ans=max(ans,k);
	cout<<ans<<endl;
}



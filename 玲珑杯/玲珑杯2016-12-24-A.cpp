#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int s1[100010],s2[100010];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,flg=0;
		scanf("%d",&n);
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),s1[i]=s1[i-1]+a[i];
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),s2[i]=s2[i-1]+b[i];
		sort(s1+1,s1+n);
		sort(s2+1,s2+n);
		for(int i=1;i<=n;i++){
			if(s1[i]!=s2[i]){
				flg=1;
				cout<<"No"<<endl;
				break;
			}
		}
		if(!flg)cout<<"Yes"<<endl;
	}
}

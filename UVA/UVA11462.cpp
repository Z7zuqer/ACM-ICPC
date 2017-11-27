#include<bits/stdc++.h>
using namespace std;
int cnt[100];
int main(){
	int n;
	while(cin>>n&&n){
		short x;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>x;
			cnt[x-1]++;
		}
		n=0;
		for(int i=0;i<=99;i++){
			if(cnt[i]&&!n)printf("%d",i+1),cnt[i]--,n=1;
			while(cnt[i])printf(" %d",i+1),cnt[i]--;
		}
		cout<<endl;
	}
}

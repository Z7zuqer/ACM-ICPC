#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+7;
int num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		int x;
		scanf("%d",&x);
		return 0*printf("YES\n%d %d\n",1,x);
	}
	scanf("%d",&num[1]);
	map<int,int>mp;
	int maxm=num[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&num[i]);
		int cnt=abs(num[i]-num[i-1]);
		mp[cnt]++;
		if(mp.size()>2)return 0*printf("NO\n");
		maxm=max(maxm,num[i]);
	} 
	if(mp.size()==1){
		int X=-1,Y=-1;
		map<int,int>::iterator it=mp.begin();
		if(it->first==1){
			X=maxm;
			Y=1;
		}
		else {
			X=it->first;
			Y=maxm/X+1;
		}
		printf("YES\n%d %d\n",Y,X);
	}
	else if(mp.size()==2){
		int k1=-1,k2=-1;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			if(k1==-1)k1=it->first;
			else k2=it->first;
		}
		int X=-1,Y=-1;
		if(k1==1)X=k2;
		else X=k1;
		if(X==0)while(1);
		Y=maxm/X+1;
		printf("YES\n%d %d\n",Y,X);
	}
}



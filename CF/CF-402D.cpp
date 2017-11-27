#include<bits/stdc++.h>
using namespace std;
char s[200100],r[200100],ss[110];
int A[200100],cnt[200100];
int work(int k,int n,int nn){
	//if(n-k)
	int wh=0;
	for(int i=0;i<n;i++){
		if(cnt[i]<=k-1)continue;
		if(ss[wh]==s[i])wh++;
		if(wh>=nn)return 1;
		//cout<<i<<endl;
	}
	//cout<<endl;
	if(wh>=nn)return 1;
	return 0;
}
int main(){
	scanf("%s%s",s,ss);
	int n=strlen(s),nn=strlen(ss);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		cnt[A[i]-1]=i;
	}
	//for(int i=0;i<n;i++)cout<<cnt[i]<<endl;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(work(mid,n,nn))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}



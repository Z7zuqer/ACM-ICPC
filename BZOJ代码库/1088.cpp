#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int n,seq[maxn],f[maxn];
bool cek(){
	for(int i=2;i<=n;i++){
		f[i+1]=seq[i]-f[i]-f[i-1];
		if(f[i+1]<0)return 0;
	}
	if(seq[n]-f[n]-f[n-1]!=0)return 0;
	return 1;
}
int main(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&seq[i]);
	if(seq[1]==0)ans+=cek();
	else if(seq[1]==1){
		f[1]=1;ans+=cek();
		memset(f,0,sizeof(f));
		f[2]=1;ans+=cek();
	}
	else {
		f[1]=f[2]=1;ans+=cek();
	}
	cout<<ans<<endl;
}

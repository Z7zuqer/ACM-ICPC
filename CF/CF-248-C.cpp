#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100100],pre[100100];
vector<LL>v[100100];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%I64d",&A[i]);
	if(m==1)return 0*printf("0\n");
	for(int i=1;i<=m;i++){
		if(i==1){
			if(A[i]!=A[2])v[A[i]].push_back(A[2]);
			pre[A[i]]+=abs(A[1]-A[2]);
		}
		else if(i==m){
			if(A[i]!=A[m-1])v[A[i]].push_back(A[m-1]);
			pre[A[i]]+=abs(A[m]-A[m-1]);
		}
		else {
			pre[A[i]]+=abs(A[i]-A[i-1])+abs(A[i]-A[i+1]);
			if(A[i-1]!=A[i])v[A[i]].push_back(A[i-1]);
			if(A[i+1]!=A[i])v[A[i]].push_back(A[i+1]);
		}
	}
	LL maxm=0;
	LL x=-1,y=-1;
	for(int i=1;i<=n;i++){
		if(v[i].size()==0)continue;
		sort(v[i].begin(),v[i].end());
		int siz=v[i].size();
		int mid=siz/2+1;
		LL div=v[i][mid-1];
		//if(div==i)continue;
		LL sum=0;
		for(int j=0;j<v[i].size();j++)sum+=abs(v[i][j]-1LL*div);
		//cout<<sum<<" "<<pre[i]<<endl;
		if(maxm<pre[i]-sum){
			maxm=pre[i]-sum;
			x=i;
			y=div;
		}
	}
	LL ans=0;
	//cout<<x<<" "<<y<<endl;
	for(int i=1;i<=m;i++)if(A[i]==x)A[i]=y;
	for(int i=1;i<=m;i++){
		//if(A[i]==x)A[i]=y;
		if(i==1);//ans+=abs(A[1]-A[2]);
		else if(i==m)ans+=abs(A[i]-A[i-1]);
		else ans+=abs(A[i]-A[i-1]); 
	}
	cout<<ans<<endl;
}



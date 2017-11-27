#include<bits/stdc++.h>
using namespace std;
int A[100005];
struct node{
	int v,x;
}r[100005];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int cmp(node m,node n){
	return m.v<n.v;
}
int main(){
	int n,cas=1;
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;i++)scanf("%d",&A[i]),r[i].v=A[i],r[i].x=i;
		sort(r+1,r+1+n,cmp);
		int flg=0,re=0;
		vector<pair<int,int> >v;
		for(int i=2;i<=n;i++){
			A[1]=A[i]=gcd(A[1],A[i]);
			v.push_back({1,i});
			if(A[1]==1)flg=1;
		}
		if(flg)
			for(int i=1;i<=n;i++)
				if(A[i]!=1)A[1]=A[i]=1,v.push_back({1,i});
		printf("Case %d: ",cas++);
		if(flg&&v.size()<=5*n){
			printf("%d\n",v.size());
			for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].first,v[i].second);
			
		}
		else printf("-1\n");
		cout<<endl;
	}
}



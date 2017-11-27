#include<bits/stdc++.h>
using namespace std;
struct node{
	int p,c,idx;
}A[1010];
int cmp(node m,node n){
	return m.p>n.p;
}
struct NODE{
	int idx,x;
}B[1010];
int cmp1(NODE m,NODE n){
	return m.x<n.x;
}
vector<pair<int,int> >v;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&A[i].c,&A[i].p);
		A[i].idx=i;
	}
	sort(A+1,A+1+n,cmp);
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&(B[i].x));
		B[i].idx=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		sort(B+1,B+1+k,cmp1);
		for(int j=1;j<=k;j++){
			if(B[j].x>=A[i].c){
				B[j].x=0;
				ans+=A[i].p;
				v.push_back({A[i].idx,B[j].idx});
				break;
			}
		}
	}
	printf("%d %d\n",v.size(),ans);
	for(int i=0;i<v.size();i++){
		printf("%d %d\n",v[i].first,v[i].second);
	}
}



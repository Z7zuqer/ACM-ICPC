#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int cnt[1007];
struct node{
	int p,q;
}a[1007][1007];
bool cmp(node m,node n){
	return m.p<n.p;
}
int b;
int r=1;
int check(int p){
	long long s=0;
	for(int i=1;i<r;i++){
		int flg=0,minx=1e9;
		for(int j=0;j<cnt[i];j++){
			if(a[i][j].q>=p){
				minx=min(minx,a[i][j].p);
				flg=1;
			}
		}
		if(minx>=b)return 0;
		s+=minx;
		if(s>b)return 0;
		if(!flg)return 0;
	}
	return s<=b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,rr=-1,l=0;
		r=1;
		scanf("%d%d",&n,&b);
		//cin>>n>>b;
		memset(cnt,0,sizeof(cnt));
		string s1,s2;
		for(int i=1;i<=n;i++){
			//cnt[i]=0;
			int x,y;
			cin>>s1>>s2;
			scanf("%d%d",&x,&y);//>>x>>y;
			if(!mp[s1])mp[s1]=r++;
			int wh=mp[s1];
			a[wh][cnt[wh]].p=x;
			a[wh][cnt[wh]++].q=y;
			rr=max(rr,y);
		}
		//int ans=-1;
		//for(int i=1;i<r;i++)sort(a[i],a[i]+cnt[i]-1,cmp);
		while(l<rr){
			int mid=(rr+l)/2;
			if(check(mid))l=mid;//+1,ans=mid;
			else rr=mid-1;
		}
		printf("%d\n",l);
	}
}

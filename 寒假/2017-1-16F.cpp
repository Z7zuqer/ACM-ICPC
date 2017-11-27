#include<bits/stdc++.h>
using namespace std;
int n,m,src[21];
map<string,int>mp;
map<int,string>mpp;
int num=0;
char s1[100],s2[100];
struct node{
	int sce,sig,high,low;
}A[21];
struct {
	int x,y,re;
}B[1010];
void print(int k,int high,int low){
	if(high==1)cout<<"Team "<<mpp[k]<<" can finish as high as "<<high<<"st place and as low as ";
	else if(high==2)cout<<"Team "<<mpp[k]<<" can finish as high as "<<high<<"nd place and as low as ";//1st place."<<endl;
	else if(high==3)cout<<"Team "<<mpp[k]<<" can finish as high as "<<high<<"rd place and as low as ";//1st place."<<endl;
	else cout<<"Team "<<mpp[k]<<" can finish as high as "<<high<<"th place and as low as ";
	if(low==1)cout<<low<<"st place."<<endl;
	else if(low==2)cout<<low<<"nd place."<<endl;
	else if(low==3)cout<<low<<"rd place."<<endl;
	else cout<<low<<"th place."<<endl;
}

void dfs(int now){
	if(now>=num){
		for(int i=1;i<=n;i++){
		int rk1=0;
		for(int j=1;j<=n;j++)
			if(A[j].sce>A[i].sce)rk1++;
			A[i].high=min(rk1+1,A[i].high);
			A[i].low=max(rk1+1,A[i].low);
		}	
		return ;
	}
	A[B[now].x].sce+=3;
	dfs(now+1);
	A[B[now].x].sce-=3;
	A[B[now].y].sce+=3;
	dfs(now+1);
	A[B[now].y].sce-=3;
	A[B[now].x].sce++;A[B[now].y].sce++;
	dfs(now+1);
	A[B[now].x].sce--;A[B[now].y].sce--;
}
int main(){
	int cas=0;
	while(scanf("%d%d",&n,&m)&&n+m!=0){
		if(cas!=0)cout<<endl;cas++;
		memset(src,0,sizeof(src));
		num=0;
		mp.clear();mpp.clear();
		for(int i=1;i<=n;i++)cin>>s1,mp[string(s1)]=i,mpp[i]=string(s1);
		for(int i=0;i<m;i++){
			int n1,n2;
			scanf("%s%*s%s%d%d",s1,s2,&n1,&n2);
			s2[strlen(s2)-1]=0;
			if(n1==-1){
				B[num].x=mp[string(s1)];
				B[num++].y=mp[string(s2)];
				continue;
			}
			if(n1>n2)src[mp[string(s1)]]+=3;
			if(n1<n2)src[mp[string(s2)]]+=3;
			if(n1==n2)src[mp[string(s1)]]++,src[mp[string(s2)]]++;
		}
		for(int i=1;i<=n;i++)A[i].sce=src[i],A[i].sig=i,A[i].high=26,A[i].low=-1;
		dfs(0);
		for(int i=1;i<=n;i++)
			print(i,A[i].high,A[i].low);
	}
}



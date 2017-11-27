#include<bits/stdc++.h>
using namespace std;
int vis[50000+7];
int A[50010],nex[50010];
void print(int wh){
	printf("? %d\n",wh);
	fflush(stdout);
}
void read(int &x,int &y){
	scanf("%d%d",&x,&y);
}
int main(){
	int n,sta,x;
	scanf("%d%d%d",&n,&sta,&x);
	if(n<2000){
		int minv=1e9+1,xx;
		for(int i=1;i<=n;i++){
			print(i);
			int tmp;
			scanf("%d%d",&tmp,&xx);
			if(tmp>=x)minv=min(minv,tmp);	
		}
		//if(A[i]>x){
		//	minv=min(minv,A[i]);
		//}
		if(minv==1e9+1)printf("! -1\n");
		else printf("! %d\n",minv);
		fflush(stdout);
		return 0;
	}
	int req,reqv;
	print(sta);read(reqv,req);vis[sta]=1;
	if(reqv>=x)return 0*printf("! %d\n",reqv);
	nex[sta]=req;A[sta]=reqv;
	int res=998;
	srand(time(0));
	int maxv=0,wh=-1;
	while(res){
		int reqk=rand()%n;if(reqk==0)reqk=n;
		if(vis[reqk])continue;
		print(reqk);read(A[reqk],nex[reqk]);req--;vis[reqk]=1;
		if(A[reqk]<=x){
			maxv=max(maxv,A[reqk]);
			wh=reqk;
		}
	}
	res=1000;
	int ans=1e9+1;
	while(nex[wh]!=-1&&res){
		int reqk=nex[wh];wh=reqk;
		if(vis[reqk])continue;
		print(wh);read(A[wh],nex[wh]);vis[wh]=1;res--;
		if(A[wh]>=x)ans=min(ans,A[wh]);
	}
	if(ans==1e9+1)printf("! -1\n");
	else printf("! %d\n",ans);
}



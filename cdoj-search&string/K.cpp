#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,ans_w,ans_v,V;
LL cnt=0,pre[82],times=8999999;
struct node{
	LL w,v;
}r[82];
int cmp(node m,node n){
	if(m.v==n.v)return m.w>n.w;
	return m.v<n.v;
}
void dfs(int now,LL now_v,LL now_w){
	if(now>n+1)return ;
	if(now_w<ans_w&&now_v>ans_v)return ;
	if(now_w+pre[now]<=ans_w)return ;
	if(now_w>ans_w){
		ans_w=now_w;
		ans_v=now_v;
	}	
	if(V-now_v<r[now].v)return ;
	if(cnt>times)return ;cnt++;
	dfs(now+1,now_v,now_w);
	if(V-now_v>=r[now].v)dfs(now+1,now_v+r[now].v,now_w+r[now].w);
}
int cmp2(node m,node n){
	return (double)m.w/(double)n.v>(double)n.w/(double)n.v;
}
int main(){
	//freopen("C://Users//Duhao//Desktop//in.txt","r",stdin);
	//int t=clock();
	while(scanf("%d%lld",&n,&V)==2){
		ans_v=0;ans_w=0;cnt=0;
		for(int i=1;i<=n;i++)scanf("%lld%lld",&r[i].v,&r[i].w);
		sort(r+1,r+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(ans_v+r[i].v<=V)ans_v+=r[i].v,ans_w+=r[i].w;
			else break;
		}
		sort(r+1,r+1+n,cmp);
		pre[n+1]=0;for(int i=n;i>=1;i--)pre[i]=pre[i+1]+r[i].w;
		dfs(1,0,0);
		printf("%lld\n",ans_w);		
	}
	//cout<<clock()-t<<endl;
}



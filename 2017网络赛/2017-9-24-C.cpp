#include<bits/stdc++.h>
using namespace std;
int A[1010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int pri=x,r=-1,res;
		while(scanf("%d",&res)!=EOF){
			if(res==-1)break;
			int req;
			scanf("%d",&req);
			if(req==pri&&(res<r||r==-1)||req>pri){
				r=res;
				x=pri;
				pri=req;
			}
			else x=max(x,req);
		}
		if(r!=-1)A[r]+=min(pri,(int)floor(x*1.1));
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		printf("%d\n",A[x]);
	}
}


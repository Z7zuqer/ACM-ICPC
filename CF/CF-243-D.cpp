#include<bits/stdc++.h>
using namespace std;
int mp[110][110];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	if(m<=k){
		int all=1<<m;all--;
		int minm=1e9;
		for(int sta=0;sta<=all;sta++){
			int tmp=0;
			for(int i=1;i<=n;i++){
				int cnt=0;
				for(int j=1;j<=m;j++)
					if((1<<(j-1)&sta)>0&&mp[i][j]==1)cnt++;
					else if((1<<(j-1)&sta)==0&&mp[i][j]==0)cnt++;
				cnt=min(cnt,m-cnt);
				tmp+=cnt;
			}
			minm=min(minm,tmp);
		}
		//cout<<minm<<endl;
		if(minm==1e9)puts("0");
		else if(minm>k)printf("-1\n");
		else printf("%d\n",minm);
	}
	else {
		int minm=1e9;
		for(int sel=1;sel<=m;sel++){
			int tmp=0;
			for(int j=1;j<=m;j++){
				if(j==sel)continue;
				int cnt=0;
				for(int i=1;i<=n;i++)
					if(mp[i][j]==mp[i][sel])cnt++;
				cnt=min(cnt,n-cnt);
				tmp+=cnt;
			}
			//cout<<tmp<<endl;
			minm=min(minm,tmp);
		}
		if(minm==1e9)puts("0");
		else if(minm>k)printf("-1\n");
		else printf("%d\n",minm);
	}
}



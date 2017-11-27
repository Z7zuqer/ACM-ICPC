#include<bits/stdc++.h>
using namespace std;
struct node{
	int sta;
	int step,wh;
}; 
int stat[22];
void trans(int sta){
	for(int i=)
}
int main(){
	int T:
	scanf("%d",&T);
	while(T--){
		int now=0,now_wh=-1;
		mp.clear();
		for(int i=0;i<6;i++)
			for(int j=0;j<=i;j++){
				int x;
				scanf("%d",&x);
				init_sta[now++]=x;
				if(x==0)now_wh=now-1;	
			}
		while(!q.empty())q.pop();
		q.push({init_sta,now_wh});
		mp[get_hash(init_sta)]=1;
		int flg=bfs();
		if(flg==-1)puts("too difficult");
		else printf("%d\n",flg);
	}
}



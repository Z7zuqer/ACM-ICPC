#include<bits/stdc++.h>
using namespace std;
#define POINT2(x,y) make_pair(x,y)
#define POINT(x,y,z) make_pair(x,make_pair(y,z))
map<pair<int,pair<int,int> >,int>mp; 
map<pair<int,int>,int>mp_2;
vector<int>v[120000];
vector<int>v_2[120000];
int vis[120000],maxm,flg_h,tot,tot_2;
int deg[120000],deg2[120000],dis[120000];
int topo_2(){
	queue<int>q;
	for(int i=1;i<=tot_2;i++)
		if(deg2[i]<=1)
			q.push(i);
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=0;i<v_2[k].size();i++){
			int e=v_2[k][i];
			deg2[e]--;deg2[k]--;
			if(deg2[e]==1)q.push(e);
		}
	}
	for(int i=1;i<=tot_2;i++)if(deg2[i]>0)return -1;
	return 1;
}
int topo(){
	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(deg[i]<=1)
			q.push(i);
	while(!q.empty()){
		int k=q.front();q.pop();
		for(int i=0;i<v[k].size();i++){
			int e=v[k][i];
			deg[e]--;deg[k]--;
			if(deg[e]==1)q.push(e);
		}
	}
	for(int i=1;i<=tot;i++)if(deg[i]>0)return -1;
	return 1;
}
map<pair<int,int> ,int>c1,c2;
int main(){
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int pos_1=-1;
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int p1=-1;
		if(!mp[POINT(x,y,z)])pos_1=++tot,mp[POINT(x,y,z)]=pos_1;
		else pos_1=mp[POINT(x,y,z)];
		
		if(!mp_2[POINT2(x,y)])p1=++tot_2,mp_2[POINT2(x,y)]=p1;
		else p1=mp_2[POINT2(x,y)];
		
		
		scanf("%d%d%d",&x,&y,&z);
		int pos_2=-1,p2=-1;
	
		if(!mp[POINT(x,y,z)])pos_2=++tot,mp[POINT(x,y,z)]=pos_2;
		else pos_2=mp[POINT(x,y,z)];
		
		if(!mp_2[POINT2(x,y)])p2=++tot_2,mp_2[POINT2(x,y)]=p2;
		else p2=mp_2[POINT2(x,y)];
		
		//cout<<pos_1<<" "<<pos_2<<" "<<p1<<" "<<p2<<endl;
		if(pos_1!=pos_2&&!c1[{pos_1,pos_2}])v[pos_1].push_back(pos_2);
		if(pos_1!=pos_2&&!c1[{pos_1,pos_2}])v[pos_2].push_back(pos_1);
		
		if(p1!=p2&&!c2[{p1,p2}])v_2[p1].push_back(p2);
		if(p1!=p2&&!c2[{p1,p2}])v_2[p2].push_back(p1);
		
		if(pos_1!=pos_2&&!c1[{pos_1,pos_2}])deg[pos_1]++,deg[pos_2]++;
		if(p1!=p2&&!c2[{p1,p2}])deg2[p1]++,deg2[p2]++;
		c1[{pos_1,pos_2}]=c1[{pos_2,pos_1}]=c2[{p2,p1}]=c2[{p1,p2}]=1;
	}
	if(topo()==1)maxm=4;
	if(topo_2()==1)flg_h=1;
	if(maxm!=4)puts("True closed chains");
	else puts("No true closed chains");
	if(!flg_h)puts("Floor closed chains");
	else puts("No floor closed chains");
}



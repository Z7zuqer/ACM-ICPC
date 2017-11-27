#include<bits/stdc++.h>
using namespace std;
const int maxn=150050;
int n;
struct node{
	int t1,t2;
	friend bool operator<(node a,node b){
		return a.t2<b.t2;
	}
}res,req[maxn];
priority_queue<int>q;
int main(){
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&req[i].t1,&req[i].t2);
	}
	int now=0;
	sort(req,req+n);
	for(int i=0;i<n;i++){
		if(req[i].t1+now<=req[i].t2){
			q.push(req[i].t1);
			now+=req[i].t1;
		}
		else if(req[i].t1+now>req[i].t2&&req[i].t1<q.top()){
			now-=q.top();now+=req[i].t1;
			q.pop();
			q.push(req[i].t1);
		}
	}
	cout<<q.size()<<endl;
}

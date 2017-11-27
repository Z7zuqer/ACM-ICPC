#include<bits/stdc++.h>
using namespace std;
int n,p;
struct node{
	long long t;
	int k,d;
}r[100010];
struct nde{
	long long t;
	int id;
	bool operator <(nde a) const {  
		if(t==a.t)return id>a.id;
		return t > a.t; 
	}
    bool operator >(nde a) const {  
		if(t==a.t)return id>a.id;
		return t < a.t; 
	}
};
priority_queue<nde>q;
long long tmp[110],num=0;
int tid[110];
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=p;i++){
		scanf("%I64d%d%d",&r[i].t,&r[i].k,&r[i].d);
	}
	for(int i=1;i<=n;i++)
		q.push({0,i});
	//while(!q.empty())cout<<q.top().t<<endl,q.pop();
	for(int i=1;i<=p;i++){
		int req=r[i].k,sum=0;
		long long lst=0;
		num=0;
		while(req--){
			if(q.empty())break;
			nde u=q.top();q.pop();
			//cout<<u.t<<"==="<<u.id<<endl;
			tmp[num]=u.t;
			tid[num]=u.id;
			sum+=u.id;
			//q.pop();
			lst=max(lst,tmp[num]);
			num++;
			//req--;
		}
	//	cout<<lst<<"==="<<r[i].t<<endl;
		if(req>=0||lst>r[i].t){
			printf("-1\n");
			for(int j=0;j<num;j++)q.push({tmp[j],tid[j]});
			num=0;
			continue;
		}
		printf("%d\n",sum);
		for(int j=0;j<num;j++)q.push({r[i].t+r[i].d,tid[j]});
	}
}

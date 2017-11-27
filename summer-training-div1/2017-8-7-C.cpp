#include<bits/stdc++.h>
using namespace std;
#define LL long long
priority_queue<LL, vector<LL>, greater<LL> >q;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			q.push(x);
		}
		LL ans=0;
		while(!q.empty()){
			if(q.size()<=1)break;
			LL a=q.top();q.pop();
			LL b=q.top();q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		printf("%lld\n",ans);
	}
}



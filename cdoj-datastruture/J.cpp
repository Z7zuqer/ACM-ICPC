#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		q.push(x);
	}
	int ans=0;
	while(q.size()){
		if(q.size()==1)break;
		int a=q.top();q.pop();
		int b=q.top();q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	cout<<ans<<endl;
}



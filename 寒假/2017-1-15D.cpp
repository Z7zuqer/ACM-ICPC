#include<bits/stdc++.h>
using namespace std;
struct node1{
	int sig,a,b;//,sig;
	bool operator<(const node1 &A)const{
		if(a==A.a&&b==A.b)return sig<A.sig;
		if(a==A.a)return b>A.b;
		return a>A.a;
	}
}A[100010];
struct node2{
	int sig,a,b;
	bool operator<(const node2 &A)const{
		if(a==A.a&&b==A.b)return sig<A.sig;
		if(b==A.b)return a>A.a;
		return b>A.b;
	}
}; 
priority_queue<node2>q;
int main(){
	//freopen("C://Users//Duhao//Desktop//input.txt","r",stdin);
	int n,pos=1;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>A[i].a;
	for(int i=1;i<=n;i++)cin>>A[i].b,A[i].sig=i;
	sort(A+1,A+1+n);
	for(;pos+2<=n;pos+=2){
		q.push({A[pos+1].sig,A[pos+1].a,A[pos+1].b});
		q.push({A[pos+2].sig,A[pos+2].a,A[pos+2].b});
		q.pop();
	}
	if(pos+1<=n)q.push({A[pos+1].sig,A[pos+1].a,A[pos+1].b});
	while(!q.empty()){
		ans+=q.top().b;
		//cout<<q.top().b<<" "<<q.top().a<<endl;
		q.pop();
	}
	cout<<ans<<endl;
}



#include<bits/stdc++.h>
using namespace std;
int n,A[2000000];
queue<int>q1[2],q2[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=2;i<=n;i++){
		if(A[i]>A[1])q1[0].push(A[i]);
		if(A[i]<=A[1])q2[0].push(A[i]);
	} 
	int ans=0,now=0;
	while(1){
		if(q2[now].empty()){
			if(q1[now].empty())return 0*printf("%d",ans);
			else return 0*printf("%d",ans+1);
		}
		int time_q1=q1[now].size()/2;
		while(time_q1){
			q1[now^1].push(q1[now].front());q1[now].pop();q1[now].pop();time_q1--;
		}
		if(q1[now].size()){
			if(q2[now].size())q2[now].pop(),q1[now^1].push(q1[now].front());
			else return 0*printf("%d",ans+1);
		}
		int time_q2=q2[now].size()/2;
		while(time_q2){
			q2[now^1].push(q2[now].front());q2[now].pop();q2[now].pop();time_q2--;
		}
		if(q2[now].size())q2[now].pop();		
		ans++;now^=1;
	}
}

/*
8
5 1 2 3 4 6 7 8
*/

#include<bits/stdc++.h>
using namespace std;
int n,A[200100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	deque<int>q;
	for(int i=1;i<=n;i++){
		if(i&1)q.push_back(A[i]);
		else q.push_front(A[i]);
	}
	if(n&1)
		for(int i=q.size()-1;i>=0;i--)printf("%d ",q[i]);
	else 
		for(int i=0;i<q.size();i++)printf("%d ",q[i]);
}	



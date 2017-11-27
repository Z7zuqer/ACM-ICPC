#include<bits/stdc++.h>
using namespace std;
int A[100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		sort(A+1,A+n+1); 
		int cnt=0;
		while(A[1]!=A[n]){
			cnt++;
			A[1]=A[n]=A[n]-A[1];
			sort(A+1,A+n+1);
			if(cnt>1000000)break;
		}
		if(A[1]==A[n])cout<<A[1]<<endl;
		else cout<<"Nooooooo!"<<endl;
	} 
}



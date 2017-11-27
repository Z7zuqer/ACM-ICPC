#include<bits/stdc++.h>
using namespace std;
int A[200100];
int main(){
	int n,a,b,sum=0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		cin>>A[i];
		sum+=A[i];
	} 
	sort(A+1,A+1+n,greater<int>());
	int ans=0;
	for(int i=1;i<=n;i++){
		if(A[i]==2){
			if(b)ans+=2,b--;
		}
		else {
			if(b)ans++,b--,a++;
			else if(a)ans++,a--;
		}
	}
	cout<<sum-ans<<endl;
}



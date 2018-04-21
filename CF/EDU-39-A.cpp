#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int minv=0,sum=0;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		if(k>0)sum+=k;
		else minv+=k;
		//minv=min(minv,k);
	}
	//if(minv)cout<<sum-minv-minv<<endl;
	cout<<sum-minv<<endl;
}



#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	//int T=clock();
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++){//a
		for(int j=1;i*j<n;j++){
			for(int k=1;i*(j+k)<n;k++){
				if((n-i*j)%k==0)ans++;
			}
		}
	}
	printf("%d\n",ans);
	//int TT=clock();
	//cout<<TT-T<<endl;
}



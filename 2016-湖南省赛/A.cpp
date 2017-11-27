#include<bits/stdc++.h>
using namespace std;
int num[10]={2,2,2,2,2,3,3,7}; 
#define LL long long
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		LL ans=0;
		for(int i=1;i<=min(2016,n);i++)
			for(int j=1;j<=min(2016,m);j++){
				//cout<<i<<" "<<j<<endl;
				if((i*j)%2016==0){
					ans+=((n-i)/2016+1)*((m-j)/2016+1);
				}
			}
		cout<<ans<<endl;
	}
}



#include<bits/stdc++.h>
using namespace std;
int mp[101][101];
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		int maxm=0;
		//cout<<n<<k<<endl;
		for(int i=1;i<=n-k+1;i++)
			for(int j=1;j<=n-k+1;j++){
				int sum=0;
				for(int ii=1;ii<=k;ii++)
					for(int jj=1;jj<=k;jj++)
						sum+=mp[i+ii-1][j+jj-1];
				maxm=max(maxm,sum);
			}
		printf("%d\n",maxm);
	}
}



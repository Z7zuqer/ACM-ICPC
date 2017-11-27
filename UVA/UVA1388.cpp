#include<bits/stdc++.h>
using namespace std;
const double r=10000;
int vis[2010];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		memset(vis,0,sizeof(vis));
		double ans=0;
		for(int i=1;i<n;i++){
			double tmp=1e20;
			int wh=-1;
			for(int j=1;j<n+m;j++){
				//if(vis[j])continue;
				double k=fabs(r*(double)(i*n+i*m-j*n)/(double)(n*(n+m)));
				if(tmp>k){
					wh=j;
					tmp=k;
				}
			}
			vis[wh]=1;
			ans+=tmp;
		}
		printf("%.4lf\n",(double)ans);
		//cout<<(double)(n-1)*ans<<endl;
		//Lzuqer
	}
}

#include<bits/stdc++.h>
using namespace std;
int x[410];
double X[410],ans[410];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	double minm=1e10;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int num=j-i;X[i]=x[i];X[j]=x[j];
			double div=((double)x[j]-(double)x[i])/(double)num;
			for(int k=i-1;k>=1;k--)X[k]=(double)x[i]-(1.0*i-1.0*k)*div;
			for(int k=i+1;k<=n;k++)X[k]=(double)x[i]+(1.0*k-1.0*i)*div;
			//for(int k=1;k<=n;k++)cout<<X[k]<<" ";cout<<endl; 
			double tmp=0;
			for(int k=1;k<=n;k++)tmp+=fabs(X[k]-1.0*x[k]);
			if(tmp<minm){
				minm=tmp;
				for(int k=1;k<=n;k++)ans[k]=X[k];
			}
		}
	printf("%.8lf\n",minm);
	for(int i=1;i<=n;i++)printf("%.8lf ",ans[i]);
}



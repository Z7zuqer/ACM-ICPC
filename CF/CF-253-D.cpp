#include<bits/stdc++.h>
using namespace std;
double A[110];
int cmp(double a,double b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>A[i];
	sort(A+1,A+1+n,cmp);
	double maxv=A[1];
	for(int i=1;i<=n;i++){
		double res=0;
		for(int j=1;j<=i;j++){
			double x=A[j];
			for(int k=1;k<=i;k++)
				if(k!=j){
					x*=(1-A[k]);
				}
			res+=x;
		}
		maxv=max(maxv,res);
	}
	printf("%.12lf\n",maxv);
}



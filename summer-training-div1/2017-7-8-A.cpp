#include<bits/stdc++.h>
using namespace std;
int h,a,b,c,va,vb,vc;
double cal(double k){
	double r1=sin(k);
	double r2=(double)vb/(double)va*r1;
	double r3=(double)vc/(double)vb*r2;
	return (double)a/sqrt(1.0-r1*r1)*r1+(double)b/sqrt(1.0-r2*r2)*r2+(double)c/sqrt(1.0-r3*r3)*r3;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d",&h,&a,&b,&c,&va,&vb,&vc);
		double l=0,r=acos(-1.0)/2;
		while(r-l>1e-10){
			double mid=(l+r)/2;
			if(cal(mid)<h)l=mid;
			else r=mid;
		}
		double r1=sin((l+r)/2);
		double r2=(double)vb/(double)va*r1; 
		double r3=(double)vc/(double)vb*r2;
		double T_1=(double)a/(sqrt(1.0-r1*r1)*(double)va);
		double T_2=(double)b/(sqrt(1.0-r2*r2)*(double)vb);
		double T_3=(double)c/(sqrt(1.0-r3*r3)*(double)vc);
		//cout<<T_1<<" "<<T_2<<" "<<T_3<<endl;
		printf("%.4lf\n",T_1+T_2+T_3);
	}
	
}



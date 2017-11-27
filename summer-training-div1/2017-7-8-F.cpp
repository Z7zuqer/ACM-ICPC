#include<bits/stdc++.h>
using namespace std;
int T,n;
int X[1010],Y[1010];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
double dis(double x,double y,double xx,double yy){
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
double F(double x,double y){
	double r=0;
	for(int i=1;i<=n;i++)
		r+=dis(X[i],Y[i],x,y);
	return r;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]);
		double del_x=0,del_y=0;
		for(int i=1;i<=n;i++)del_x+=X[i],del_y+=Y[i];
		del_x/=2;del_y/=2;
		double delta=0.98,t=100,k=F(del_x,del_y);
		while(t>1e-8){
			int flg=0;
			double tmp_x=del_x,tmp_y=del_y,tmp_k=k;
			for(int i=0;i<4;i++){
				double tmp_x_x=del_x+t*dx[i];
				double tmp_y_y=del_y+t*dy[i];
				double tmp_k_k=F(tmp_x_x,tmp_y_y);
				if(tmp_k_k<tmp_k){
					tmp_k=tmp_k_k;
					tmp_x=tmp_x_x;
					tmp_y=tmp_y_y;
					flg=1; 
				}
				//if(flg)break; 
			}
			if(flg)del_x=tmp_x,del_y=tmp_y,k=tmp_k;
			else t*=delta;
		}
		printf("%.7lf %.7lf\n",del_x,del_y);
	}
}



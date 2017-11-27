#include<bits/stdc++.h>
using namespace std;
const double p=acos(-1);
int n,f;
int r[10010];
double are[10010];
int check(double ar){
	int k=0;
	for(int i=1;i<=n;i++)
		k+=(int)floor(are[i]/ar);
	return k>=f+1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		double rr=-1,l=0;//,s=0;
		cin>>n>>f;
		for(int i=1;i<=n;i++){
			cin>>r[i];
			are[i]=(double)r[i]*(double)r[i]*p;
			rr=max(rr,are[i]);
		}
		while(rr-l>1e-5){
			double mid=(rr+l)/2;
			if(check(mid))l=mid;
			else rr=mid;
		}
		printf("%.5lf\n",l);
	}
}

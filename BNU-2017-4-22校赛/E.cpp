#include<bits/stdc++.h>
using namespace std;
const double p=acos(-1);
int main(){
	int T;
	cin>>T;
	while(T--){
		double a,b,c;
		cin>>a>>b>>c;
		double aa=a,bb=b,cc=c;
		a=max(aa,max(bb,cc));
		c=min(aa,min(bb,cc));
		b=aa+bb+cc-a-c;
		printf("%.7lf\n",p*(b*b+(a-b)*(a-b)));
	} 
}



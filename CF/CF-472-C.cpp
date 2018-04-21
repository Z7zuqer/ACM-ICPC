#include<bits/stdc++.h>
using namespace std;
int num[100100];
int main(){
	int n,u;
	scanf("%d%d",&n,&u);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	int pre=1;
	double ans=-1;
	for(int i=3;i<=n;i++){
		while(num[i]-num[pre]>u&&i-pre>2)pre++;
		if(num[i]-num[pre]>u)continue;
		ans=max(ans,1.0*(num[i]-num[pre+1])/(num[i]-num[pre]));
	}
	if(ans<0)return 0*printf("-1\n");
	printf("%.10f\n",ans);
}



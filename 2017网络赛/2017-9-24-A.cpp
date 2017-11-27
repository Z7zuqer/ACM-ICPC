#include<bits/stdc++.h>
using namespace std;
const double eps=1e-15;
double A[6][6];
char s[1000000];
int num[1000000],cnt;
void work(){
	gets(s);stringstream ss(s);cnt=0;
	while(ss>>num[++cnt]);cnt--;
	if(cnt==1){
		printf("1\n");
		return ;
	}
	int pre=num[1];double ans=1.0;
	for(int i=2;i<=cnt;i++){
		ans=ans*A[pre][num[i]];
		//cout<<ans<<" "<<A[pre][num[i]]<<" "<<pre<<endl;
		pre=num[i];
	}
	printf("%.8f\n",ans);
}
int main(){
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			cin>>A[i][j];
	//double ans1=1;
	getchar();
	work();work();
	int x;
	scanf("%d",&x);
	double ans1=1,p=1;
	for(int i=2;;i++){
		p*=A[x][x];
		double res=(double)p;
		if(res<=eps)break;
		ans1+=res;
	}
	printf("%.8f\n",ans1);
	
	scanf("%d",&x);
	//cout<<x<<endl;
	double ans2=1;p=1;
	for(int i=2;;i++){
		p*=A[x][x];
		double res=(double)p;
		if(res<=eps)break;
		ans2+=res;
	}
	printf("%.8f\n",ans2);
}



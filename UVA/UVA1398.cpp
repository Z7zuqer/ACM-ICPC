#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
struct node{
	double x;
	int type;
	bool operator<(const node& a)const{
		return x<a.x||((fabs(x-a.x)<1e-6)&&type>a.type); 
	}
}A[maxn<<1];
void update(int x,int a,int w,double& L,double& R){
	if(a==0){
		if(x>=w||x<=0)R=L-1;
	}
	else if(a>0){
		L=max(L,(double)(-1*x)/(double)a);
		R=min(R,(double)(w-x)/(double)a);
	}
	else {
		R=min(R,(double)(-1*x)/(double)a);
		L=max(L,(double)(w-x)/(double)a);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,w,h,num=0;
		cin>>w>>h>>n;
		for(int i=1;i<=n;i++){
			int x,y,a,b;
			cin>>x>>y>>a>>b;
			double L=0,R=1e9;
			update(x,a,w,L,R);
			update(y,b,h,L,R);
			if(R>L){
				A[num++]={L,0};
				A[num++]={R,1};
			}
		}
		sort(A,A+num);
		int ans=0,cnt=0;
		for(int i=0;i<num;i++){
			if(A[i].type==1)cnt--;
			else {
				ans=max(ans,++cnt);
			}
		}
		cout<<ans<<endl;
	}
}



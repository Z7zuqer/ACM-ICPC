#include<bits/stdc++.h>
using namespace std;
struct node{
	double l,r;
}A[10010];
double cal(double r,double w){
	return sqrt(r*r-w*w/4);
}
bool cmp(node m,node n){
	//if(fabs(m.l-n.l)<1e-6)return m.r<n.r;
	return m.l<n.l;
}
int main(){
	int n;
	double l,w;
	while(scanf("%d%lf%lf",&n,&l,&w)!=EOF){
		//if(l<w)swap(l,w);
		double wh,r;
		int flg=1,ans=0,cnt=1;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&wh,&r);
			double k=cal(r,w);
			if(r*2<=w)continue;
			A[cnt].l=wh-k<0?0:wh-k;
			A[cnt++].r=wh+k>l?l:wh+k; 
		}	
		sort(A+1,A+1+cnt,cmp);
		//cout<<"dsa"<<endl;
		double L=0,R=0;
		for(int i=1;i<=cnt;){
			if(A[i].l>R){
				flg=0;
				break;
			}
			int j;
			double tmp=A[i].r;
			for(j=i;j<=cnt;j++){
				if(A[j].l<=R)tmp=max(tmp,A[j].r);
				else {
					i=j;
					break;
				}
			}
			i=j;
			R=tmp;
			ans++;
		}
		if(!flg)printf("-1\n");
		else printf("%d\n",ans);
	}
}



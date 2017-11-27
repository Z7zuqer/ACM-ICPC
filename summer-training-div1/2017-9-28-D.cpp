#include<bits/stdc++.h>
using namespace std;
int A[110];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int maxi=-1,mini=-1,maxk,mink;
	double ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			double maxv=1.0*A[i]/j;
			double minv=9e18;
			int flg=0,minii,minkk;
			for(int x=1;x<=n&&!flg;x++){
				int y=1,ffg=0;
				if(x==i)continue;
				for(;y<=k;y++)
					if(1.0*A[x]/y<=maxv){
						ffg=1;
						break;
					}	
				if(!ffg)flg=1;			
				if(minv>1.0*A[x]/y){
					minv=1.0*A[x]/y;
					minii=x;
					minkk=y;
				}
				//minv=min(minv,1.0*A[x]/y);
			}
			if(!flg){
				if(maxv/minv<ans){
					ans=maxv/minv;
					maxi=i;
					mini=minii;
					maxk=j;
					mink=minkk;
				}
			}
		}
	}
	//cout<<maxi<<" "<<mini<<endl;
	for(int i=1;i<=n;i++){
		if(i==maxi)printf("%d ",maxk);
		else if(i==mini)printf("%d ",mink);
		else {
			for(int j=1;j<=k;j++){
				if(1.0*A[i]/j>=1.0*A[mini]/mink&&1.0*A[i]/j<=1.0*A[maxi]/maxk){
					printf("%d ",j);
					break;
				}
			}
		}
	}
}



#include<bits/stdc++.h>
using namespace std;
#define LL long long
const double p=acos(-1);
LL A[1010][6];
vector<int>v;
int main(){
	int n;
	scanf("%d",&n);
	if(n>243)return 0*printf("0");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			scanf("%I64d",&A[i][j]); 
	for(int i=1;i<=n;i++){//a
		int flg=0;
		for(int j=1;j<=n&&!flg;j++){//b
			if(i==j)continue;
			for(int k=j+1;k<=n&&!flg;k++){//c
				LL x1=A[j][1]-A[i][1];
				LL x2=A[j][2]-A[i][2];
				LL x3=A[j][3]-A[i][3];
				LL x4=A[j][4]-A[i][4];
				LL x5=A[j][5]-A[i][5];
				LL y1=A[k][1]-A[i][1];
				LL y2=A[k][2]-A[i][2];
				LL y3=A[k][3]-A[i][3];
				LL y4=A[k][4]-A[i][4];
				LL y5=A[k][5]-A[i][5];
				if(p/2>acos((x1*y1+x2*y2+x3*y3+x4*y4+x5*y5)/(sqrt(x1*x1+x2*x2+x3*x3+x4*x4+x5*x5)*sqrt(y1*y1+y2*y2+y3*y3+y4*y4+y5*y5)))){
					flg=1;
					break;
				}
			}
		}
		if(!flg)v.push_back(i);
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)printf("%d\n",v[i]);
}



#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int flg[maxn],stav[maxn],num[maxn],inque[maxn],numv[maxn];
struct {
	char s[10];
	int k;
}A[maxn];
queue<int>q[2];
void print(int k){
	int po=1e5;
	for(int i=0;i<6;i++){
		printf("%d",(k/po)%10);
		po/=10;
	}
}
int main(){
	freopen("C://Users//Duhao//Desktop//a.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(stav,0,sizeof stav);
		memset(numv,0,sizeof numv);
		memset(flg,0,sizeof flg);
		memset(num,0,sizeof num);
		memset(inque,0,sizeof inque);
		for(int i=0;i<2;i++)while(q[i].size())q[i].pop();
		for(int i=1;i<=n;i++){
			scanf("%s%d",A[i].s,&A[i].k);
			if(A[i].s[0]=='u')flg[A[i].k]=1;
			if(A[i].s[1]=='o')flg[A[i].k]=0;
			if(A[i].s[0]=='d'&&A[i].s[1]=='e')stav[A[i].k]=i,flg[A[i].k]=0,num[A[i].k]=0;
			if(A[i].s[0]=='v')numv[A[i].k]=i;
		}
		for(int i=n;i>=1;i--)
			if(i>stav[A[i].k]){
				if(A[i].s[0]=='r'){
					if(!inque[A[i].k])q[flg[A[i].k]].push(A[i].k),inque[A[i].k]=1;
					if(i>numv[A[i].k])num[A[i].k]++;
				}
			}
		for(int i=1;i>=0;i--){
			while(q[i].size()){
				print(q[i].front());
				printf(" %d\n",num[q[i].front()]);
				q[i].pop();
			}
		}
		printf("\n");
	}
}



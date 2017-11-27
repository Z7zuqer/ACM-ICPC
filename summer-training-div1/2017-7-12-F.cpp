#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int isnot_pri[maxn]={1,1},pri_num,pri[maxn];
int A[maxn],B[maxn],cnt_A[maxn],cnt_B[maxn],maxm;
void get_pri(){
	for(int i=2;i<maxn;i++){
		if(!isnot_pri[i])pri[pri_num++]=i;
		for(int j=0;j<pri_num&&i*pri[j]<maxn;j++){
			isnot_pri[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}
int cnt[maxn][1300];
vector<pair<int,int> >v;
int main(){
	//freopen("factorial.in","r",stdin);
	//freopen("factorial.out","w",stdout);
	int n,m;
	get_pri();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)scanf("%d",&B[i]);
	for(int i=2;i<maxn-2;i++){
		int k=i;
		for(int j=0;j<pri_num;j++){
			cnt[i][j]=cnt[i-1][j];
			while((k%pri[j])==0){
				cnt[i][j]++;
				k/=pri[j];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<pri_num;j++)
			cnt_A[j]+=cnt[A[i]][j];
	for(int i=1;i<=m;i++)
		for(int j=0;j<pri_num;j++)
			cnt_B[j]+=cnt[B[i]][j];
	//for(int i=0;i<pri_num;i++)cout<<cnt_A[i]<<" "<<cnt_B[i]<<endl;while(1);
	for(int i=0;i<pri_num;i++)
		if(cnt_A[i]<cnt_B[i])
			return 0*printf("-1\n");
	for(int i=0;i<pri_num;i++)cnt_A[i]-=cnt_B[i];//cout<<cnt_A[0]<<endl;
	if(cnt_A[0]<1)return 0*printf("0\n");
	//cout<<"dsa"<<endl;
	/*
	4 2 
	9 2 2 2 
	3 4 
	*/ 
	for(int i=maxn-3;i>=2;i--){
		int flg=1,r=1e9;
		for(int j=0;j<pri_num;j++){
			if(cnt_A[j]<cnt[i][j]){
				flg=0;
				break;
			}		
			if(cnt[i][j])r=min(r,cnt_A[j]/cnt[i][j]);
		}
		if(flg==0)continue;
		for(int j=0;j<pri_num;j++)
			cnt_A[j]-=r*cnt[i][j];
		v.push_back({i,r});
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)
		printf("%d %d\n",v[i].first,v[i].second);
}



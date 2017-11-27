#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n;
int isnotpri[maxn]={1,1},pri[maxn],num_pri=0;
void pre(){
	for(int i=2;i<maxn;i++){
		if(!isnotpri[i])pri[num_pri++]=i;
		for(int j=0;j<num_pri&&i*pri[j]<maxn;j++){
			isnotpri[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}
int num[maxn],ord[100]={1,-1,-1,-1,1,-1,-1,1,1};
int main(){
	int n;
	//int t=clock();
	//n=1000000;
	scanf("%d",&n); 
	pre();
	num[1]=1;
	int sum=1,now=0,cnt1=0,cnt2=0;
	for(int i=2;i<=n;i++){
		int tmp=-2;
		if(!isnotpri[i]){
			if((i/3)%2==1)num[i]=1;
			else num[i]=-1;
			continue;
		}
		for(int j=0;j<num_pri;j++){
			if(i%pri[j]==0){
				tmp=num[i/pri[j]]*num[pri[j]];
				break;
			}
		}
		num[i]=tmp;
		//sum+=num[i];
	}
	//cout<<clock()-t<<endl;
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=num[i];
		if(abs(sum)>20)cout<<sum<<endl;
	}
	//for(int i=1;i<=n;i++)printf("%d ",num[i]);
	//printf("\n");
}



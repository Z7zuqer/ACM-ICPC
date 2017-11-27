#include<bits/stdc++.h>
using namespace std;
int ans,num[377],tmp[377],res[377];
void dfs(int k,int sum,int step){
	if(sum==0){
		if(ans>step){
			ans=step;
			for(int i=1;i<=357;i++)res[i]=tmp[i];
			return ;
		}
	}
	if(ans<=step||step+1>=ans||step+sum/num[k]>=ans)return ;
	for(int i=k;i>=1;i--){
		if(num[i]<=sum){
			tmp[i]++;
			dfs(i,sum-num[i],step+1);
			tmp[i]--;
		}
	}
}
int main(){
	//cout<<358*358*358<<endl;
	for(int i=1;i<=358;i++)num[i]=i*i*i;
	int n,end=-1;
	scanf("%d",&n);
	ans=n;res[1]=n;
	dfs(358,n,0);
	printf("%d\n",ans);
	for(int i=1;i<=357;i++)
		for(int j=0;j<res[i];j++)
			printf("%d ",i);
	printf("\n");
}



#include<bits/stdc++.h>
using namespace std;
int pri[100010],num=0;
int notp[100010]={1,1};
void pre(){
	for(int i=2;i<=100010;i++){
		if(!notp[i])pri[num++]=i;
		for(int j=0;j<num&&i*pri[j]<100010;j++){
			notp[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}
int a[100010];
int cnt[100010];
int main(){
	pre();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int maxm=0;
	for(int i=1;i<=n;i++){
		int k=(int)ceil((double)sqrt(a[i]));
		//cnt[a[i]]++;
		for(int j=0;j<num&&a[i];j++){
			if(a[i]%pri[j]==0)cnt[j]++;
			if(pri[j]>k)break;
		}
	}
	for(int i=0;i<num;i++)maxm=max(maxm,cnt[i]);
	printf("%d\n",maxm); 
}

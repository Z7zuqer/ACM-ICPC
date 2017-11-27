#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL A[100100],sum[100100];
vector<pair<LL,vector<LL> > >v; 
vector<LL>nowo;
vector<LL>nowe;
int main(){
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(A[i]&1)cnt1++,nowo.push_back(A[i]);
		else cnt0++,nowe.push_back(A[i]);
	}
	int now=1;
	for(int i=0;i<nowo.size();i++)A[now++]=nowo[i];
	for(int i=0;i<nowe.size();i++)A[now++]=nowe[i];
	int req0=p,req1=k-p;
	if(cnt1<req1||(cnt1-req1)%2!=0)return 0*printf("NO\n");
	//if()
	LL cnt=0,sum=0,r=0,last=-1;
	vector<LL>tmp;
	for(int i=1;i<=n;i++){
		sum+=A[i];cnt++;tmp.push_back(A[i]);
		if((sum&1)&&req1>0){
			//cout<<sum<<endl;
			v.push_back({cnt,tmp});
			sum=0;
			cnt=0;
			tmp.clear();
			req1--;
			last=i+1;
		}
		else if(sum%2==0&&req0>0){
			v.push_back({cnt,tmp});
			sum=0;
			cnt=0;
			tmp.clear();
			req0--;
			last=i+1;
		}
	}
	for(int i=last;i<=n;i++)
		v[v.size()-1].first++,v[v.size()-1].second.push_back(A[i]);
	if(v.size()!=k)return 0*printf("NO\n");
	puts("YES");
	for(int i=v.size()-1;i>=0;i--){
		printf("%I64d ",v[i].first);
		for(int j=0;j<v[i].second.size();j++)
			printf("%I64d ",v[i].second[j]);
		puts("");
	}
}



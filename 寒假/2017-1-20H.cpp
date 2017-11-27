#include<bits/stdc++.h>
using namespace std;
int n,s;
int A[100010],lst[100010],sum[100010];
int main(){
	int T;
	cin>>T; 
	while(T--){
		scanf("%d%d",&s,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		memset(lst,-1,sizeof(lst));
		memset(sum,0,sizeof(sum));
		int ans=0;
		for(int i=0;i<n;i++){
			if(lst[A[i]]!=-1){
				if(i-lst[A[i]]>=s){
					ans++;
					sum[0]++;
					sum[s]--;
				}
				else{
					if(lst[A[i]]/s==i/s){
						sum[lst[A[i]]%s]++;
						sum[i%s]--;
						ans++;
					}
					else {
						sum[lst[A[i]]%s]++;
						sum[s+1]--;
						sum[0]++;
						sum[i%s]--;
						ans++;
					}
				}
			}
			lst[A[i]]=i;
		}
		int num=0;
		for(int i=1;i<=s;i++)sum[i]+=sum[i-1];
		for(int i=0;i<s;i++)
			if(sum[i]==ans)num++;
		cout<<num<<endl;
	}
}



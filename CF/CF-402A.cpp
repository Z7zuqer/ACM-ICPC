#include<bits/stdc++.h>
using namespace std;
int A[110],B[110];
int r[110];
int cnt1[7],cnt2[7],req[7];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),cnt1[A[i]]++;
	for(int i=1;i<=n;i++)scanf("%d",&B[i]),cnt2[B[i]]++;
	int flg=0,ans=0;
	for(int i=1;i<=5;i++){
		if((cnt1[i]+cnt2[i])%2){
			flg=1;
			break;
		}
		ans+=abs(cnt1[i]-cnt2[i])/2;
	}
	if(flg)cout<<"-1"<<endl;
	else cout<<ans/2<<endl; 
}



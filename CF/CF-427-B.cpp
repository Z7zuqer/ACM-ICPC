#include<bits/stdc++.h>
using namespace std;
char s[100100];
long long k;
int A[100100]; 
int main(){
	long long tmp=0;
	cin>>k;
	scanf("%s",s);
	int sum=0,cnt=0;
	for(int i=0;s[i];i++){
		sum+=s[i]-'0';
		A[i]=s[i]-'0';cnt++;
	}
	sort(A,A+cnt);
	if(sum>=k)return 0*printf("0\n");
	sum=k-sum;
	int ans=0;
	for(int i=0;i<cnt;i++){
		if(sum<9-A[i]){
			cout<<ans+1<<endl;
			return 0;
		}
		sum-=(9-A[i]);
		if(sum==0){
			cout<<ans+1<<endl;
			return 0; 
		}
		ans++;
	}
	cout<<max(0LL,k-sum)<<endl;
}



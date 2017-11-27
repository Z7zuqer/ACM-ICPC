#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int A[maxn]; 
int main(){
	int n,l;
	int t;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		sort(A+1,A+1+n);
		int wh=1,ans=0;
		for(int i=n;i>=1;i--){
			if(i==wh){
				ans++;
				break;
			}
			if(i<wh)break;
			if(A[i]+A[wh]<=l){
				ans++;wh++;
			}
			else ans++;
		}
	
		cout<<ans<<endl;	if(t!=0)cout<<endl;
	}
}



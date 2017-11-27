#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int fa[maxn],A[maxn],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&fa[i]);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(fa[i]!=A[i]){
			int t=i;
			while(fa[t]!=0){
				ans++;
				int s=fa[t];
				fa[t]=0;
				t=s;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(fa[i]!=A[i]){
			int t=A[i];
			while(fa[t]!=0){
				ans++;
				int s=fa[t];
				fa[t]=0;
				t=s;
			}
		}
	}
	for(int i=1;i<=n;i++)if(fa[i]!=A[i])ans++;
	cout<<ans<<endl;
}



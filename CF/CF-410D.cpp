#include<bits/stdc++.h>
using namespace std;
int A[100100],B[100100],vis[100100];
int idx[100100];
int main(){
	srand(time(0));
	int n;
	scanf("%d",&n);
	long long s1=0,s2=0;
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),idx[i]=i,s1+=1LL*A[i];
	for(int i=1;i<=n;i++)scanf("%d",&B[i]),s2+=1LL*B[i];
	int now=0,lim=n/2+1,k=1;
	while(1){
		random_shuffle(idx+1,idx+1+n);
		long long ans1=0,ans2=0;
		for(int i=1;i<=lim;i++)ans1+=A[idx[i]],ans2+=B[idx[i]];
		if(ans1*2>s1&&ans2*2>s2){
			cout<<lim<<endl;
			for(int i=1;i<=lim;i++)printf("%d ",idx[i]);cout<<endl;
			return 0;
		}
	}
}

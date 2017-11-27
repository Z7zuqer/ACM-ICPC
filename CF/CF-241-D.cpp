#include<bits/stdc++.h>
using namespace std;
int A[200200];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=1,j,k;i<=n;){
		ans++;
		j=i;while(A[j]==-1)j++;
		k=j+1;while(A[k]==-1)k++;
		if(k>n)break;
		if((A[k]-A[j])%(k-j)!=0){
			i=k;
			continue;
		}
		int div=(A[k]-A[j])/(k-j);
		if(1LL*A[k]-1LL*div*(k-i)<=0){
			i=k;
			continue;
		}
		for(i=k+1;i<=n&&A[k]+1LL*div*(i-k)>0&&(1LL*A[i]==1LL*A[k]+1LL*div*(i-k)||A[i]==-1);i++);
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int A[100100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	int L=1,R=n;
	while(L<n&&A[L]<A[L+1])L++;
	while(R>1&&A[R]<A[R-1])R--;
	cout<<L<<" "<<R<<endl;
	for(int i=L+1;i<=R;i++)if(A[i]!=A[L])return 0*printf("NO\n");
	puts("YES");
}

#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL are[1000100];
int main(){
	int R;
	scanf("%d",&R);
	int n;
	scanf("%d",&n);
	LL sum=0;
	for(int i=1;i<=n;i++){
		int L,T,W,H;
		scanf("%d%d%d%d",&L,&T,&W,&H);
		for(int i=0;i<W;i++)are[i+L]+=H,sum+=H;
	} 
	for(int i=1;i<=R;i++)are[i]+=are[i-1];
	int l=0,r=R;
	while(l<r){
		int mid=(l+r)>>1;
		if(are[mid]*2LL>=sum)r=mid;
		else l=mid+1;
	}
	LL minv=abs(sum-2LL*are[r]);
	for(int i=r;i<R;i++)
		if(minv==abs(sum-2LL*are[i]))r=i;
		else if(minv>abs(sum-2LL*are[i]))r=i;
		else break;
	printf("%d\n",r+1);
}



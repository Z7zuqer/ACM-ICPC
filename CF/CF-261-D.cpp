#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,A[1000100],B[1000100],cnt[1000100],tr[1000100],pre[1000100];
int find(int x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(B[mid]>=x)r=mid;
		else l=mid+1;
	}
	return r;
}
void add(int x,int v){
	while(x<1000100){
		tr[x]+=v;
		x+=x&-x;
	}
}
LL getans(int x){
	LL ans=0;
	while(x){
		ans+=tr[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&A[i]),B[i]=A[i];
	sort(B+1,B+1+n);
	for(int i=1;i<=n;i++)A[i]=find(A[i]);
	//for(int i=1;i<=n;i++)printf("%d ",A[i]);cout<<endl;
	for(int i=n;i>=2;i--){
		cnt[A[i]]++;
		add(cnt[A[i]],1);
	}
	pre[A[1]]++;
	LL ans=0;
	for(int i=2;i<=n;i++){
		pre[A[i]]++;
		if(cnt[A[i]]>0)add(cnt[A[i]],-1);
		//if(cnt[A[i]]-1>0)add(cnt[A[i]]-1,1);
		cnt[A[i]]--;
		ans+=getans(pre[A[i]]-1);
	}
	printf("%I64d\n",ans);
}



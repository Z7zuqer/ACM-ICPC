#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int seq[maxn],res[maxn],n;
int work(){
	int ans=0;
	int l1=1,r1=n;
	int l2=1,r2=n;
	while(l1<=r1&&l2<=r2){
		if(seq[l1]>res[l2]){
			ans+=2;
			l1++;l2++;//cout<<seq[l1]<<" "<<res[l2]<<endl;
		}
		else if(seq[r1]>res[r2]){
			ans+=2;
			r1--;r2--;//cout<<ans<<endl;
		}
		else {
			ans+=(seq[l1]==res[r2]);
			l1++;r2--;
		}
		//cout<<ans<<endl;
	}
	return ans;
	//cout<<endl;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&seq[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&res[i]);
	}
	sort(res+1,res+1+n);//cout<<seq[1]<<endl; 
	sort(seq+1,seq+1+n);
	int ans=work();for(int i=1;i<=n;i++)swap(seq[i],res[i]);
	cout<<ans<<" "<<2*n-work()<<endl;
	
}

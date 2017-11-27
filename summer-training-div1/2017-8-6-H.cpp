#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL cal(int len1,int len0,LL end){
	int len_all=len0+len1;
	if(len_all>=64)return 0;
	LL ans=0,x=(1LL<<len1)-1;
	LL k=x<<len0;
	int now=1;
	while(k<=end){
		ans++;
		//cout<<now<<" "<<ans<<" "<<len_all<<endl;
		if(now){
			if(len_all+len1>=64)break;
			k<<=len1;k|=x;
			len_all+=len1;
		}
		else {
			if(len_all+len0>=64)break;
			k<<=len0;
			len_all+=len0;
		}
		now^=1;
	}
	return ans;
}
LL work(LL r){
	LL ans=0;
	for(int i=1;i<=63;i++){
		if((1LL<<i)-1LL<=r)ans++;
		for(int j=1;j<=63;j++){
			ans+=cal(i,j,r);
		}
	}	
	return ans;	
}
int main(){
	LL l,r;
	cin>>l>>r;
	cout<<work(r)-work(l-1)<<endl;
}



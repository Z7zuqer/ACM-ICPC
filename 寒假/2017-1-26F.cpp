#include<bits/stdc++.h>
using namespace std;
int work(int W,int H,int w,int h){
	if(w>W||h>H)return 1e9;
	int ans=0;
	while(W>=w*2){
		ans++;
		W=(W+1)/2;
	}
	if(W!=w)ans++;
	while(H>=2*h){
		ans++;
		H=(H+1)/2;
	}
	if(H!=h)ans++;
	return ans;
}
int main(){
	int w,h,W,H;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	if(w>h)swap(w,h);
	if(W>H)swap(W,H);
	if(H<h||w>W)return 0*printf("-1\n");
	int ans=1e9;
	ans=min(ans,work(W,H,w,h));
	ans=min(ans,work(W,H,h,w));
	cout<<ans<<endl;
}


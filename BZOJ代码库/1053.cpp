#include<bits/stdc++.h>
using namespace std;
int pri[15]={1,2,3,5,7,11,13,17,19,23,29,31};
long long ans_num=1,ans_cnt=1,n;
void dfs(int wh,long long now,int cnt,int last){
	if(wh==12){
		if(ans_cnt<cnt){
			ans_num=now;
			ans_cnt=cnt;
		}
		else if(ans_cnt==cnt&&ans_num>now){
			ans_num=now;
			ans_cnt=cnt;
		}
		return ;
	}
	int t=1;
	for(int i=0;i<=last;i++){
		if(now*t>n)break;
		dfs(wh+1,now*t,cnt*(i+1),i);
		t*=pri[wh];
	}
}
int main(){
	cin>>n;
	dfs(1,1,1,20);
	cout<<ans_num<<endl;
} 

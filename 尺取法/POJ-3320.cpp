#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<int,int>mp;
map<int,int>now;
int A[1000100];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		mp.clear();now.clear();
		int cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&A[i]);
			if(!mp[A[i]]){
				mp[A[i]]=1;
				cnt++;
			}
		}
		int l=1,r=1;
		int nowcnt=0,ans=n;
		while(l<=r&&r<=n){
			now[A[r]]++;
			if(now[A[r]]==1)nowcnt++;
			while(now[A[l]]>1&&l<r){
				now[A[l]]--;
				l++;
			}
			if(nowcnt==cnt){
				//cout<<l<<" "<<r<<endl;
				ans=min(ans,r-l+1);
			}
			r++;
		}
		printf("%d\n",ans);
	}
}
/*
5
1 8 8 8 1
*/



#include<bits/stdc++.h>
using namespace std;
int m,cnt[500000+1234],ans=0; 
int main(){
	while(scanf("%d",&m)==1){
		char s[2];
		if(!m){
			cout<<-1<<endl;
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		int k,r=0,min_r=1234567;ans=1234567;
		for(int i=1;i<=m;i++){
			scanf("%s%d",s,&k);
			if(s[0]=='O'){
				if(r)r--;
				else if(!cnt[k])ans=min(ans,i);
				else cnt[k]--;
			}
			if(s[0]=='I'){
				if(r)r--;
                else if(cnt[k])ans=min(ans,i);
				else cnt[k]++;
			}
			if(s[0]=='?')r++,min_r=min(min_r,i);
		}
		cout<<(ans==1234567?-1:min(ans,min_r))<<endl;
	}
}



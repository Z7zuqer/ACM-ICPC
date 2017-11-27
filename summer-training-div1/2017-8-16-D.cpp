#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
map<int,string>mpp;
vector<string>v;
void dfs(int now,int rem,string s){
	if(rem==0){
		int siz=s.size();
		while(siz<6)s+='0',siz++;
		v.push_back(s); 
		return ;
	}
	if(now==6){
		s+=('0'+rem);
		v.push_back(s);
		return ;
	}
	for(int i=0;i<=rem;i++){
		dfs(now+1,rem-i,s+(char)('0'+i));
	}
}
void pre(){
	dfs(1,15,"");
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		//cout<<v[i]<<" "<<i+1<<endl;
		//getchar();
		mp[v[i]]=i;
		mpp[i]=v[i];
	}
}
int main(){
	char s[2];
	pre();
	int cas=1;
	while(scanf("%s",s)!=EOF){
		if(s[0]=='e')break;
		if(s[0]=='m'){
			string s="";
			for(int i=0;i<6;i++){
				int x;
				scanf("%d",&x);
				s+=(char)('0'+x);
			}
			printf("Case %d: %d\n",cas++,mp[s]);
		}
		if(s[0]=='u'){
			int k;
			scanf("%d",&k);
			printf("Case %d: ",cas++);
			string s=mpp[k];
			for(int i=0;i<6;i++)printf("%d ",(int)(s[i]-'0'));
			printf("\n");
		}
	}
}



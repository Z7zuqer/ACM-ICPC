#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char s[maxn][210];
int ord[maxn],deg[maxn],vis[30];
char ans[31],ans2[31];
struct {
	int e,next;
}ed[maxn*maxn]; 
int head[maxn],num;
void add(int s,int e){
	ed[num].e=e;ed[num].next=head[s];head[s]=num++;
}
int mp[31][31];
int work(){
	int r=0,cnt=0;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<26;i++){
		if(!deg[i]&&vis[i])q.push(i);
		if(vis[i])cnt++;
	}
	while(!q.empty()){
		int k=q.top();q.pop();ans[r++]=k+'a';
		for(int i=head[k];i!=-1;i=ed[i].next){
			if(--deg[ed[i].e]==0)q.push(ed[i].e);
		}
	}
	ans[r]='\0';
	if(r==cnt)return 0;
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int flg=0,k=0;
			for(;s[i][k]&&s[j][k];k++)
				if(s[i][k]!=s[j][k]){
					if(mp[s[i][k]-'a'][s[j][k]-'a'])break;
					//cout<<s[i][k]<<" "<<s[j][k]<<endl;
					flg=1;deg[s[j][k]-'a']++;mp[s[i][k]-'a'][s[j][k]-'a']=1;
					add(s[i][k]-'a',s[j][k]-'a');vis[s[i][k]-'a']=vis[s[j][k]-'a']=1;
					break;
				}
			if(!flg&&(s[i][k]&&!s[j][k]))return 0*printf("-1\n");
		}
	}
	if(work())return 0*printf("-1\n");int r=0;
	for(int i=0;i<26;i++)if(!vis[i])ans2[r++]='a'+i;ans2[r]='\0';
	int r1=0,r2=0;
	while(ans[r1]&&ans2[r2]){
		if(ans[r1]<ans2[r2])printf("%c",ans[r1++]);
		else printf("%c",ans2[r2++]);
	}
	while(ans[r1])printf("%c",ans[r1++]);
	while(ans2[r2])printf("%c",ans2[r2++]);cout<<endl;
}



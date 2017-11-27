#include<bits/stdc++.h>
using namespace std;
char  mp[110][110];
struct node{
	char s[110];
}r[110],c[110];
int cmp(node m,node n){
	return strcmp(n.s,m.s);
}
int get_max(string s){
	int len=s.size();
	int i=0,j=1,k=0;
	while(i<len&&j<len&&k<len){
		int t=s[(i+k)%len]-s[(j+k)%len];
		if(t==0)k++;
		else {
			if(t>0)j+=k+1;
			else i+=k+1;
			if(i==j)j++;
			k=0;
		}
	}
	return min(i,j);
}
int main(){
	int n,m;
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			r[i].s[j-1]=mp[i][j];
		r[i].s[m]='\0';
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++)
			c[j].s[i-1]=mp[i][j];
		c[j].s[n]='\0';
	}
	sort(r+1,r+1+n,cmp);
	sort(c+1,c+1+m,cmp);
	string ans1="",ans2="";
	for(int i=1;i<=n;i++)
		ans1+=(string)r[i].s;
	for(int i=1;i<=m;i++)
		ans2+=(string)c[i].s;
	string LAST1="",LAST2="";
	int sta1=get_max(ans1),siz1=ans1.size();
	int sta2=get_max(ans2),siz2=ans2.size();
	for(int i=0;i<siz1;i++)
		LAST1+=ans1[(i+sta1)%siz1];
	for(int i=0;i<siz2;i++)
		LAST2+=ans2[(i+sta2)%siz2];
	if(LAST1>LAST2){
		int i=0,siz=LAST1.size();
		for(;i<siz;i++)if(LAST1[i]!='0')break;
		if(i==siz)return 0*printf("0\n");
		for(;i<siz;i++)printf("%c",LAST1[i]);
	}
	else {
		int i=0,siz=LAST2.size();
		for(;i<siz;i++)if(LAST2[i]!='0')break;
		if(i==siz)return 0*printf("0\n");
		for(;i<siz;i++)printf("%c",LAST2[i]);		
	}
}



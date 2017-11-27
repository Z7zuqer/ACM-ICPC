#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
char s[120][120];
char one[100][100];
int ex,ey,n,m;
int hashr(int x,int y,int cnt){
	string s="";
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			s+=one[i][j];
	if(!mp[s]){
		mp[s]=cnt;
		return 1;
	}
	else if(mp[s]==cnt)return 1;
	return 0;
}
char tmp[120][120];
void rotate(int x,int y){
	int dst=x;
	for(int i=1;i<=x;i++,dst--)
		for(int j=1;j<=y;j++)
			tmp[j][dst]=one[i][j];
	for(int i=1;i<=y;i++)
		for(int j=1;j<=x;j++)
			one[i][j]=tmp[i][j];
}
int ans=0;
void f(int x,int y,int cnt){
	int xx=1,yy=1;
	for(int i=x;i<=x+ex-1;i++,yy=1,xx++)
		for(int j=y;j<=y+ey-1;j++)
			one[xx][yy++]=s[i][j];
	int flg=1;
	flg&=hashr(ex,ey,cnt);
	rotate(ex,ey);
	if(ex==ey)flg&=hashr(ey,ex,cnt);
	rotate(ey,ex);
	flg&=hashr(ex,ey,cnt);
	rotate(ex,ey);
	if(ex==ey)flg&=hashr(ey,ex,cnt);
	if(flg)ans++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int r1=0,r2=0;
	for(int i=1;i<=n;i++)if(s[i][2]=='#')r1++;
	for(int i=1;i<=m;i++)if(s[2][i]=='#')r2++;
	ex=(n-1)/(r1-1);ex--;
	ey=(m-1)/(r2-1);ey--;
	int all=(r1-1)*(r2-1);
	int nowx=2,nowy=2;
	for(int i=0;i<all;i++){
		memset(one,0,sizeof one);
		f(nowx,nowy,i+1);
		if(nowy+ey+1>=m){
			nowx+=ex+1;
			nowy=2;
		}
		else nowy+=ey+1;
	}
	cout<<ans<<endl;
}



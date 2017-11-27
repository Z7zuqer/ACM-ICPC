#include<bits/stdc++.h>
using namespace std;
char s[110][110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int maxx=0,maxy=0,minx=1e9,miny=1e9;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++){
			if(s[i][j]=='B'){
				maxx=max(maxx,i);
				maxy=max(maxy,j);
				minx=min(minx,i);
				miny=min(miny,j);
			}
		}
	}
	if(minx==1e9)return 0*printf("1\n");
	int lenx=maxx-minx+1;
	int leny=maxy-miny+1;
	if(lenx==leny){
		int ans=0;
		if(n<lenx||m<lenx)return 0*printf("-1\n");
		for(int i=minx;i<=maxx;i++)
			for(int j=miny;j<=maxy;j++)
				if(s[i][j]=='W')ans++;
		cout<<ans<<endl;
	}
	else{
		int maxlen=max(lenx,leny);
		int minlen=min(lenx,leny);
		if(n<maxlen||m<maxlen)return 0*printf("-1\n");
		int ans=0;
		for(int i=minx;i<=maxx;i++)
			for(int j=miny;j<=maxy;j++)
				if(s[i][j]=='W')ans++;
		//cout<<maxlen<<endl;
		cout<<ans+maxlen*(maxlen-minlen)<<endl;
	}
}



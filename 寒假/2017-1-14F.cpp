#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
char s[200010];
int wh[200010][2];
int sumx[maxn<<1],sumy[maxn<<1];
int main(){
	int r,c,t;
	scanf("%d",&t);
	while(t--){
		memset(sumx,0,sizeof(sumx));
		memset(sumy,0,sizeof(sumy));
		scanf("%d%d",&r,&c);	
		scanf("%s",s);
		int mxx=0,mxy=0,miy=1e9,mix=1e9;
		int sx=1,sy=1,a=0,b=0,c=0,d=0;
		for(int i=0;s[i];i++){
			if(s[i]=='>')sy++,a++,sumy[sy+maxn]++;
			if(s[i]=='^')sx--,b++,sumx[sx+maxn]++;
			if(s[i]=='<')sy--,c++,sumy[sy+maxn]++;
			if(s[i]=='v')sx++,d++,sumx[sx+maxn]++;
			wh[i][0]=sx;
			wh[i][1]=sy;
			//sumx[sx]++;
			//sumy[sy]++;
			mxx=max(mxx,sx);
			mix=min(mix,sx);
			mxy=max(mxy,sy);
			miy=min(miy,sy);
		}
		for(int i=mix;i<=mxx;i++)sumx[i+maxn]+=sumx[i-1+maxn];
		for(int i=miy;i<=mxy;i++)sumy[i+maxn]+=sumy[i-1+maxn];
		int lenx=abs(mxx-mix)+1,leny=abs(mxy-miy)+1;
		if(lenx<=r&&leny<=c)cout<<0<<endl;
		else if(lenx<=r){
			int maxm=0;
			for(int i=miy;i+c-1<=mxy;i++)maxm=max(maxm,sumy[i+c-1+maxn]-sumy[i-1+maxn]);
			cout<<a+c-maxm<<endl;
		}
		else if(leny<=c){
			int maxm=0;
			for(int i=mix;i+r-1<=mxx;i++)maxm=max(maxm,sumx[i+r-1+maxn]-sumx[i-1+maxn]);
			cout<<b+d-maxm<<endl;
		}
		else {
			int maxm1=0;
			for(int i=miy;i+c-1<=mxy;i++)maxm1=max(maxm1,sumy[i+c-1+maxn]-sumy[i+maxn]);
			int maxm2=0;
			for(int i=mix;i+r-1<=mxx;i++)maxm2=max(maxm2,sumx[i+r-1+maxn]-sumx[i+maxn]);
			cout<<a-1+c-1+b-1+d-maxm1-1-maxm2-1<<endl;
		}
	} 
	
}



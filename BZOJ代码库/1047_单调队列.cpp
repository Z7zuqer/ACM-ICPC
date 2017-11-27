#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
const int inf=1e9+1;
int mp[maxn][maxn];
int mx[maxn][maxn],mi[maxn][maxn];
int a,b,n;
int val[maxn],pos[maxn];
void pre(){
	int l,r;
	for(int i=1;i<=a;i++){
		l=r=1;
		for(int j=1;j<=b;j++){
			while(l<r&&val[r-1]<=mp[i][j])r--;
			val[r]=mp[i][j];pos[r++]=j;
			if(pos[l]<=j-n)l++;
			if(j>=n)mx[i][j]=val[l];
		}
		l=r=1;
		for(int j=1;j<=b;j++){
			while(l<r&&val[r-1]>=mp[i][j])r--;
			val[r]=mp[i][j];pos[r++]=j;
			if(pos[l]<=j-n)l++;
			if(j>=n)mi[i][j]=val[l];
		}
	}
}
int t1[maxn],t2[maxn];
int main(){
	//pre();
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)	
		for(int j=1;j<=b;j++)
			scanf("%d",&mp[i][j]);
	pre();
	int ans=inf,l,r;
	for(int i=n;i<=b;i++){
		l=r=1;
		for(int j=1;j<=a;j++){
			while(l<r&&val[r-1]<=mx[j][i])r--;
			val[r]=mx[j][i];pos[r++]=j;
			if(pos[l]<=j-n)l++;
			if(j>=n)t1[j]=val[l];
		}
		l=r=1;
		for(int j=1;j<=a;j++){
			while(l<r&&val[r-1]>=mi[j][i])r--;
			val[r]=mi[j][i];pos[r++]=j;
			if(pos[l]<=j-n)l++;
			if(j>=n)t2[j]=val[l];
		}
		for(int j=n;j<=a;j++)ans=min(ans,abs(t1[j]-t2[j]));
	}
	cout<<ans<<endl;
}

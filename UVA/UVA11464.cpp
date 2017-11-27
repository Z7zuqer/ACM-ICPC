#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+1;
int a[17][17],b[17][17];
int ans,n;
void show(){
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			cout<<b[i][j]<<" ";
	cout<<endl;
}
int getans(int c){
	int k=c;
	for(int i=1;i<=n;i++)b[1][i]=a[1][i];
	if(n>=2){
		for(int i=1;i<=n;i++){
			if(i==1){
				if(b[1][2]){
					if(!a[2][1])k++;
					b[2][1]=1;
				}
				else {
					if(a[2][1])return inf;
					b[2][1]=0;
				}
			}
			else if(i==n){
				if(b[1][n-1]){
					if(!a[2][n])k++;
					b[2][n]=1;
				}
				else {
					if(a[2][n])return inf;
					b[2][n]=0;
				}
			}
			else {
				if((b[1][i-1]+b[1][i+1])%2){
					if(!a[2][i])k++;
					b[2][i]=1;
				}
				else {
					if(a[2][i])return inf;
					b[2][i]=0;
				}
			}
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==1){
				if((b[i-2][1]+b[i-1][2])%2){
					if(!a[i][j])k++;
					b[i][j]=1;
				}
				else {
					if(a[i][j])return inf;
					b[i][j]=0;
				}
			}
			else if(j==n){
				if((b[i-2][n]+b[i-1][n-1])%2){
					if(!a[i][j])k++;
					b[i][j]=1;
				}
				else {
					if(a[i][j])return inf;
					b[i][j]=0;
				}
			}
			else {
				if((b[i-1][j-1]+b[i-1][j+1]+b[i-2][j])%2){
					if(!a[i][j])k++;
					b[i][j]=1;
				}
				else {
					if(a[i][j])return inf;
					b[i][j]=0;
				}
			}
		}
	}
	//show();
	return k;
}
void dfs(int wh,int k){
	if(wh>n){
		ans=min(ans,getans(k));
		return ;
	}
	if(!a[1][wh]){
		a[1][wh]=1;
		dfs(wh+1,k+1);
		a[1][wh]=0;
	}
	dfs(wh+1,k);
}
int main(){
	int t,cas=1;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		ans=1e9+1;
		dfs(1,0);
		printf("Case %d: %d\n",cas++,ans==inf?-1:ans);
	}
} 

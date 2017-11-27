#include<bits/stdc++.h>
using namespace std;
double dfs(double x,double y,int k){
	if(k==1)return max(x,y)/min(x,y);
	double maxm=1e19;
	for(int i=1;i<k;i++)maxm=min(maxm,max(dfs(x,y*i/k,i),dfs(x,y*(k-i)/k,k-i)));
	for(int i=1;i<k;i++)maxm=min(maxm,max(dfs(x*i/k,y,i),dfs(x*(k-i)/k,y,k-i)));
	return maxm;
}
double x,y;
int k;
int main(){
	cin>>x>>y>>k;
	printf("%.6lf\n",dfs(x,y,k));
} 

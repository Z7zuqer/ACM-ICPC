#include<bits/stdc++.h>
using namespace std;
int bits[111][2];
int main(){
	int m,s;
	scanf("%d%d",&m,&s);
	if(s<m||m*9<s)return 0*printf("-1\n");
	for(int i=1;i<=m;i++)bits[i][0]=bits[i][1]=1,s--;
	int k=s;
	for(int i=1;i<=m;i++){
		if(s<=8){
			bits[i][0]+=s;
			break;
		}
		else {
			bits[i][0]+=8;
			s-=8;
		}
	}
	for(int i=m;i>=1;i--){
		if(k<=8){
			bits[i][1]+=k;
			break;
		}
		else {
			bits[i][1]+=8;
			k-=8;
		}
	}
	for(int i=1;i<=m;i++)printf("%d",bits[i][1]);printf(" ");
	for(int i=1;i<=m;i++)printf("%d",bits[i][0]);
}



#include<bits/stdc++.h>
using namespace std;
#define ULL unsgined long long
const int maxn=1010;
int mod[2]={1e9+7,1e9+9};
char s[maxn];
ULL F[2][maxn],seed;
void pre_init(){
	for(int i=0;i<1;i++){
		F[i][0]=1;
		for(int j=1;j<maxn;j++)
			F[t][j]=F[t][i-1]*seed%mod[i];
	}
}
int main(){

}



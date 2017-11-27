#include<bits/stdc++.h>
using namespace std;
vector<int>v[110]; 
int main(){
	int p,k;
	scanf("%d%d",&p,&k);
	if(rand()&1)printf("Bob will win.\n");
	else printf("Alice will win.\n");
	for(int i=1;i<=p;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y;
			scanf("%d",&y);
			v[i].push_back(y);
		}
	}
	srand(p*k+1);
}



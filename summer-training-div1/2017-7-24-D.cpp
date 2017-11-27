#include<bits/stdc++.h>
using namespace std;
queue<int>q[41];
int main(){
	int k,pos;
	scanf("%d%d",&k,&pos);
	char c;
	getchar();
	while(scanf("%c",&c)!=EOF&&c!='\n'){
		if(q[0].size()>pos)continue;
		int j=k;
		q[j].push((int)(c-'0'));
		while(q[j].size()>=2&&j>0){
			while(q[j].size()>=2){
				int x=q[j].front();q[j].pop();
				int y=q[j].front();q[j].pop();
				while(x--)q[j-1].push(y);
			}
			j--;
		}
	}
	while(pos--)q[0].pop();
	printf("%d\n",q[0].front());
}

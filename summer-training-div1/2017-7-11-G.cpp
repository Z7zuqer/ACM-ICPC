#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+12345;
int num[maxn];
set<int>s;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	int max_dep=1;
	for(int i=1;i<=n;i++){
		if(s.count(0)>=1){
			printf("No\n");
			continue;
		}
		int tmp_num=num[i];
		while(s.count(max_dep)){
			max_dep++;
		}
		if(max_dep-1<tmp_num){
			printf("Yes\n");
		}
		else if(max_dep-1>tmp_num){
			printf("No\n");
			continue;
		}
		else if(max_dep-1==tmp_num){
			if(s.size()!=max_dep-1){
				printf("No\n");
				continue;
			}
			else {
				printf("Yes\n");
			}
		}
		while(s.count(tmp_num))s.erase(tmp_num--);
		s.insert(tmp_num);
	}
}

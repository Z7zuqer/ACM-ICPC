#include<bits/stdc++.h>
using namespace std;
char s[101010];
int get(int pre,int now){
	int sum=0;
	for(int i=pre;i<=now;i++)sum=sum*10+s[i]-'0';
	return sum;
}
int main(){
	scanf("%s",s);
	int sum=0;
	int now=0,end=strlen(s);
	while(now<end){
		int pre=now;
		while(s[now]!='+'&&now<end)now++;
		sum+=get(pre,now-1);
		now++;
	}
	printf("%d\n",sum);
}



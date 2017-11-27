#include<bits/stdc++.h>
using namespace std;
char s[1010],p[1010];
int work(int sta1,int sta2){
	
}
int main(){
	while(scanf("%s%s",s,p)!=EOF){
		int lens=strlen(s),lenp=strlen(p),maxv=0;
		if(lens==1||lenp==1)break;
		for(int i=0;i<lens;i++)
			for(int j=0;j<lenp;j++)
				maxv=max(maxv,work(i,j));
		printf("%d\n",maxv);
	}
}	



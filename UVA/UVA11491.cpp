#include<bits/stdc++.h>
using namespace std;
char s[100100];
int A[100100];
struct node{
	int wh,v;
	bool operator<(const node &A)const{
		if(v==A.v)return wh>A.wh;
		return v>A.v;
	}
};
priority_queue<node>q;
int main(){
	int n,d;
	while(scanf("%d%d",&n,&d)==2&&n&&d){
		while(!q.empty())q.pop();
		scanf("%s",s);
		for(int i=0;i<n-d;i++)q.push({i,s[i]-'0'});
		for(int i=n-d;i<n;i++){
			//cout<<q.top().v<<endl;
			A[q.top().wh]=1;
			q.pop();
			q.push({i,s[i]-'0'});
		}
		for(int i=0;s[i];i++)
			if(A[i])A[i]=0;
			else printf("%c",s[i]);
		printf("\n");
	}
}



#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q; 
char s[16];
vector<int>v,num;
//1 insert
//2 getmin
//3 remove 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='r'){
			if(q.empty()){
				q.push(1);
				v.push_back(1);
				num.push_back(1);
			}
			v.push_back(3);q.pop();
		}//printf("%s\n",s);
		if(s[0]=='i'){
			int x;
			scanf("%d",&x);
			v.push_back(1);num.push_back(x);
			//printf("%s %d\n",s,x);
			q.push(x);
		}
		if(s[0]=='g'){
			int x;
			scanf("%d",&x);
			while(q.size()){
				if(q.top()>=x)break;
				q.pop();
				v.push_back(3);
				//printf("removeMin\n");
			}
			if(q.empty()||q.top()>x){
				q.push(x);
				v.push_back(1);num.push_back(x);
				//printf("insert %d\n",x);
			}
			v.push_back(2);num.push_back(x);
			//printf("getMin %d\n",x);
		}
	}
	int cnt=0;
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
		if(v[i]==1)printf("insert %d\n",num[cnt++]);
		else if(v[i]==2)printf("getMin %d\n",num[cnt++]);
		else printf("removeMin\n");
}



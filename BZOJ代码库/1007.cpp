#include<bits/stdc++.h>
using namespace std;
const int maxn=50050;
const double eps=1e-8;
struct node{
	double a,b;
	int num;
}res[maxn];
bool cmp(node m,node n){
	if(fabs(m.a-n.a)<eps)return m.b<n.b;
	return m.a<n.a;
}
int top=0,n,wh[maxn];
node st[maxn];
double crossx(node m,node n){
	return (n.b-m.b)/(m.a-n.a);
}
void insert(node k){
	//if(fabs(k.a)<eps&&fabs(k.b)<eps)return ;
	while(top){
		if(fabs(st[top].a-k.a)<eps)top--;
		else if(top>1&&crossx(k,st[top])<=crossx(st[top],st[top-1]))top--;
		else break;
	}
	st[++top]=k;
}
void work(){
	for(int i=1;i<=n;i++)insert(res[i]);
	for(int i=1;i<=top;i++)wh[st[i].num]=1;
	for(int i=1;i<=n;i++)if(wh[i])printf("%d ",i);
}
int main(){
	//int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>res[i].a>>res[i].b;
		res[i].num=i;
	}
	sort(res+1,res+1+n,cmp);
	work();
}

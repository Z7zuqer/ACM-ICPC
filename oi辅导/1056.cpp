#include<bits/stdc++.h>
using namespace std;
#define LL long long
int check(int p,int q,int r,int k){
	LL p1=0,power=1;
	while(p){
		if(p%10>=k)return 0;
		p1+=(p%10)*power;
		p/=10;
		power*=k;
	}
	LL q1=0;power=1;
	while(q){
		if(q%10>=k)return 0;
		q1+=(q%10)*power;
		q/=10;
		power*=k;
	}
	LL r1=0;power=1;
	while(r){
		if(r%10>=k)return 0;
		r1+=power*(r%10);
		r/=10; 
		power*=k;
		//cout<<r1<<endl;
	}
	return 1LL*p1*q1==1LL*r1;
}
int main(){
	int p,r,q;
	scanf("%d%d%d",&p,&q,&r);
	for(int i=2;i<=16;i++){
		if(check(p,q,r,i))return 0*printf("%d\n",i);
	}
	puts("0");
}



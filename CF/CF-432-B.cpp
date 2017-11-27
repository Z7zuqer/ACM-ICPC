#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ax,ay,bx,by,cx,cy;
LL getdis(LL x1,LL y1,LL x2,LL y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
LL cal(LL x1,LL y1,LL x2,LL y2){
	return x1*x2+y1*y2;
}
int work(){
	if(getdis(ax,ay,bx,by)!=getdis(bx,by,cx,cy))return 0;
	return 1;	
}
int solve(){
	if((by-ay)*(cx-bx)!=(cy-by)*(bx-ax))return 1;
	return 0;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&ax,&ay,&bx,&by,&cx,&cy);
	if(work()&&solve())puts("YES");
	else puts("NO");
}



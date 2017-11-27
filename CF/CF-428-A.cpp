#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int sum,rr,now;
int A[110];
int main(){
    int i;
	scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    for(i=0;i<n;i++){
        rr=A[i];
        sum+=rr;
        if(sum<=8){
            now+=sum;
            sum=0;
        }
        else{
            sum-=8;
            now+=8;
        }
        if(now>=k)break;
    }
    if(now<k)printf("-1\n");
    else printf("%d\n",i+1);
}


#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

double init;
int n;
double max_cnt,max_sell;

int main()
{
    scanf("%lf%d",&init,&n);
    double x;
    scanf("%lf",&x);
    max_cnt=init/x;
  //  max_cnt=init/price[0];
    scanf("%lf",&x);
	max_sell=max_cnt*x;
    for(int i=1;i<n;i++){
    	if(i!=1)scanf("%lf",&x);
        max_sell=max(max_sell,max_cnt*x);
        max_cnt=max(max_cnt,init/x);
    }
    printf("%.2lf",max_sell-init);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
double dist(int x1,int y1,int x2,int y2){
    x1-=x2;y1-=y2;
    return sqrt(x1*x1+y1*y1);
}
void work(int x,int y,int &xx,int &yy){
    double tx=0,ty=0,minv= 1e18;
    for(int i = -9;i<=10;i++){
        for(int j=-9;j<=10;j++){
            double ty=j*7.5;
            double tx=2*i*sqrt(25.0-6.25)+j*sqrt(25.0-6.25);
            double res= dist(x,y,tx,ty);
            if(res<minv){
                minv=res;
                xx=i;yy=j;
            }
        }
    }
}
int X[15],Y[15];
int main(){
    for(int i=1;i<=10;i++)scanf("%d%d",&X[i],&Y[i]);
    for(int i=1;i<=10;i++){
    	int x,y;
    	work(X[i],Y[i],x,y);
    	if(i!=10)printf("[%d,%d], ",x,y);
    	else printf("[%d,%d]\n",x,y);
    }
}


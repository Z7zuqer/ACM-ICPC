#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;  
double A[10];
struct point{  
    double x,y;  
};  
struct line{  
    double a,b,c;  
};  
line LineFromSegment(point p1,point p2)//两个点求直线  
{  
    line temp;  
    temp.a=p2.y-p1.y;  
    temp.b=p1.x-p2.x;  
    temp.c=p2.x*p1.y-p1.x*p2.y;  
    return temp;  
}  
point LineInter(line l1,line l2){  
    point temp;  
    double a1=l1.a;  
    double b1=l1.b;  
    double c1=l1.c;  
    double a2=l2.a;  
    double b2=l2.b;  
    double c2=l2.c;  
    if(fabs(b1)<eps)  
    {  
        temp.x=-c1/a1;  
        temp.y=(-c2-a2*temp.x)/b2;  
    }  
    else  
    {  
        temp.x=(c1*b2-b1*c2)/(b1*a2-b2*a1);  
        temp.y=(-c1-a1*temp.x)/b1;  
    }  
  
    return temp;  
}  
point symmetrical(point p, line L){  
    point p2;  
    double d;  
    d = L.a * L.a + L.b * L.b;  
    p2.x = (L.b * L.b * p.x - L.a * L.a * p.x -  
            2 * L.a * L.b * p.y - 2 * L.a * L.c) / d;  
    p2.y = (L.a * L.a * p.y - L.b * L.b * p.y -  
            2 * L.a * L.b * p.x - 2 * L.b * L.c) / d;  
    return p2;  
}  
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=6;i++)scanf("%lf",&A[i]);
		point u={A[3],A[4]};
		point v={A[5],A[6]};
		point p={A[1],A[2]};
		line uv=LineFromSegment(u,v);
		point ans=symmetrical(p,uv);
		printf("%.6f %.6f\n",(ans.x+p.x)/2,(ans.y+p.y)/2);
	}
}



#include<cmath>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps=1e-8;
const double pi=acos(-1.0);
inline double sqr(double x){
    return x*x;
}

int cmp(double x){
    if(fabs(x)<eps)return 0;
    if(x>0)return 1;
    return -1;
}

struct point{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b){
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b){
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b){
        return cmp(a.x-b.x)==0 && cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b){
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b){
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b){
        return point(a.x/b,a.y/b);
    }
    double norm(){
        return sqrt(sqr(x)+sqr(y));
    }
};
double det(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
double dist(const point &a,const point &b){
    return (a-b).norm();
}
point rotate_point(const point &p,double A){
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

struct polygon_convex{
    vector <point> P;
    polygon_convex(int Size=0){
        P.resize(Size);
    }
};

bool comp_less(const point &a,const point &b){
    return cmp(a.x-b.x)<0 || cmp(a.x-b.x)==0 && cmp(a.y-b.y)<0;
}

polygon_convex convex_hull(vector<point> a){
    polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),comp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for(int i=0;i<a.size();++i){
        while(m>1 && cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0)--m;
        res.P[m++]=a[i];
    }
    res.P.resize(m);
    if(a.size()>1)res.P.resize(m-1);
    return res;
}
vector<point>v;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	polygon_convex r=convex_hull(v);
	for(int i=0;i<r.P.size();i++)printf("%d %d\n",r.P[i].x,r.P[i].y);
}


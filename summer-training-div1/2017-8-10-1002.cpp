#include<bits/stdc++.h>
using namespace std;
template <class T>
inline void scand(T &res){
    res=0;
    int sgn=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}
    res *= sgn;
}
template <class T>
inline void outd(T x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)outd(x/10);
    putchar(x%10+'0');
}
const double pi = acos(-1), eps = 1e-7;
int T,in1,in2,in3,in4,in5,tmpx,tmpy;
double xa,xb,ya,yb,R;
inline double calc(double x,double y){
    return sqrt((x-xa)*(x-xa)+(y-ya)*(y-ya)) + sqrt((x-xb)*(x-xb)+(y-yb)*(y-yb));
}
int main(){
//    freopen("data.in","r",stdin);
//    freopen("out.out","w",stdout);
    scand(T);
    while(T--){
        scand(in1);scand(in2);scand(in3);scand(in4);scand(in5);
        R = in1; xa = in2; ya = in3; xb = in4; yb = in5;
        double l = atan2((in5+in3+1.0)/2,(1.0+in4+in2)/2);
        double d0 = sqrt((in3*in3+in2*in2)-0.25*((in2-in4)*(in2-in4)+(in3-in5)*(in3-in5)));
        double alpha = acos(d0/R);
        double r = l + alpha;
        if(r > pi){
            r = l;
            l = r - alpha;
        }
//        printf("//%.7f   %.7f\n",l,r);
    
        double t1 = calc(R*cos(l),R*sin(l));
        double t2 = calc(R*cos(r),R*sin(r));
        if(t1>t2)swap(t1,t2);
        double res1 = 1e9,ans = t1;
//        printf("//%.7f\n",ans);
        if(calc(R*cos((l+r)/2),R*sin((l+r)/2)) < t2){
            for(int times=0;times<=13;times++){
                double m1 = l + (r - l) / 3;
                double m2 = r - (r - l) / 3;
                double f1 = calc(R*cos(m1),R*sin(m1));
                double f2 = calc(R*cos(m2),R*sin(m2));
                if(f1 >= f2){
                    l = m1;
                    res1 = f2;
                }
                else{
                    r = m2;
                    res1 = f1;
                }
            }
        }
        ans = min(ans,res1);
        int it = floor(ans);
        outd(it);
        putchar('.');
        for(int i = 0;i < 7;++i){
            ans -= it;
            ans *= 10;
            it = floor(ans);
            putchar('0'+it);
        }
        putchar('\n');
//        sprintf(ss,"%.7lf",ans);
        //sprintf(ss,"%.7lf",ans);
        //printf("%.7f\n",ans);
//        puts(ss);
    }
    return 0;
}

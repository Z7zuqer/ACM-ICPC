#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Point{
    double x,y;
    Point(double xx,double yy){
        x = xx; y = yy;
    }
    Point(){x = 0; y = 0;}
};

typedef Point Vector;

Vector operator + (Point A,Point B){
    return Vector(A.x+B.x,A.y+B.y);
}

Vector operator - (Point A,Point B){
    return Vector(A.x-B.x,A.y-B.y);
}

Vector operator * (Point A,double p){
    return Vector(A.x*p,A.y*p);
}

double Cross(Vector A, Vector B){
    return A.x*B.y - A.y*B.x;
}

double dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool cmp(Point A, Point B){
    if(A.x != B.x) return A.x < B.x;
    return A.y < B.y;
}

int vis[1010];
Point cHull[1010];

int ConvexHull(Point* p,int n,Point* ch){
    sort(p+1,p+n+1,cmp);
    int tmp[1010];
    int m = 0;
    for(int i = 1;i <= n;++i){
        if(vis[i]) continue;
        while(m > 1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) < 0) m--;
        tmp[m] = i;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-1;i >= 1;i--){
        if(vis[i]) continue;
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) < 0) m--;
        tmp[m] = i;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    for(int i = 0;i < m;++i) vis[tmp[i]] = 1;
    return m;
}

Point p[1010];
int T,n;
vector<int> vNum;

int main(){
    cin >> T;
    srand(time(0));
    while(T--){
        vNum.clear();
        memset(vis,0,sizeof vis);
        scanf("%d",&n);
        for(int i = 1,x,y;i <= n;++i){
            scanf("%d%d",&x,&y);
            p[i].x = x;
            p[i].y = y;
        }
        int used = 0;
        while(n - used > 2){
            int m = ConvexHull(p,n,cHull);
            vNum.push_back(m);
            used += m;
        }
        int ans = 0;
        for(int i = 0;i < vNum.size();++i){
            if(i == (int)vNum.size()-1){
                ans ^= (vNum[i] &1);
                int t = n - used;
                if(t == 0){
                    ans ^= (vNum[i] - 3) & 1;
                    continue;
                }
                if(vNum[i] & 1) ans ^= (t & 1) ? 1 : 0;
                else ans ^= (t & 1) ? 0 : 1;
            }
            else{
                if(vNum[i] & 1) ans ^= 1;
            }
        }
        if(ans) puts("T^T");
        else puts("OwO");
    }

    return 0;
}


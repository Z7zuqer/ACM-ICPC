#include<bits/stdc++.h>
using namespace std;

typedef vector<double> vec;
typedef vector<vec> mat;

const double eps = 1e-12;

vec gauss_jordan(const mat& A,const vec& b){
    int n = A.size();
    mat B(n,vec(n + 1));      //augmented matrix
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j) B[i][j] = A[i][j];
    for(int i = 0;i < n;++i) B[i][n] = b[i];

    for(int i = 0;i < n;++i){
        int pivot = i;
        for(int j = i;j < n;j++)
            if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        swap(B[i],B[pivot]);
        //No solution or innumerable solutions
        if(abs(B[i][i]) < eps) return vec(1,-1);
        for(int j = i + 1;j <= n;++j) B[i][j] /= B[i][i];
        for(int j = 0;j < n;++j)
            if(i != j)
                for(int k = i + 1;k <= n;++k) B[j][k] -= B[j][i] * B[i][k];
    }
    vec x(n);
    for(int i = 0;i < n;++i) x[i] = B[i][n];
    return x;
}

double p;
int N;

int main(){
//    p = 0.4, N = 3;
    cin >> p >> N;
    double q = 1 - p;
    mat A(300);
    vec b(300);
    b[0] = 1;
    for(int i = 1;i < 300;++i) b[i] = 0.0;

    A[0].push_back(1);
    for(int i = 1;i < 300;++i) A[0].push_back(0);
    A[1].push_back(-q);A[1].push_back(1);A[1].push_back(0);A[1].push_back(-p);
    for(int i = 4;i < 300;++i) A[1].push_back(0);
    for(int i = 2;i < 298;++i){
        for(int j = 0;j < i - 1;++j) A[i].push_back(0);
        A[i].push_back(-q);
        A[i].push_back(1);
        A[i].push_back(0);
        A[i].push_back(-p);
        for(int j = i + 3;j < 300;++j) A[i].push_back(0);
    }
    for(int i = 0;i < 297;++i) A[298].push_back(0);
    A[298].push_back(-q);A[298].push_back(1);
    A[298].push_back(0);
    for(int i = 0;i < 298;++i) A[299].push_back(0);
    A[299].push_back(-q);A[299].push_back(1);
    vec ans = gauss_jordan(A,b);
//    for(int i = 0;i < 100;++i)
        printf("%.9f\n",ans[N]);

    return 0;
}

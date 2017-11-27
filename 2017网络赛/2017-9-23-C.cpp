#include<bits/stdc++.h>
using namespace std;

int n,m,p,a[303][303],c[303],sum[303];


int dp[303][303][10][10];
void pre(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[i][j][0][0]=a[i][j];
	for(int i=0;(1<<i)<=n;i++)
		for(int j=0;(1<<j)<=m;j++){
			if(i==0&&j==0)continue;
			for(int row=1;row+(1<<i)-1<=n;row++)
				for(int col=1;col+(1<<j)-1<=m;col++){
					if (i == 0) dp[row][col][i][j] = min(dp[row][col][i][j - 1], dp[row][col + (1 << (j - 1))][i][j - 1]);
                    else if (j == 0) dp[row][col][i][j] = min(dp[row][col][i - 1][j], dp[row + (1 << (i - 1))][col][i - 1][j]);
                    else dp[row][col][i][j] = min(dp[row][col][i][j - 1], dp[row][col + (1 << (j - 1))][i][j - 1]);
				}
		}
}
int query(int x1,int y1,int x2,int y2){//left-right
//	int kx = 0, ky = 0;
 //   while (x1 + (1 << (1 + kx)) - 1 <= x2) kx++;
    int kx=log2(x2-x1+1);if(x1 + (1 << (1 + kx)) - 1 <= x2)kx++;
 //   while (y1 + (1 << (1 + ky)) - 1 <= y2) ky++;
   	int ky=log2(y2-y1+1);if(y1 + (1 << (1 + ky)) - 1 <= y2)ky++;
    int m1 = dp[x1][y1][kx][ky];
    int m2 = dp[x2 - (1 << kx) + 1][y1][kx][ky];
    int m3 = dp[x1][y2 - (1 << ky) + 1][kx][ky];
    int m4 = dp[x2 - (1 << kx) + 1][y2 - (1 << ky) + 1][kx][ky];
    return min(min(m1, m2), min(m3, m4));
}

template <class T>
inline void scan_d(T &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int main(){
    while(scanf("%d%d%d",&n,&m,&p)!=EOF){
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j)
                scan_d(a[i][j]);
        pre();
        memset(c,0,sizeof c);
        memset(sum,0,sizeof sum);
        int ANS = -2e9;
        for(int i = 1;i <= n;++i){
            for(int j = i;j <= n;++j){
                int ans = -2e9, ans2 = -2e9, l,r;
                int minsum = 0, minpos = 0;
                for(int k = 1;k <= m;++k){
                	if(j==i)c[k]=a[j][k];
                	else c[k]+=a[j][k];
   //                 c[k] = (j == i) ? a[j][k] : (c[k] + a[j][k]);
                    sum[k] = sum[k-1] + c[k];

                    if(sum[k] - minsum > ans){
                        ans = sum[k] - minsum;
                        l = minpos + 1; r = k;
                    }

                    if(l > 1){
                        int tmp = sum[l-1] - sum[l-2];
                        int mn = query(i,l-1,j,l-1);
                        if((p-mn)+tmp+ans > ans2)
                            ans2 = (p-mn)+tmp+ans;
                    }

                    int mn = query(i,l,j,r);
                    if((p-mn)+ans > ans2)
                        ans2 = (p-mn)+ans;

                    if(sum[k] < minsum){
                        minsum = sum[k];
                        minpos = k;
                    }
                }
                if(i > 1 || j < n || l > 1 || r < m) ANS = max(ANS,ans);
                ANS = max(ANS,ans2);
            }
        }
        printf("%d\n",ANS);
    }

    return 0;
}


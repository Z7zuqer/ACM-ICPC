#include<bits/stdc++.h>
using namespace std;

int T,n,m,mp[111][111],tot;

int main(){
    cin >> T;
    while(T--){
        tot = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j)
                scanf("%d",&mp[i][j]), tot += mp[i][j];
        if(n & 1){
            printf("%d\n",tot);
            for(int i = 1;i < m;++i) putchar('R');
            for(int i = 1;i <= n / 2;++i){
                putchar('D');
                for(int j = 1;j < m;++j) putchar('L');
                putchar('D');
                for(int j = 1;j < m;++j) putchar('R');
            }
        }
        else if(m & 1){
            printf("%d\n",tot);
            for(int i = 1;i < n;++i) putchar('D');
            for(int i = 1;i < m / 2;++i){
                putchar('R');
                for(int j = 1;j < n;++j) putchar('U');
                putchar('R');
                for(int j = 1;j < n;++j) putchar('D');
            }
        }
        else{
            int mn = 1e9,mi,mj;
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j)
                    if((i & 1) ^ (j & 1)){
                        if(mp[i][j] < mn){
                            mn = mp[i][j];
                            mi = i;
                            mj = j;
                        }
                    }
            }
            printf("%d\n",tot-mn);
            if(mi & 1){
                for(int i = 1;i < mi;++i){
                    if(i & 1)
                        for(int j = 1;j < m;++j) putchar('R');
                    else
                        for(int j = 1;j < m;++j) putchar('L');
                    putchar('D');
                }
                putchar('D');
                for(int i = 1;i < mj / 2;++i)
                    printf("RURD");
                putchar('R');
                for(int i = 1;i <= (m - mj) / 2;++i)
                    printf("RURD");
                for(int i = mi + 2;i <= n;++i){
                    putchar('D');
                    if(i & 1)
                        for(int j = 1;j < m;++j) putchar('L');
                    else
                        for(int j = 1;j < m;++j) putchar('R');
                }
            }
            else{
                for(int i = 1;i < mj;++i){
                    if(i & 1)
                        for(int j = 1;j < n;++j) putchar('D');
                    else
                        for(int j = 1;j < n;++j) putchar('U');
                    putchar('R');
                }
                putchar('R');
                for(int i = 1;i < mi / 2;++i)
                    printf("DLDR");
                putchar('D');
                for(int i = 1;i <= (n - mi) / 2;++i)
                    printf("DLDR");
                for(int i = mj + 2;i <= m;++i){
                    putchar('R');
                    if(i & 1)
                        for(int j = 1;j < n;++j) putchar('U');
                    else
                        for(int j = 1;j < n;++j) putchar('D');
                }
            }
        }
        putchar('\n');
    }

    return 0;
}

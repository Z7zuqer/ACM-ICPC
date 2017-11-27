#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 2002 ;
vector<int> location[26] ;
int lenb,c[maxn*maxn],d[maxn*maxn],f[maxn*maxn],g[maxn],oput[maxn][maxn];

//nlogn Çólcs
void lcs(char a[],char b[])
{
    int i , j , k , w , ans , l , r , mid ;
    for( i = strlen(a)-1 ; i >= 0 ; i--) location[a[i]-'a'].push_back(i) ;
    for( i = k = 0 ; b[i] ; i++)
    {
        g[i] = k;
        for( j = 0 ; j < location[w=b[i]-'a'].size() ; j++,k++)
            c[k] = location[w][j], f[k] = i;
    }
//    printf("//");
//    for(int i = 0;i < k;++i) printf("%d ",c[k]);
//    printf("\n");
    for(int s = 0;s < lenb;++s){
        d[1] = c[g[s]] ;   d[0] = -1 ;
        ans = 1;
        if(g[s] == k) continue;
        oput[s][s] = 1;
        for( i = g[s]+1 ; i < k ; i++){
            if(c[i] > d[ans])
                d[++ans] = c[i];
            else{
                int pos = lower_bound(d,d+ans,c[i]) - d;
                d[pos] = c[i];
            }
            oput[s][f[i]] = ans;
        }
    }
}

int main(){
    char a[maxn] , b[maxn] ;
    scanf("%s%s",a,b);
    lenb = strlen(b);
    lcs(a,b);
    for(int i = 0;i < lenb;++i){
        for(int j = i;j < lenb;++j){
            if(j && oput[i][j] < oput[i][j-1]) printf("%d ",oput[i][j] = oput[i][j-1]);
            else printf("%d ",oput[i][j]);
        }
        printf("\n");
    }

    return 0;
}

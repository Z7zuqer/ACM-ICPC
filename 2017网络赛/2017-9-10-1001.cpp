#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 301111
using namespace std;
char s[MAXN];
int t1[MAXN],t2[MAXN],cc[MAXN],sa[MAXN],rnk[MAXN],height[MAXN];
int len;
bool cmp(int *y,int a,int b,int k)
{
	int a1=y[a];
	int b1=y[b];
	int a2=a+k>=len ? -1:y[a+k];
	int b2=b+k>=len ? -1:y[b+k];
	return a1==b1 && a2==b2;
}
int make_sa()
{
	int *x=t1,*y=t2;
	int m=26;
	for(int i=0; i<m; i++) cc[i]=0;
	for(int i=0; i<len; i++) ++cc[x[i]=s[i]-'a'];
	for(int i=1; i<m; i++) cc[i]+=cc[i-1];
	for(int i=len-1; i>=0; i--) sa[--cc[x[i]]]=i;

	for(int k=1; k<=len; k<<=1)
	{
		int p=0;
		for(int i=len-k; i<len; i++) y[p++]=i;
		for(int i=0; i<len; i++)
		   if( sa[i]>=k ) y[p++]=sa[i]-k;

		for(int i=0; i<m; i++) cc[i]=0;
		for(int i=0; i<len; i++) ++cc[x[y[i]]];
		for(int i=1; i<m; i++) cc[i]+=cc[i-1];
		for(int i=len-1; i>=0; i--) sa[--cc[x[y[i]]]]=y[i];

		swap(x,y);
		m=1; x[sa[0]]=0;
		for(int i=1; i<len; i++)
		  x[sa[i]]=cmp(y,sa[i],sa[i-1],k) ? m-1:m++;

		if( m>=len ) break;
	}
}
void make_height()
{
	for(int i=0; i<len; i++) rnk[sa[i]]=i;
	height[0]=0;
	int k=0;
	for(int i=0; i<len; i++)
	{
		if(!rnk[i]) continue;
		int j=sa[rnk[i]-1];
		if(k) k--;
		while(s[i+k]==s[j+k]) k++;
		height[rnk[i]]=k;
	}
}


int n;
LL minl[200022][18];

void S_table(){
    int l = log(n) / log(2);
    for(int j = 1;j <= l;++j){
        for(int i = 1;i + (1 << (j - 1)) - 1 <= n;++i){
            minl[i][j] = min(minl[i][j-1],minl[i+(1<<(j-1))][j-1]);
        }
    }
}

LL rmq(int l,int r){
    int k = log(r-l+1) / log(2);
    return min(minl[l][k],minl[r-(1<<k)+1][k]);
}


int T,k,cnt[30];
LL ans;

int main(){
    cin >> T;
    while(T--){
        ans = 0;
        memset(t1,0,sizeof t1);
        memset(t2,0,sizeof t2);
        scanf("%d",&k);
        scanf("%s",s); len = strlen(s);
        make_sa();
        make_height();
//        for(int i = 0;i < len;++i) printf("//sa[%d] = %d\n",i,sa[i]);
//        for(int i = 0;i < len;++i) printf("//ht[%d] = %d\n",i,height[i]);
        n = len - 1;
        for(int i = 0;i < 100022;++i) minl[i][0] = 0;
        for(int i = 1;i < len;++i)
            minl[i][0] = height[i];
        S_table();
        for(int i = 1;i <= n - k + 2;++i){
            LL tmp = rmq(i,i+k-2);
            if(height[i-1] < tmp && height[i+k-1] < tmp)
                ans += tmp - max(height[i-1],height[i+k-1]);
        }

        printf("%lld\n",ans);
    }
}


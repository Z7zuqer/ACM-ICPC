#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
struct COMPLEX{
    double r,i;
    COMPLEX(double _r = 0.0,double _i = 0.0){r = _r; i = _i;}
    COMPLEX operator +(const COMPLEX &b){return COMPLEX(r+b.r,i+b.i);}
    COMPLEX operator -(const COMPLEX &b){return COMPLEX(r-b.r,i-b.i);}
    COMPLEX operator *(const COMPLEX &b){return COMPLEX(r*b.r-i*b.i,r*b.i+i*b.r);}
};
void rev(COMPLEX r[],int len){
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(r[i],r[j]);
        int k=len/2;
        while(j>=k){j-=k;k/=2;}
        if(j<k)j+=k;
    }
}
void FFT(COMPLEX r[],int len,int on){
    rev(r,len);
    for(int i=2;i<=len;i<<=1){
        COMPLEX re_d(cos(-on*2*PI/i),sin(-on*2*PI/i));
        for(int j=0;j<len;j+=i){
            COMPLEX re_w(1,0);
            for(int k=j;k<j+i/2;k++){
                COMPLEX re_u=r[k];
                COMPLEX re_t=re_w*r[k+i/2];
                r[k]=re_u+re_t;
                r[k+i/2]=re_u-re_t;
                re_w=re_w*re_d;
            }
        }
    }
    if(on==-1)for(int i=0;i<len;i++)r[i].r/=len;
}
const int maxn=2010*2;
COMPLEX A[maxn*10],B[maxn*10];
int r[maxn*10],num[maxn],L[maxn][maxn],R[maxn][maxn],ans[maxn][maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		memset(L,0,sizeof L);
		memset(R,0,sizeof R);
		memset(ans,0,sizeof ans);
		int len=1;
		while(len<n*2)len<<=1;
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<=n;i++){
			int cnt=0;
			L[i][0]=R[i][0]=1;
			for(int j=i-1;j>=1;j--){
				if(num[j]>num[i])cnt++;
				L[i][cnt]++;
			}
			cnt=0;
			for(int j=i+1;j<=n;j++){
				if(num[j]>=num[i])cnt++;
				R[i][cnt]++;
			}
			for(int j=0;j<len;j++)A[j]=B[j]=COMPLEX(0,0);
			for(int j=0;j<=n;j++)A[j]=COMPLEX(L[i][j],0);
			for(int j=0;j<=n;j++)B[j]=COMPLEX(R[i][j],0);
			FFT(A,len,1);
			FFT(B,len,1);
			for(int j=0;j<len;j++)A[j]=A[j]*B[j];
			FFT(A,len,-1);
			for(int j=0;j<len;j++)ans[num[i]][j]+=(int)(A[j].r+0.5);
		}
		for(int i=1;i<=q;i++){
			int k,x;
			scanf("%d%d",&k,&x);
			printf("%d\n",ans[x][k-1]);
		}
	}
}



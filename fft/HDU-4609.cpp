#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
#define LL long long
int num[100100],cnt[100100];
struct COMPLEX{
    double r,i;
    COMPLEX(double _r = 0.0,double _i = 0.0){r = _r; i = _i;}
    COMPLEX operator +(const COMPLEX &b){return COMPLEX(r+b.r,i+b.i);}
    COMPLEX operator -(const COMPLEX &b){return COMPLEX(r-b.r,i-b.i);}
    COMPLEX operator *(const COMPLEX &b){return COMPLEX(r*b.r-i*b.i,r*b.i+i*b.r);}
};
//  进行FFT和IFFT前的反转变换。
//  位置i和（i二进制反转后位置）互换
//  len必须2的幂
void rev(COMPLEX r[],int len){
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(r[i],r[j]);
        int k=len/2;
        while(j>=k){j-=k;k/=2;}
        if(j<k)j+=k;
    }
}
//做FFT
//len必须为2^k形式
//on==1时是DFT  
//on==-1时是IDFT
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
COMPLEX A[100100*8],B[100100*8];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<=n;i++)cnt[A[i]]++;
		int len=1;
		while(len<=100000*2)len<<=1;
		for(int i=0;i<len;i++)A[i]=complex(0,0);
		for(int i=0;i<100000;i++)A[i]=complex(cnt[i+1],0);
		FFT(A,len,1);
		for(int i=0;i<len;i++)A[i]=A[i]*A[i];
		FFT(A,len,-1);
		for(int i=0;i<100000;i++)cnt[i+1]=(int)(A[i].r+0.5);
		LL ans=0;
		for(int i=1;i<=100000;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=100000;i++){
			ans+=cnt[100000]-
		}
	}
}



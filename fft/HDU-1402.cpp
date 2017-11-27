#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+172;
const double PI=acos(-1.0);
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
COMPLEX A[maxn],B[maxn];
char s_A[maxn/2],s_B[maxn/2];
int ans[maxn];
int main(){
	while(scanf("%s%s",s_A,s_B)==2){
		//memset(ans,0,sizeof ans);
		int len1=strlen(s_A);
		int len2=strlen(s_B);
		int len=1;
		while(len<len1*2||len<len2*2)len<<=1;
		for(int i=0;i<len1;i++)A[i]=COMPLEX(s_A[len1-i-1]-'0',0);
		for(int i=len1;i<len;i++)A[i]=COMPLEX(0,0);
		for(int i=0;i<len2;i++)B[i]=COMPLEX(s_B[len2-i-1]-'0',0);
		for(int i=len2;i<len;i++)B[i]=COMPLEX(0,0);
		FFT(A,len,1);
		FFT(B,len,1);
		for(int i=0;i<len;i++)A[i]=A[i]*B[i];
		FFT(A,len,-1);
		for(int i=0;i<len;i++)ans[i]=(int)(A[i].r+0.5);
		for(int i=0;i<len;i++){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		int end=-1;
		for(int i=len-1;i>=0;i--){
			if(ans[i]>0){
				end=i;
				break;
			}
		}
		if(end==-1)printf("0");
		else for(int i=end;i>=0;i--)printf("%d",ans[i]);printf("\n");
	}
}



#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int A[maxn];
int n,q,l,r,s,t,num[11],pre[maxn][11];//2 3 5 7
inline int read() {    
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}

inline int make(int k){
	//memset(num,0,sizeof(num));
	int cnt=0,tmp=1;;
	while(k){
		if(k&1)num[cnt++]=tmp;;
		k>>=1;tmp++;
	}
	return cnt;
}
int main(){
	t=read();
	while(t--){
		n=read();q=read();
		for(int i=1;i<=n;i++){
			A[i]=read();
			for(int j=1;j<=10;j++)
				if(A[i]%j==0)
					pre[i][j]=1;
				
		}
		//cout<<q<<endl;
		while(q--){
			int ans=0;
			l=read();r=read();s=read();
			int cnt=make(s);
			int all=r-l;
			for(int i=0;i<all/2;i++){
				if(l+i>r-i)break;
				for(int j=0;j<cnt/2+1;j++){
					if(pre[i+l][num[j]]||pre[i+l][num[cnt-1-j]]){
						ans++;
						break;
					}
				}
				for(int j=0;j<cnt/2+1;j++){
					if(pre[r-i][num[j]]||pre[r-i][num[cnt-1-j]]){
						ans++;
						break;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
}



#include<bits/stdc++.h>
using namespace std;
int n;
int A[5][7];
int check(int x){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=6;j++)
			if(A[i][j]==x)
				return 1;
	if(x/10<1)return 0;
	if(x/100){
		int num1=x/100,num2=(x-num1*100)/10,num3=x%10;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					for(int k=1;k<=n;k++)
						if(i!=k&&k!=j)
							for(int ii=1;ii<=6;ii++)
								for(int jj=1;jj<=6;jj++)
									for(int kk=1;kk<=6;kk++)
										if(A[i][ii]==num1&&A[j][jj]==num2&&A[k][kk]==num3)
											return 1;
		return 0;
	}
	else {
		int num1=x%10,num2=x/10;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
				for(int xi=1;xi<=6;xi++)
					for(int xj=1;xj<=6;xj++)
						if(A[i][xi]==num1&&A[j][xj]==num2)
							return 1;
		return 0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=6;j++)
			scanf("%d",&A[i][j]);
	for(int i=1;;i++)
		if(!check(i))return 0*printf("%d",i-1);
	
}



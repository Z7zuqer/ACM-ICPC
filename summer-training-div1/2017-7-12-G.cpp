#include<bits/stdc++.h>
using namespace std;
int r,c,k;
int mp[5][5];
int main(){
	//freopen("alignment.in","r",stdin);
	//freopen("alignment.out","w",stdout);
	while(1){
		scanf("%d%d%d",&r,&c,&k);
		mp[r][c]=k;
		int ans=5-k;
		for(int i=1;i<=4;i++){
			int sum=0,sum_s=0,wh_x=-1,wh_y=-1;
			for(int j=1;j<=4;j++)
				if(mp[i][j])sum+=mp[i][j];
				else sum_s++,wh_x=i,wh_y=j;
			if(sum_s==1&&sum>=6&&sum<10){
				printf("%d %d %d WIN\n",wh_x,wh_y,10-sum);
				fflush(stdout);
				return 0;
			}
		}
		for(int j=1;j<=4;j++){
			int sum=0,sum_s=0,wh_x=-1,wh_y=-1;
			for(int i=1;i<=4;i++)
				if(mp[i][j])sum+=mp[i][j];
				else sum_s++,wh_x=i,wh_y=j;
			if(sum_s==1&&sum>=6&&sum<10){
				printf("%d %d %d WIN\n",wh_x,wh_y,10-sum);
				fflush(stdout);
				return 0;
			}
		}
		int minm=1e9+1,wh_y=-1;
		for(int j=1;j<=4;j++){
			if(j==c)continue;
			int sum=0;
			for(int i=1;i<=4;i++)
				if(mp[i][j])sum++;
			//cout<<j<<" "<<sum<<endl;
			if(sum<minm){
				minm=sum;
				wh_y=j;         
			}
		}
		mp[r][wh_y]=ans;
		printf("%d %d %d\n",r,wh_y,ans);
		fflush(stdout);
	}
}



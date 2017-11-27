#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
char s[7][maxn][maxn];
char r[maxn][maxn][maxn];
int n;
void get(int k,int i,int j,int u,int &x,int &y,int &z){
	if(k==0)x=n-1-u,y=i,z=n-1-j;
	if(k==1)x=j,y=u,z=n-1-i;
	if(k==2)x=u,y=n-j-1,z=n-1-i;
	if(k==3)x=n-1-j,y=n-u-1,z=n-1-i;
	if(k==4)x=i,y=j,z=n-1-u;
	if(k==5)x=i,y=n-1-j,z=u;
	//x-=1;y-=1;z-=1;
}
void show(){
	for(int i=0;i<n;i++,puts("========"))
		for(int j=0;j<n;j++,puts(""))
			for(int k=0;k<n;k++)
				cout<<r[i][j][k];
}
int main(){;
	//int n;
	while(scanf("%d",&n)==1&&n){
		for(int j=0;j<n;j++){
			for(int i=0;i<6;i++){
				scanf("%s",s[i][j]);
			}
		}
		/*for(int i=0;i<6;i++,puts("\n"))
			for(int j=0;j<n;j++,puts(""))
				for(int k=0;k<n;k++)
					cout<<s[i][j][k];*/
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int u=0;u<n;u++)
					r[i][j][u]='#';
		for(int u=0;u<6;u++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					if(s[u][i][j]=='.'){
						for(int k=0;k<n;k++){
							int x,y,z;
							get(u,i,j,k,x,y,z);
							r[x][y][z]='.';
						}
					}
				}
		//show();
		while(1){
			int flg=1;
			for(int i=0;i<6;i++)
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++){
						if(s[i][j][k]!='.'){
							//int flg=1;
							for(int u=0;u<n;u++){
								int x,y,z;
								get(i,j,k,u,x,y,z);
								if(r[x][y][z]=='.')continue;
								if(r[x][y][z]=='#'){
									r[x][y][z]=s[i][j][k];
									break;
								}
								if(r[x][y][z]==s[i][j][k])break;
								r[x][y][z]='.';
								flg=0;
								//cout<<"dsa"<<endl;
							}
							//if(!flg)break;
						}
					}
			if(flg)break;
			//show();
		}
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					if(r[i][j][k]!='.')ans++;
		printf("Maximum weight: %d gram(s)\n",ans);
	}
}

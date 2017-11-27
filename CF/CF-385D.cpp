#include<bits/stdc++.h>
using namespace std;
int ans[1010],n,now;
int main(){
	memset(ans,0x3f,sizeof(ans));
	scanf("%d",&n);
	for(int i=0;i<10;i++)
		for(int j=0;j<2;j++){
			int flg=0,cnt=0;
			for(int u=0;u<n;u++)
				if(((u>>i)&1)==j)flg=1,cnt++;
			if(flg){
				cout<<cnt<<endl;
				for(int u=0;u<n;u++)
					if(((u>>i)&1)==j)
						cout<<u+1<<" ";
				cout<<endl;
				fflush(stdout);
				for(int u=0;u<n;u++){
					int a;
					scanf("%d",&a);
					if(((u>>i)&1)==(!j))
						ans[u]=min(ans[u],a);
					}
				}
			now=!now;
		}
	cout<<"-1"<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	fflush(stdout);
}

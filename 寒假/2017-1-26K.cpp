#include<bits/stdc++.h>
using namespace std;
int d,m,y,n;
struct node{
	int d,m,y,sig;
	bool operator<(const node &A)const{
		if(y==A.y)
			if(m==A.m)return d>A.d;
			else return m>A.m;
		return y>A.y;
	}
}A[110];
int main(){
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	cin>>d>>m>>y>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i].d>>A[i].m>>A[i].y,A[i].sig=i;
	sort(A+1,A+1+n);
	int ans=-1;
	for(int i=1;i<=n;i++){
		//cout<<A[i].d<<" "<<A[i].m<<" "<<A[i].y<<endl;
		if(A[i].y<=y-18){
			if(A[i].y==y-18&&(A[i].m<m||(A[i].m==m&&A[i].d<=d))){
				ans=A[i].sig;
				break;
			}
			else if(A[i].y<y-18){
				ans=A[i].sig;
				break;
			}
		}
	}
	cout<<ans<<endl;
}



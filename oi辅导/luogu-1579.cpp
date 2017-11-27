#include<bits/stdc++.h>
using namespace std;
int s[100001];
bool zs(int a)
{
	 for(int i=2;i<=sqrt(a)+3;i++)
	 {
	      if(a%i==0&&a!=i)
		  {
		  	 return false; 
		  } 
	} 
	return true;
}
int main()
{
	int j,z=1,i,n;
	scanf("%d",&n);
	s[z++]=2;
	for(i=2;i<=n;i++) 
	{
		 if(zs(i)&&i!=2)
		 {
		 	 s[z]=i;
		 	 z++; 
		 }
	}
	for(i=1;i<z;i++)
	{
	     for(j=i;j<z;j++)
		 {
		 	  if(zs(n-s[i]-s[j])&&n-s[i]-s[j]>0)
		 	  {
		 	  	  cout<<s[i]<<" "<<s[j]<<" "<<n-s[i]-s[j];
		 	  	  return 0;
		 	  }
		 } 
	} 
}


#include <bits/stdc++.h>
using namespace std;
char s[200100];
int main(){
	//char s[5000];
	int p, i, Half, Left, Right, Count;
	while( cin>>s ){
		i = strlen(s);
		long long n=i,res=0;
		Count = 0;
		//�����Ҷ�ס���һ��
		for(p=0; p<=i-1; p++)
		{
			Half = ((i-1)-p) / 2;
			//����Ӵ���������
			if( ((i-1)-p)%2 == 0 )
			{
				Left = p + Half - 1;
				Right = p + Half + 1;
			}
			else   //����Ӵ���ż����
			{
				Left = p + Half;
				Right = p + Half + 1;
			}
			while( Left >= p )
			{
				if( s[Left] == s[Right])  
				{
					Count++;  //������һ�����Ĵ�
					int len=Right-Left+1; 
					res+=(len)*(len-1)/2;
					Left--;
					Right++;
				}
				else  //�������ȣ�������ֹ��������������ɢ�����ܻ��л��Ĵ�
				{
					break;
				}
			}
		}
		for(p=i-2; p>=1; p--){
			Half = p / 2;
			//����Ӵ���������
			if( p%2 == 0 )
			{
				Left = Half - 1;
				Right = Half + 1;
			}
			else   //����Ӵ���ż����
			{
				Left = Half;
				Right = Half + 1;
			}
			while( Left >= 0 ){
				if( s[Left] == s[Right] ){
					Count++;
					int len=Right-Left+1; 
					res+=(len)*(len-1)/2;
					Left--;
					Right++;
				}
				else break;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)ans+=i-1;
		ans-=Count;
		ans+=1;		
		printf("%lld\n",ans);
	}
	return 0;
}


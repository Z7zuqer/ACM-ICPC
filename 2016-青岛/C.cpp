#include<bits/stdc++.h>
using namespace std;

#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4
class bigPosInt
{
private:
	int a[500];    //���Կ��ƴ�����λ��
	int len;       //��������
public:
	bigPosInt(){ len = 1;memset(a,0,sizeof(a)); }   //���캯��
	bigPosInt &operator=(const bigPosInt &);   //���ظ�ֵ�����������֮����и�ֵ����

	friend istream& operator>>(istream&,  bigPosInt&);   //�������������
	friend ostream& operator<<(ostream&,  bigPosInt&);   //������������

	bigPosInt operator+(const bigPosInt &) const;   //���ؼӷ����������������֮����������
	bigPosInt operator-(const bigPosInt &) const;   //���ؼ������������������֮����������
	bigPosInt operator*(const bigPosInt &) const;   //���س˷����������������֮������
	void print();       //�������
};
istream& operator>>(istream & in,  bigPosInt & b)   //�������������
{
	char ch[MAXSIZE*4];
	int i = -1;
	in>>ch;
	int l=strlen(ch);
	int count=0,sum=0;
	for(i=l-1;i>=0;)
	{
		sum = 0;
		int t=1;
		for(int j=0;j<4&&i>=0;j++,i--,t*=10)
		{
			sum+=(ch[i]-'0')*t;
		}
		b.a[count]=sum;
		count++;
	}
	b.len =count++;
	return in;

}
ostream& operator<<(ostream& out,  bigPosInt& b)   //������������
{
	int i;
	cout << b.a[b.len - 1];
	for(i = b.len - 2 ; i >= 0 ; i--)
	{
		cout.width(DLEN);
		cout.fill('0');
		cout << b.a[i];
	}
	return out;
}

bigPosInt bigPosInt::operator+(const bigPosInt & T) const   //��������֮����������
{
	bigPosInt t(*this);
	int i,big;      //λ��
	big = T.len > len ? T.len : len;
	for(i = 0 ; i < big ; i++)
	{
		t.a[i] +=T.a[i];
		if(t.a[i] > MAXN)
		{
			t.a[i + 1]++;
			t.a[i] -=MAXN+1;
		}
	}
	if(t.a[big] != 0)
		t.len = big + 1;
	else
		t.len = big;
	return t;
}
bigPosInt bigPosInt::operator-(const bigPosInt & T) const   //��������֮����������
{
	int i,j,big;
	bool flag;
	bigPosInt t1,t2;
	if(*this>T)
	{
		t1=*this;
		t2=T;
		flag=0;
	}
	else
	{
		t1=T;
		t2=*this;
		flag=1;
	}
	big=t1.len;
	for(i = 0 ; i < big ; i++)
	{
		if(t1.a[i] < t2.a[i])
		{
			j = i + 1;
			while(t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while(j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while(t1.a[len - 1] == 0 && t1.len > 1)
	{
		t1.len--;
		big--;
	}
	if(flag)
		t1.a[big-1]=0-t1.a[big-1];
	return t1;
}

bigPosInt bigPosInt::operator*(const bigPosInt & T) const   //��������֮����������
{
	bigPosInt ret;
	int i,j,up;
	int temp,temp1;
	for(i = 0 ; i < len ; i++)
	{
		up = 0;
		for(j = 0 ; j < T.len ; j++)
		{
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if(temp > MAXN)
			{
				temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			}
			else
			{
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if(up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while(ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
void bigPosInt::print()    //�������
{
	int i;
	cout << a[len - 1];
	for(i = len - 2 ; i >= 0 ; i--)
	{
		cout.width(DLEN);
		cout.fill('0');
		cout << a[i];
	}
	cout << endl;
}

int main(){
    bigPosInt a = 111,b = -22;
    a = a + b;
    cout << a;

    return 0;
}

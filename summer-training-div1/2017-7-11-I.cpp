#include<cstdio>
#include<cmath>
using namespace std;

int x, y, T, p, q, gc;
const int N=50000;

int exgcd(int m, int n, int &x, int &y) {
	int x0 = 0, y0 = 1, x1 = 1, y1 = 0, r = m % n;
	x = 0, y = 1;
	while (r) {
		x0 = x1 - m / n * x; x1 = x; x = x0;
		y0 = y1 - m / n * y; y1 = y; y = y0;
		m = n; n = r; r = m % n;
	}
	return n;
}


int main()
{
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &x, &y);
		if (x <= N)
		{
			puts("3");
			printf("%d %d\n", 0, 0);
			printf("%d %d\n", x, y);
			printf("%d %d\n", 0, 1);
			continue;
		}
		if (y <= N)
		{
			puts("3");
			printf("%d %d\n", 0, 0);
			printf("%d %d\n", x, y);
			printf("%d %d\n", 1, 0);
			continue;
		}
		gc = exgcd(y, x, p, q);
		p = abs(p);
		q = abs(q);
		if (gc <= N)
		{	// 3
			puts("3");
			printf("%d %d\n", 0, 0);
			printf("%d %d\n", x, y);
			printf("%d %d\n", p, q);
			continue;
		} else {
			// 4
			puts("4");
			printf("%d %d\n", x, y);
			printf("%d %d\n", 0, 1);
			printf("%d %d\n", x - x / gc, y - y / gc);
			printf("%d %d\n", 1, 0);
		}
	}
	return 0;
}



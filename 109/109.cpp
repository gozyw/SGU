#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int p = n;
	printf("%d", p);
	for ( int i = 1; i <= n; i ++ )
		for ( int j = 1; j <= n; j ++ )
			if ( i + j >= p + 3 ) printf(" %d", (i - 1) * n + j);
	puts("");
	if ( p & 1 ) p += 2;
	else p ++;
	for ( int d = n + 2; d > 2; d -- )
	{
		printf("%d", p);
		p += 2;
		for ( int i = 1; i <= n; i ++ )
			for ( int j = 1; j <= n; j ++ )
				if ( i + j == d ) printf(" %d", (i - 1) * n + j);
		puts("");
	}
	return 0;
}

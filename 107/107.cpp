#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	if ( n <= 8 ) puts("0");
	else if ( n == 9 ) puts("8");
	else
	{
		printf("72");
		n -= 10;
		while ( n -- ) putchar('0');
		puts("");
	}
	return 0;
}


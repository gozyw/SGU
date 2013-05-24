#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MP(a, b) make_pair(a, b)
using namespace std;
bool fg[10001];
int cnt;
int G( int s )
{
	int res = s;
	while ( s )
	{
		res += s % 10;
		s /= 10;
	}
	return res;
}
typedef pair<int ,int> GG;
vector<GG >que;
inline bool cmp( GG a, GG b )
{
	return a.first < b.first;
}
int res[5600];
int main()
{
	int n, k;
	cin >> n >> k;
	que.clear();
	for ( int i = 0; i < k; i ++ )
	{
		int q;
		cin >> q;
		que.push_back(MP(q, i));
	}
	sort(que.begin(), que.end(), cmp);
	int head = 0;
	cnt = 0;
	for ( int st = 0; st <= 9990000; st += 10000 )
	{
		if ( st > n ) break;
		int pre = st - 200, tail = st + 10000;
		memset(fg, 0, sizeof(fg));
		for ( int i = pre; i <= tail; i ++ )
		{
			int gs = G(i);
			if ( gs >= st && gs <= tail ) fg[gs - st] = true;
		}
		for ( int i = 0; i < 10000; i ++ )
		{
			if ( !fg[i] )
			{
				if ( i + st <= n )
				cnt ++;
				while ( head < k && cnt == que[head].first )
				res[que[head].second] = i + st, head ++;
			}
		}
	}
	printf("%d\n", cnt);
	for ( int i = 0; i < k; i ++ )
	{
		if ( i ) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}
/*

10000000 10
1 10 100 1000 10000 50000 60000 70000 80000 90000



*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MP(x, y) make_pair(x, y)
const int MAXN = 7;
vector<int > sto[MAXN][MAXN];
int mz[MAXN][MAXN], n;
int fa[MAXN];
int find( int x )
{
	return ~fa[x]? fa[x] = find(fa[x]) : x;
}
pair<int, int>path[210];
int suc;
void DFS(int pt, int c)
{
	if ( suc ) return;
	if ( c == n )
	{
		suc = 1;
		int ct[MAXN][MAXN] = {0};
		for ( int i = 0; i < n; i ++ )
		{
			int a = path[i].first, b = path[i].second;
			if ( ct[a][b] < sto[a][b].size() )
			{
				printf("%d +\n", sto[a][b][ct[a][b]]);
				ct[a][b] ++;
			}
			else
			{
				printf("%d -\n", sto[b][a][ct[b][a]]);
				ct[b][a] ++;
			}
		}
		return ;
	}
	for ( int i = 0; i < MAXN; i ++ )
	{
		if ( mz[pt][i] )
		{
			path[c] = MP(pt, i);
			mz[pt][i] --;
			mz[i][pt] --;
			DFS(i, c + 1);
			mz[pt][i] ++;
			mz[i][pt] ++;
		}
	}
}
int main()
{
	memset(mz, 0, sizeof(mz));
	memset(fa, -1, sizeof(fa));
	cin >> n;
	int sz[MAXN] = {0}, ap[MAXN] = {0}, ca;
	for ( int i = 1; i <= n; i ++ )
	{
		int a, b;
		cin >> a >> b;
		sz[a] ++, sz[b] ++;
		ap[a] = ap[b] = 1;
		mz[a][b] ++;
		mz[b][a] ++;
		sto[a][b].push_back(i);
		int ffa = find(a), ffb = find(b);
		if ( ffa != ffb )
		fa[ffa] = ffb;
		ca = a;
	}
	int cnt = 0, fcnt = 0;
	for ( int i = 0; i < MAXN; i ++ )
	{
		if ( sz[i] & 1 ) cnt ++, ca = i;
		if ( find(i) == i && ap[i] ) fcnt ++;
	}
	if ( (cnt && cnt != 2) || fcnt != 1 )
	{
		puts("No solution");
		return 0;
	}
	suc = 0;
	DFS(ca, 0);
	if ( !suc ) puts("No solution");
	return 0;
}

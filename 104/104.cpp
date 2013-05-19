#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 105;
int n, m;
int f[MAXN][MAXN];
int dp[MAXN][MAXN];
vector<int>path[MAXN][MAXN];
inline bool cmax( int &a, int b )
{
	if ( b > a )
	{
		a = b;
		return true;
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++ )
		for ( int j = 1; j <= m; j ++ )
			cin >> f[i][j];
	for ( int i = 0; i <= n; i ++ )
		for ( int j = 0; j <= m; j ++ )
			path[i][j].clear();
	memset(dp, 0x80, sizeof(dp));
	dp[0][0] = 0;
	for ( int i = 1; i <= m; i ++ )
	{
		for ( int j = 0; j <= n; j ++ )
		{
			if ( dp[i - 1][j] == dp[0][1] ) continue;
			if ( cmax(dp[i][j], dp[i - 1][j]) )
			{
				path[i][j] = path[i - 1][j];
			}
			if ( cmax(dp[i][j + 1], dp[i - 1][j] + f[j + 1][i]) )
			{
				path[i][j + 1] = path[i - 1][j];
				path[i][j + 1].push_back(i);
			}
		}
	}
	cout << dp[m][n] << endl;
	for ( int i = 0; i < path[m][n].size(); i ++ )
	{
		if ( i ) cout << " ";
		cout << path[m][n][i];
	}
	cout << endl;
	return 0;
}



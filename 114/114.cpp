#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 20000;
/*
solution 1 
double p[MAXN], c[MAXN];
int n;
double cal( double x )
{
	double res = 0;
	for ( int i = 0; i < n; i ++ )
	{
		res += fabs(p[i] - x) * c[i];
	}
	return res;
}
double gao()
{
	double l = 0, r = 50000, ld, rd;
	while ( r - l > 1e-8 )
	{
		ld = (2 * l + r) / 3.;
		rd = (l + 2 * r) / 3.;
		//printf("%f %f %f %f \n",ld,cal(2.),rd,cal(rd));
		if ( cal(ld) > cal(rd) ) l = ld;
		else r = rd;
	}
	return l;
}
*/
#define MP(x, y) make_pair(x, y)
typedef pair<int, int> L;
vector<L>vc;
inline bool cmp( L a, L b )
{
	return a.first < b.first;
}
int main()
{
	int sum = 0, n;
	cin >> n;
	for ( int i = 0; i < n; i ++ )
	{
		int p, c;
		cin >> p >> c;
		vc.push_back(MP(p, c));
		sum += c;
	}
	sort(vc.begin(), vc.end(), cmp);
	int ts = 0;
	for ( int i = 0; i < n; i ++ )
	{
		ts += vc[i].second;
		if ( 2 * ts >= sum )
		{
			printf("%d.00000\n", vc[i].first);
			break;
		}
	}
	return 0;
}

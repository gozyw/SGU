#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MP(x, y) make_pair(x, y)
const int MAXN = 305;
const int QueS = 110000;
int mt[MAXN][MAXN][2]; // 第i点，区间第j秒，灯颜色 
struct Nd
{
	int p, t, pre;
	Nd(){}
	Nd( int _p, int _t, int _pre ):
		p(_p), t(_t), pre(_pre){}
}que[QueS];
int st, ed, n, m, head, tail;
vector<pair<int, int> >mp[MAXN];
int Initcol[MAXN], Remtim[MAXN], T0[MAXN], T1[MAXN], TS[MAXN];
int CalCol( int n, int t )
{
	if ( t < Remtim[n] ) return Initcol[n];
	int pt = (t - Remtim[n]) % TS[n];
	if ( !Initcol[n] ) return pt < T1[n] ? 1 : 0;
	return pt < T0[n] ? 0 : 1;
}
int GetCol( int n, int st, int t )
{
	return (t - st) % TS[n] < T0[n] ? 0 : 1;
}
int CalMst( int a, int b, int ta )
{
	int ca = Initcol[a]? Remtim[a] : Remtim[a] + T1[a];
	int cb = Initcol[b]? Remtim[b] : Remtim[b] + T1[b];
	ca -= TS[a], cb -= TS[b];
	
	int bca = GetCol(a, ca, ta), bcb = GetCol(b, cb, ta);
	
	if ( bca == bcb ) return 0;
	int rta, rtb, sum = 0;
	if ( bca == 0 ) rta = T0[a] - (ta - ca) % TS[a];
	else rta = TS[a] - (ta - ca) % TS[a];
	if ( bcb == 0 ) rtb = T0[b] - (ta - cb) % TS[b];
	else rtb = TS[b] - (ta - cb) % TS[b];
	//if ( a == 2 && b == 4 ) printf("&& %d %d %d\n",rta,rtb, ta);
	
	if ( rta != rtb ) return min(rta, rtb);
	else sum += rta;
	if ( bca == 0 ) rta = T1[a];
	else rta = T0[a];
	if ( bcb == 0 ) rtb = T1[b];
	else rtb = T0[b];
	if ( rta != rtb ) return min(rta, rtb) + sum;
	else sum += min(rta, rtb);
	
	if ( bca == 0 ) rta = T0[a];
	else rta = T1[a];
	if ( bcb == 0 ) rtb = T0[b];
	else rtb = T1[b];
	if ( rta != rtb ) return min(rta, rtb) + sum;
	return -1;
}
void CalNxt( int n, int t, int &p, int &c )
{
	if ( t < Remtim[n] ) p = t, c = Initcol[n];
	else
	{
		int pt = (t - Remtim[n]) % TS[n];
		if ( !Initcol[n] )
		{
			if ( pt < T1[n] ) p = pt, c = 1;
			else p = pt, c = 0;
		}
		else
		{
			if ( pt < T0[n] ) p = pt, c = 0;
			else p = pt, c = 1;
		}
	}
}
int rps[QueS], Bg;
void BFS()
{
	head = tail = 0;
	que[tail ++] = Nd(st, 0, -1);
	memset(mt, -1, sizeof(mt));
	mt[st][Initcol[st]? T1[st] - Remtim[st] : T0[st] - Remtim[st]][Initcol[st]] = 0;
	int res = 0xFFFFFFF;
	while ( head ^ tail )
	{
		Nd tmp = que[head ++];
		if ( tmp.t >= res ) continue;
		int p = tmp.p, t = tmp.t, pre = tmp.pre;
		//printf("~%d %d\n", p, t);
		if ( p == ed )
		{
			res = tmp.t;
			Bg = 0;
			rps[Bg ++] = p;
			while ( pre != -1 )
			{
				rps[Bg ++] = que[pre].p;
				pre = que[pre].pre;
			}
			continue;
		}
		for ( int i = 0; i < mp[p].size(); i ++ )
		{
			int np = mp[p][i].first, cst = mp[p][i].second;
			int mcst = CalMst(p, np, t);
			//if ( p == 2 && np == 4 ) printf("**%d %d %d\n",mcst, np, cst);
			if ( mcst == -1 ) continue;
			int npt = t + mcst + cst;
			int npp, npc;
			CalNxt(np, npt, npp, npc);
			if ( mt[np][npp][npc] == -1 || npt < mt[np][npp][npc] )
			{
				mt[np][npp][npc] = npt;
				que[tail ++] = Nd(np, npt, head - 1);
			}
		}
	}
	if ( res == 0xFFFFFFF )
	puts("0");
	else
	{
		printf("%d\n",res);
		for ( int i = Bg - 1; i >= 0; i -- )
		{
			printf("%d", rps[i]);
			if ( i ) printf(" ");
		}
		puts("");
	}
}
int main()
{
	cin >> st >> ed;
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++ )
	{
		char s[4];
		cin >> s >> Remtim[i] >> T0[i] >> T1[i];
		Initcol[i] = s[0] == 'B' ? 0 : 1;
		TS[i] = T0[i] + T1[i];
		mp[i].clear();
	}
	memset(mp, -1, sizeof(mp));
	while ( m -- )
	{
		int a, b, c;
		cin >> a >> b >> c;
		mp[a].push_back(MP(b, c));
		mp[b].push_back(MP(a, c));
	}
	BFS();
	return 0;
}


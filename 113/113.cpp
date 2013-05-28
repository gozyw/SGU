#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 200;
bool f[MAXN * MAXN];
int pri[MAXN * MAXN], sz;
void prime_init()
{
	memset(f, 0, sizeof(f));
	for ( int i = 2; i <= 200; i ++ )
	{
		if ( f[i] ) continue;
		for ( int j = i * i; j < MAXN * MAXN; j += i )
			f[j] = true;
	}
	sz = 0 ;
	for ( int i = 2; i < MAXN * MAXN; i ++ )
	if ( !f[i] ) pri[sz ++] = i;
}
#define gcc 10007
#define MAX ((Int)1<<63)-1
using namespace std;
typedef unsigned __int64 Int;
Int p[10] = {2, 3, 5, 7, 11, 13, 17, 1, 23, 29};
map < Int, int > Map;
inline Int Gcd(Int a, Int b)
{
	Int m = 1;
	if(!b)
		return a;
	while(m)
	{
		m = a % b;
		a = b;
		b = m;
	}
	return a;
}
//计算a*b%n
inline Int Produc_Mod(Int a, Int b, Int mod)
{
	Int sum = 0;
	while(b)
	{
		if(b & 1) sum = (sum + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return sum;
}
//计算a^b%n
inline Int Power(Int a, Int b, Int mod)
{
	Int sum = 1;
	while(b)
	{
		if(b & 1) sum = Produc_Mod(sum, a, mod);
		a = Produc_Mod(a, a, mod);
		b >>= 1;
	}
	return sum;
}

//Rabin_Miller判素
bool Rabin_Miller(Int n)
{
	int i, j, k = 0;
	Int u, m, buf;
	//将n-1分解为m*2^k
	if(n == 2)
		return true;
	if(n < 2 || !(n & 1))
		return false;
	m = n-1;
	while(!(m & 1))
		k++, m >>= 1;

	for(i = 0; i < 9; i++)
	{
		if(p[i] >= n)
			return true;

		u = Power(p[i], m, n);
		if(u == 1)
			continue;
		for(j = 0; j < k; j++)
		{
			buf = Produc_Mod(u, u, n);
			//看是否有非平凡因子存在
			if(buf == 1 && u != 1 && u != n-1)
				return false;
			u = buf;
		}
		//如果p[i]^(n-1) % n != 1 那么 n为合数
		if(u-1)
			return false;
	}
	return true;
}

//寻找n的一个因子
Int Pollard_rho(Int n)
{
	int i = 1;
	Int x = rand() % (n-1) + 1;
	Int y = x;
	Int k = 2;
	Int d;
	do{
		i++;
		d = Gcd(n + y - x, n);
		if(d > 1 && d < n)
			return d;
		if(i == k)
			y = x, k *= 2;
		x = (Produc_Mod(x, x, n) + n - gcc) % n;
	}while(y != x);
	return n;
}

Int Min;
Int Pollard_Min(Int n)
{
	Int p, a, b = MAX;
	if(n == 1) return MAX;
	if(Rabin_Miller(n)) return n;
	p = Pollard_rho(n);

	if(Map[p] == 0)
	    a = Map[p] = Pollard_Min(p);
	else
		a = Map[p];
	Int y = n / p;
	if(Map[y] == 0)
	    b = Map[y] = Pollard_Min(y);
	else
		b = Map[y];
	return a < b ? a : b;
}
inline bool prime( int x )
{
	return x > 1 && !f[x];
}

int main()
{
	prime_init();
	int T;
	cin >> T;
	while ( T -- )
	{
		int p, fg = 0;
		cin >> p;
		for ( int i = 0; pri[i] * pri[i] <= p; i ++ )
		{
			if ( p % pri[i] ) continue;
			if ( Rabin_Miller((p / pri[i])) )
			{
				fg = true;
				break;
			}
		}
		puts(fg? "Yes" : "No");
	}
	return 0;
}

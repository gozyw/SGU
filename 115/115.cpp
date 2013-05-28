#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	int d, m;
	cin >> d >> m;
	if ( m < 1 || m > 12 || d < 1 || d > mm[m] )
	{
		cout << "Impossible" << endl;
		return 0; 
	}
	int sum = d;
	for ( int i = 1; i < m; i ++ ) sum += mm[i];
	cout << (sum + 6) % 7 + 1 << endl;
	return 0;
}

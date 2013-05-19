#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int pt = n % 3;
	int res = (n / 3) << 1;
	if ( pt == 2 ) res ++;
	cout << res << endl; 
	return 0;
}



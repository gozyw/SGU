#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int Quickeuler( int n )
{
    int t = 1, k = n;
    for ( int i = 2; i * i <= n; i ++ )
    {
        if ( n % i == 0 )
        {
            t *= i - 1;
            n /= i;
            while ( n % i == 0 )
            {
                t *= i;
                n /= i;
            }
        }
    }
    if ( n > 1 )
    t *= n - 1;
    return t;
}
int main()
{
    int n;
    while ( cin >> n )
    {
        cout << Quickeuler(n) <<endl;


    }
    return 0;
}

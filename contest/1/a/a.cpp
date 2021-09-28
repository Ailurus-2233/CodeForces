/* Problem: 
 * Author: ailurus2233
 * Time: 2021-09-17 11:29:31
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double m, n, a;
    cin >> m >> n >> a;
    m = ceil(m / a);
    n = ceil(n / a);
    cout << ll(m * n);

    //please AC!!
    return 0;
}
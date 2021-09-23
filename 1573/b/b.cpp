/* Problem: 
 * Author: ailurus2233
 * Time: 2021-09-18 22:38:12
**/

#include <bits/stdc++.h>

/* define block */

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c = 0;
        cin >> c;
        int a[2][c];
        for (int j = 0; j < 2; j ++) {
            for (int k = 0; k < c; k++) {
                cin >> a[j][k];
            }
        }
        int min = 2 * c;
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < c; k++) {
                if (a[0][j] < a[1][k]) {
                    int ans = j + k;
                    if (ans < min) min = ans;
                    break;
                }
            }
            if (min <= j) break; 
        }
        cout << min << endl;
    }

    //please AC!!
    return 0;
}
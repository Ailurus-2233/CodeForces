/* Problem: 
 * Author: ailurus2233
 * Time: 2021-10-14 13:23:28
**/

#include <bits/stdc++.h>

/* define block */

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    /* Code Block */
    int d, sum;
    cin >> d >> sum;

    int min[d], max[d], delta[d];
    int sum_min = 0, sum_max = 0;

    for (int i = 0; i < d; i++) {
        cin >> min[i] >> max[i];
        sum_min += min[i];
        sum_max += max[i];
        delta[i] = max[i] - min[i];
    }

    if (sum_min <= sum && sum_max >= sum) {
        cout << "YES" << endl;
        int sum_delta = sum - sum_min;
        for (int i = 0; i < d; i++) {
            if (sum_delta - delta[i] >= 0) {
                cout << max[i] << " ";
                sum_delta -= delta[i];
            } else {
                if (sum_delta == 0) {
                    cout << min[i] << " ";
                } else {
                    cout << max[i] - sum_delta << " ";
                    sum_delta = 0;
                }
            }
        }
    } else {
        cout << "NO" << endl;
    }
    //please AC!!
    return 0;
}
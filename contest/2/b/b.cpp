/* Problem: 2B The least round way
 * Author: ailurus2233
 * Time: 2021-09-17 19:36:57
**/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dp[2][MAX + 5][MAX + 5];
    bool zero_flag = false;
    int zero_x = 1, zero_y = 1, n, a;
    memset(dp, 63, sizeof(dp));
 
    cin >> n;
 
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++) {
            cin >> a;
            int count_2 = 0;
            int count_5 = 0;
            if (a == 0) {
                zero_flag = true;
                zero_x = i;
                zero_y = j;
            }
            while (a % 2 == 0 && a != 0) {
                count_2++;
                a /= 2;
            }
            while (a % 5 == 0 && a != 0) {
                count_5++;
                a /= 5;
            }
            if (i == 1 && j == 1) {
                dp[0][i][j] = count_2;
                dp[1][i][j] = count_5;
            } else {
                dp[0][i][j] = count_2 + min(dp[0][i - 1][j], dp[0][i][j - 1]);
                dp[1][i][j] = count_5 + min(dp[1][i - 1][j], dp[1][i][j - 1]);
            }
        }
    int index, ans;
    if (dp[0][n][n] > dp[1][n][n]) {
        index = 1;
        ans = dp[1][n][n];
    } else {
        index = 0;
        ans = dp[0][n][n];
    }
    if (ans == 0) {
        cout << ans << endl;
    } else {
        if (zero_flag) {
            cout << 1 << endl;
            string path = "";
            for (int i = 1; i < zero_x; i++)
                path += "D";
            for (int i = 1; i < zero_y; i++)
                path += "R";
            for (int i = zero_x; i < n; i++)
                path += "D";
            for (int i = zero_y; i < n; i++)
                path += "R";
            cout << path << endl;
        } else {
            cout << ans << endl;
        }
    }
    if (!zero_flag || ans == 0) {
        string path = "";
        int i = n, j = n;
        while (i != 1 || j != 1) {
            if (dp[index][i - 1][j] >= dp[index][i][j - 1]) {
                path = "R" + path;
                j--;
            } else {
                path = "D" + path;
                i--;
            }
        }
        cout << path << endl;
    }

    //please AC!!
    return 0;
}
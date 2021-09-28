/* Problem: 
 * Author: ailurus2233
 * Time: 2021-09-18 15:44:47
**/

#include <bits/stdc++.h>

/* define block */

using namespace std;
typedef long long ll;

int grid[3][3];

int *is_win() {
    int *ans = new int[8];
    int i = 0;
    ans[i++] = grid[0][0] + grid[1][1] + grid[2][2];
    ans[i++] = grid[0][2] + grid[1][1] + grid[2][0];

    for (int j = 0; j < 3; j++) {
        ans[i++] = grid[j][0] + grid[j][1] + grid[j][2];
        ans[i++] = grid[0][j] + grid[1][j] + grid[2][j];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int countx = 0;
    int count0 = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                grid[i][j] = 1;
                countx++;
            }
            if (c == '0') {
                grid[i][j] = -1;
                count0++;
            }
            if (c == '.')
                grid[i][j] = 0;
        }

    int *ans = is_win();
    int sec_x = 0;
    int sec_0 = 0;
    int a = 0;
    for (int i = 0; i < 8; i++) {
        if (ans[i] == 3) {
            sec_x++;
            a = ans[i];
        }
        if (ans[i] == -3) {
            sec_0++;
            a = ans[i];
        }
    }

    if (!((countx - count0 == 0 && sec_x == 0) || (countx - count0 == 1 && sec_0 == 0)) || (sec_x >= 1 && sec_0 >= 1))
        cout << "illegal";
    else {
        if (a == 3)
            cout << "the first player won";
        else if (a == -3)
            cout << "the second player won";
        else {
            if (countx + count0 == 9)
                cout << "draw";
            else if (countx - count0 == 0)
                cout << "first";
            else
                cout << "second";
        }
    }

    //please AC!!
    return 0;
}
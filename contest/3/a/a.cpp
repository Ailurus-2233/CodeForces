/* Problem: 3A Shortest path of the king
 * Author: ailurus2233
 * Time: 2021-09-18 15:44:47
**/

#include <bits/stdc++.h>

#define MAX 16

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string k = "", s = "";
    int count = 0;
    string *path = new string[MAX];

    cin >> k >> s;

    int k_site[2], s_site[2];
    k_site[0] = k[0] - 96;
    k_site[1] = k[1] - 48;
    s_site[0] = s[0] - 96;
    s_site[1] = s[1] - 48;

    while (k_site[0] != s_site[0] || k_site[1] != s_site[1]) {
        string p = "";
        if (k_site[0] > s_site[0]) {
            p += "L";
            k_site[0] -= 1;
        }
        if (k_site[0] < s_site[0]) {
            p += "R";
            k_site[0] += 1;
        }
        if (k_site[1] > s_site[1]) {
            p += "D";
            k_site[1] -= 1;
        }
        if (k_site[1] < s_site[1]) {
            p += "U";
            k_site[1] += 1;
        }
        path[count++] = p;
    }
    cout << count << endl;
    for (int i = 0; i  < count; i++)
        cout << path[i] << endl;
    //please AC!!
    return 0;
}

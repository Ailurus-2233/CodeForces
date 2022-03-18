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

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        string s = "";
        cin >> n >> s;
        int count = 0;
        if (s[s.size()-1] != 48) count += s[s.size()-1] - 48;
        for (int j = s.size() - 2; j >= 0; j--) {
            if (s[j] == 48) continue;
            else count += (s[j] - 47);
        }
        cout << count << endl;
    }

    //please AC!!
    return 0;
}
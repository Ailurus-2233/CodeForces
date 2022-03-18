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
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m.find(s) == m.end()) {
            cout << "OK" << endl;
            m[s] = 1;
        }else {
        }
        cout << s << endl;
    }
    //please AC!!
    return 0;
}
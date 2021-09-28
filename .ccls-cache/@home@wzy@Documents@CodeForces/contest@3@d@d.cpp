/* Problem: 
 * Author: ailurus2233
 * Time: 2021-09-18 15:44:47
**/

#include <bits/stdc++.h>

/* define block */
const int maxn = 50000+3;
char s[maxn];

using namespace std;
typedef long long ll;

struct inf {
    int loc;
    ll a, b;
    inf(int d, ll e, ll f) {
        loc = d;
        a = e;
        b = f;
    }
    bool operator<(const inf &x) const {
        return -b+a > -x.b+x.a;
    }
};

priority_queue<inf> q;

int main() {	
	ios::sync_with_stdio(false);
    cin.tie(0);
    /* Code Block */
    cin >> s;
    int len = strlen(s);
    int js = 0;
    ll ans = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') js++;
        if (s[i] == ')') js--;
        if (s[i] == '?') {
            js--;
            ll a, b;
            cin >> a >> b;
            q.push(inf(i, a, b));
            ans += b;
            s[i] = ')';
        }
        if (js < 0) {
            if (q.empty()) {
                cout << -1;
                return 0;
            }
            inf k = q.top();
            ans = ans-k.b+k.a;
            js += 2;
            q.pop();
            s[k.loc] = '(';
        }
    }
    if (js != 0) {
        cout << -1;
        return 0;
    }
    cout << ans << endl;
    cout << s << endl;

    //please AC!!
    return 0;
}

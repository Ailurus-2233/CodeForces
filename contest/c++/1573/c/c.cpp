/* Problem: 
 * Author: ailurus2233
 * Time: 2021-09-18 22:38:12
**/

#include <bits/stdc++.h>

/* define block */

using namespace std;
typedef long long ll;

int sum(int *arr, int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) ans += arr[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;
        int book[k][k];
        memset(book, 0, sizeof(book));
        for (int j = 0; j < k; j++) {
            int nn = 0;
            cin >> nn;
            for (int l = 0; l < nn; l++) {
                int index = 0;
                cin >> index;
                book[j][index-1] = 1;
            }
        }
        int count = 0;
        int s[k];
        while (1) {
            int s_n[k];
            for (int j = 0; j < k; j++) {
                s_n[j] = sum(book[j], k);
                if (s_n[j] == 0) {
                    for (int l = 0; l < k; l++)
                        book[l][j] = 0;
                }
            }
            count++;
            int over = 0;
            for (int j = 0; j < k; j++) {
                if (s_n[j] == 0) {
                    over = 1;
                } else {
                    over = 0;
                    break;
                }
            }
            if (over) {
                cout << count << endl;
                break;
            }
            for (int j = 0; j < k; j++) {
                if (s_n[j] == s[j]) {
                    
                } else {
                    over = 1;
                    s[j] = s_n[j];
                }
            }
            if (!over) {
                cout << -1 << endl;
                break;
            }
        }
    }

    //please AC!!
    return 0;
}
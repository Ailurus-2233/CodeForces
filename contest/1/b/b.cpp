/* Problem: 2B Spreadsheet
 * Author: ailurus2233
 * Time: 2021-09-17 11:29:31
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int c_i = 0;

int ana_method(string data)
{
    if (data[0] != 'R')
        return 1;
    if (data[1] < 65 || data[1] > 90)
        for (int i = 2; i < data.size(); i++)
            if (data[i] == 'C') {
                c_i = i;
                return 2;
            }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, method;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string data;
        cin >> data;
        method = ana_method(data);
        if (method == 1) {
            int col_i = 0;
            int col = 0, row = 0;
            for (int j = 0; j < data.size(); j++)
                if (data[j] < 65) {
                    col_i = j - 1;
                    row = atoi(data.substr(j, data.size()).c_str());
                    break;
                }
            int p = 0;
            for (int j = col_i; j >= 0; j--)
                col += (data[j] - 64) * pow(26, p++);
            cout << "R" << row << "C" << col << endl;
        } else {
            int row = atoi(data.substr(1, c_i).c_str());
            int col = atoi(data.substr(c_i + 1, data.size()).c_str());
            string col_s = "";
            while (col != 0) {
                int ans = col % 26;
                if (ans == 0) {
                    col_s = 'Z' + col_s;
                    col -= 26;
                } else {
                    col -= ans;
                    col_s = char(ans + 64) + col_s;
                }
                col /= 26;
            }
            cout << col_s << row << endl;
        }
    }

    return 0;
}
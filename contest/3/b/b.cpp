#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

struct node {
    int index, value;
} boat1[MAX], boat2[MAX];

bool cmp(node a, node b) {
    return a.value > b.value;
}

int sum1[MAX];
int sum2[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num, weight;
    cin >> num >> weight;
    int x, y, len1 = 0, len2 = 0;
    for (int i = 1; i <= num; i++) {
        cin >> x >> y;
        if (x == 1) {
            boat1[++len1].index = i;
            boat1[len1].value = y;
        } else {
            boat2[++len2].index = i;
            boat2[len2].value = y;
        }
    }

    sort(boat1 + 1, boat1 + 1 + len1, cmp);
    sort(boat2 + 1, boat2 + 1 + len2, cmp);

    for (int i = 1; i <= len1; i++)
        sum1[i] = sum1[i - 1] + boat1[i].value;

    for (int i = 1; i <= len2; i++)
        sum2[i] = sum2[i - 1] + boat2[i].value;

    x = 0;
    y = 0;
    int ans = 0;

    for (int i = 0; i <= len1; i++) {
        if (i > weight)
            break;
        int left = 0, right = len2, j = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid * 2 <= (weight - i))
                j = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        int tmp = sum1[i] + sum2[j];
        if (tmp > ans) {
            ans = tmp;
            x = i, y = j;
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= x; i++)
        cout << boat1[i].index << " ";
    for (int i = 1; i <= y; i++)
        cout << boat2[i].index << " ";

    //please AC!!
}
/* Problem: 2C Commentator problem
 * Author: ailurus2233
 * Time: 2021-09-17 19:36:57
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double x[3] = {0, 0, 0};
double y[3] = {0, 0, 0};
double r[3] = {0, 0, 0};
double t[3] = {0, 0, 0};

double mx;
double my;

double get_error(double px, double py) {
    double ans = 0;
    for (int i = 0; i < 3; i++)
        t[i] = sqrt((px - x[i]) * (px - x[i]) + (py - y[i]) * (py - y[i])) / r[i];
    for (int i = 0; i < 3; i++)
        ans += (t[i] - t[(i + 1) % 3]) * (t[i] - t[(i + 1) % 3]);
    return sqrt(ans);
}

int argmin(double arr[4]) {
    int index = 0;
    double min = arr[0];
    for (int i = 1; i < 4; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i] >> r[i];
    mx = (x[0] + x[1] + x[2]) / 3.0;
    my = (y[0] + y[1] + y[2]) / 3.0;

    double d = 1.0;

    while (d > 1e-5) {
        double tmp = get_error(mx, my);
        double ntmp[4] = {
            get_error(mx + d, my),
            get_error(mx, my + d),
            get_error(mx - d, my),
            get_error(mx, my - d)};
        if (ntmp[argmin(ntmp)] > tmp) 
            d *= 0.8;
        else {
            int i = argmin(ntmp);
            mx += i == 0 ? d : (i == 2 ? -d : 0);
            my += i == 1 ? d : (i == 3 ? -d : 0);
        }
    }

    if (get_error(mx, my) < 1e-5)
        printf("%.5f %.5f", mx, my);

    //please AC!!
    return 0;
}
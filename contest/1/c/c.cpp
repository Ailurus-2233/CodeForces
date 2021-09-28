/* Problem:
 * Author: ailurus2233
 * Time: 2021-09-17 11:29:31
 **/

#include <bits/stdc++.h>
#define PI 3.1415926

using namespace std;

typedef long long ll;

struct Point {
    double x, y;    
} A, B, C;

double get_distant(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    double a = get_distant(B, C);
    double b = get_distant(C, A);
    double c = get_distant(A, B);

    double p = 0.5 * (a + b + c);

    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    double R = a * b * c / (4 * S);

    double cos_A = 1 - (a * a) / (2 * R * R);
    if (cos_A > 1)
        cos_A = 1;
    if (cos_A < -1)
        cos_A = -1;
    double phi_A = acos(cos_A);

    double cos_B = 1 - (b * b) / (2 * R * R);
    if (cos_B > 1)
        cos_B = 1;
    if (cos_B < -1)
        cos_B = -1;
    double phi_B = acos(cos_B);

    double cos_C = 1 - (c * c) / (2 * R * R);
    if (cos_C > 1)
        cos_C = 1;
    if (cos_C < -1)
        cos_C = -1;
    double phi_C = acos(cos_C);

    int num = 0;


    for (int i = 3; i <= 100; i++) {
        double theta = 2 * PI/i;
        double t_A = phi_A / theta;
        int r_A = round(t_A);
        double t_B = phi_B / theta;
        int r_B = round(t_B);
        double t_C = phi_C / theta;
        int r_C = round(t_C);
        if (abs(t_A - r_A) < 1e-5 && abs(t_B - r_B) < 1e-5 && abs(t_C - r_C) < 1e-5) {
            num = i;
            break;
        }
    }
    printf("%.6f",  0.5 * R * R * sin(2 * PI/num) * num);
    //please AC!!
    return 0;
}
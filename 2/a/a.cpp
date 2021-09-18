/* Problem: 
 * Author: ailurus2233
 * Time: 2021-09-17 19:36:57
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct rf {
    int score;
    string name;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rf *ranks = new rf[n];
    int ranks_index = 0;
    rf *round_first = new rf[n];

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        int flag = 1;
        for (int i = 0; i < ranks_index; i++) {
            if(ranks[i].name == name) {
                ranks[i].score += score;
                flag = 0;
            }
        }
        if (flag) {
            ranks[ranks_index].name = name;
            ranks[ranks_index++].score = score;  
        }
        rf max_i;
        max_i.name = "";
        max_i.score = 0;
        for (int j = 0; j < ranks_index; j++)
            if (ranks[j].score > max_i.score) {
                max_i.name = ranks[j].name;
                max_i.score = ranks[j].score;
            }
        round_first[i] = max_i;
    }

    int same_flag = 0;
    string names[n];
    int max_score = round_first[n - 1].score;
    string max_name = round_first[n - 1].name;
    names[0] = max_name;
    int index = 0;
    for (int j = 0; j < ranks_index; j++) {
        if (ranks[j].score == max_score && ranks[j].name != max_name) {
            same_flag = 1;
            names[++index] = ranks[j].name;
        }
    }

    if (same_flag) {
        for (int j = 0; j < n; j++) {
            int flag = 0;
            for (int i = 0; i < n; i++) {
                if (round_first[j].name == names[i])
                    flag = 1;
            }
            if (round_first[j].score >= max_score && flag) {
                max_name = round_first[j].name;
                break;
            }
        }
    }

    cout << max_name;
    //please AC!!
    return 0;
}
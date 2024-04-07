#include <bits/stdc++.h>
using namespace std;

int bar() {
    int D;
    cin >> D;
    for (int i = 0; i < D; ++ i) {
        int S, T;
        string str_t;
        string str_s;
        cin >> str_t >> str_s;
        //01串长度
        int n;
        n = str_s.size();
        if ((str_s[0] != str_t[0]) || (str_s[n - 1] != str_t[n - 1])) {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        for (int cur = 1; cur < n - 1; ++ cur) {
            if (str_s[cur] != str_t[cur]) {
                if ((str_s[cur + 1] == str_s[cur - 1]) && (str_s[cur] != str_s[cur - 1])) {
                    ++ cnt;
                } else {
                    cnt = -1;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
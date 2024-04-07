#include <bits/stdc++.h>
using namespace std;

int bar () {
    int n = 0;
    cin >> n;
    vector<int> vec1;
    for (int i = 0; i < n; ++ i) {
        int tmp;
        cin >> tmp;
        vec1.push_back(tmp);
    }
    sort(vec1.begin(), vec1.end());
    int ret = vec1[0];
    int tmp = 1;
    for (int i = 1; i < n; ++ i) {
        while (vec1[i] == ret) {
            ++ tmp;
            ++ i;
        }
        if (tmp % (vec1[i - 1] + 1) == 0) {
            ++ ret;
            tmp = tmp / (vec1[i - 1] + 1);
            -- i;
        } else {
            break;
        }
    }
    cout << ret << endl;
    return 0;
}
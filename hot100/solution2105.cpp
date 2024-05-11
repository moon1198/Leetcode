#include <bits/stdc++.h>
using namespace std;

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int l = 0, r = plants.size() - 1;
    int tmpA = capacityA, tmpB = capacityB;
    int ans = 0;
    while (r >= l) {
        if (r == l) {
            int tmp = max(tmpA, tmpB);
            if (tmp < plants[l]) {
                ++ ans;
            }
        }
        if (tmpA < plants[l]) {
            tmpA = capacityA - plants[l];
            ++ ans;
        } else {
            tmpA -= plants[l];
        }

        if (tmpB < plants[r]) {
            tmpB = capacityB - plants[r];
            ++ ans;
        } else {
            tmpB -= plants[r];
        }
        ++ l; -- r;
    }

    return ans;
}
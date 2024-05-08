#include <bits/stdc++.h>
using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
    int n = plants.size();
    int ans = 0;
    int tmp = capacity;
    for (int i = 0; i < n; ++ i) {
        if (tmp >= plants[i]) {
            tmp -= plants[i];
            ++ ans;
        } else {
            ans += i * 2 + 1;
            tmp = capacity - plants[i];
        }
    }
    return ans;
}
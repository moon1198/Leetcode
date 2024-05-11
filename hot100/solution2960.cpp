#include <bits/stdc++.h>
using namespace std;

int countTestedDevices(vector<int>& batteryPercentages) {
    int ans = 0;
    for (int i = 0; i < batteryPercentages.size(); ++ i){
        if (batteryPercentages[i] - ans > 0) {
            ans ++;
        }
    }
    return ans;
}
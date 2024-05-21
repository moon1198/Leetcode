#include <bits/stdc++.h>
using namespace std;

////贪心 out 
//long long numberOfWeeks(vector<int>& milestones) {
//    int n = milestones.size();
//    if (n <= 1) {
//        return 1;
//    }
//    sort(milestones.begin(), milestones.end());
//    int ans = 0;
//    
//    while (milestones[n - 2] != 0) {
//        milestones[n - 1] -= milestones[n - 2];
//        milestones[n - 2] = 0;
//        ans += 2 * milestones[n - 2];
//        sort(milestones.begin(), milestones.end());
//    }
//    return ans;
//}




long long numberOfWeeks(vector<int>& milestones) {
    // 可分为两列，一列为奇数索引，一列为偶数索引
    // 当最大数填入时，未超出时，补满一列就可几乎随便填，
    // 当最大值填入超出一列时，必然直接导致error
    long long sum = 0;
    for (int i = 0; i < milestones.size(); ++ i) {
        sum += milestones[i];
    }
    int mx = 0;
    for (int& num : milestones) {
        mx = max(mx, num);
        // mx = mx > num ? mx : num;
    }
    return mx > (sum + 1) / 2 ? (sum - mx) * 2 + 1 : sum;
}
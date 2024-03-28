#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0) {
        return 0;
    }
    int left = 0, right = 1;
    int len = 0, ans = 1;
    for (; right < n; ++ right) {
        len = 1;
        for (int tmp = left; tmp < right; ++ tmp) {
            if (s[right] == s[tmp]) {
                left = tmp + 1;
            }else {
                ++ len;
            }
        }
        ans = max(ans, len);
    }
    return ans;

}
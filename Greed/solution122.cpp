#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution122_0(vector<int> &prices) {
    int res = 0;
    int len = prices.size();
    for (int i = 0; i < len - 1; ++ i) {
        res += (prices[i + 1] - prices[i]) > 0 ? (prices[i + 1] - prices[i]) : 0;
    }
    return res;
}
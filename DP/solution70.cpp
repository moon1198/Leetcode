#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution70_0(int n) {
    if (n == 1) return 1;
    vector<int> vec(n + 1, 1);
    vec[1] = 1;
    for (int i = 2; i < vec.size(); ++ i) {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    return vec[n];
}
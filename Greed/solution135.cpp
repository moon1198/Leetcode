#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution135_0(vector<int>& ratings) {
    vector<int> vec(ratings.size(), 1);
    for (int i = ratings.size() - 2; i >= 0; -- i) {
        if (ratings[i] > ratings[i + 1]) {
            vec[i] = vec[i + 1] + 1;
        }
    }
    for (int i = 1; i < ratings.size(); ++ i) {
        if (ratings[i] > ratings[i - 1]) {
            vec[i] = max(vec[i - 1] + 1, vec[i]);
        }
    }
    return accumulate(vec.begin(), vec.end(), 0);

}
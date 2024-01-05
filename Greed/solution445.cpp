#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution445_0(vector<int> &g, vector<int> &s) {

    sort(s.begin(), s.end(), [](int s1, int s2){return s1 > s2;});
    sort(g.begin(), g.end(), [](int s1, int s2){return s1 > s2;});
    int res = 0;
    
    //The begin of g;
    int j = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++ i) {
        while (j != static_cast<int>(g.size()) && g[j] > s[i]) {
            ++ j;
        }
        if (j == static_cast<int>(g.size())) {
            return res;
        }
        ++ j;
        ++ res;
    }
    return res;
}
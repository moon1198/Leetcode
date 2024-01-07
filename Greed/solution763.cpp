#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution763_0(string s) {
    vector<int> ans;
    vector<vector<int>> vec(26, vector<int>(2, -1));
    for (int i = 0; i < s.size(); ++ i) {
        //first encounter
        if (vec[s[i] - 'a'][0] == -1) {
            vec[s[i] - 'a'][0] = i;
            vec[s[i] - 'a'][1] = i;
        }else {
            vec[s[i] - 'a'][1] = i;
        }
    }
    int end = vec[s[0] - 'a'][1];
    int len = 0;
    for (int i = 0; i < s.size(); ++ i) {
        if (vec[s[i] - 'a'][1] > end) {
            end = vec[s[i] - 'a'][1];
        }
        ++ len;
        if (i == end) {
            ans.push_back(len);
            len = 0;
        }
    }
    return ans;
}
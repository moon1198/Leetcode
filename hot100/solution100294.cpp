#include <bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word) {
    vector<vector<bool>> vec(26, vector<bool>(2, false));
    for (int i = 0; i < word.size(); ++ i) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            vec[word[i] - 'a'][0] = true;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            vec[word[i] - 'A'][1] = true;
        }
    }
    int res = 0;
    for (int i = 0; i < vec.size(); ++ i) {
        if (vec[i][0] && vec[i][1]) {
            ++ res;
        }
    }

    return res;
}
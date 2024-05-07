#include <bits/stdc++.h>
using namespace std;

//当出现大写后，不能再出现小写, 
//出现大写后，又出现小写时，将小写置为false， 且因为大写为true， 
//小写无法改变
int numberOfSpecialChars(string word) {
    vector<vector<bool>> vec(26, vector<bool>(2, false));
    for (int i = 0; i < word.size(); ++ i) {
        if (word[i] >= 'a' && word[i] <= 'z' && !vec[word[i] - 'a'][1]) {
            vec[word[i] - 'a'][0] = true;
        } else if (word[i] >= 'a' && word[i] <= 'z' && vec[word[i] - 'a'][1]) {
            vec[word[i] - 'a'][0] = false;
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
#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    int i = 0;
    string ans;
    while (i < m && i < n) {
        ans.push_back(word1[i]);
        ans.push_back(word2[i]);
        ++ i;
    }
    if (i >= m) {
        while (i < n) {
            ans.push_back(word2[i]);
            ++ i;
        }
    } else {
        while (i < m) {
            ans.push_back(word1[i]);
            ++ i;
        }
    }

    return ans;
}

string mergeAlternately(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    int i = 0, j = 0, k = 0;

    string ans(m + n, ' ');
    while (j < m && k < n) {
        ans[i ++] = word1[j ++];
        ans[i ++] = word2[k ++];
    }
    while (j < m) {
        ans[i ++] = word1[j ++];
    }
    while (k < n) {
        ans[i ++] = word2[k ++];
    }

    return ans;
}
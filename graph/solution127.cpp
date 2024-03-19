#include <bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //simplify the search
    unordered_set word_set(wordList.begin(), wordList.end());
    if (word_set.find(endWord) == word_set.end()) return 0;

    //map<string, bool> visited(wordList.size(), false);

    int path_len = 1;
    map<string, int>mp;
    mp[beginWord] = path_len;

    queue<string> que;
    que.push(beginWord);

    while (!que.empty()) {
        string cur_word = que.front();
        que.pop();

        for (int i = 0; i < cur_word.size(); ++ i) {
            for (int j = 0; j < 26; ++ j) {
                string new_word = cur_word;
                new_word[i] = 'a' + j;
                if (new_word == endWord) {
                    mp[new_word] = mp[cur_word] + 1;
                    return mp[endWord];
                }
                if (word_set.find(new_word) != word_set.end() && 
                mp.find(new_word) == mp.end()) {
                    mp[new_word] = mp[cur_word] + 1;
                    que.push(new_word);
                }
            }
        }

    }
    return mp[endWord];
}


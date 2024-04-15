#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    //first : num; second : frequency
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int num : nums) {
        ++ mp[num];
    }
    for (auto &it : mp) {
        pq.push(it);
    }
    for (int i = 0; i < k; ++ i) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
}
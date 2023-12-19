#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::string;

struct Compare{
    //when return ture;the first argument comes before its second argument;
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }
};
vector<int> solution347_0(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto val : nums) {
        mp[val] ++;
    }
    priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Compare> pq;
    for (auto it : mp) {
        pq.push(it);
        int len = pq.size();
        if (len > k) {
            pq.pop();
        }
    }
    //for (auto it = mp.begin(); it != mp.end(); ++ it) {
    //    pq.push(*it);
    //    int len = pq.size();
    //    if (len > k) {
    //        pq.pop();
    //    }
    //}
    vector<int>ans;
    while(!pq.empty()) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
}
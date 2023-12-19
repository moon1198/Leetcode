#include <vector>
#include <string>
#include <deque>

using std::vector;
using std::deque;
using std::string;

class MyQueue {
public:
    MyQueue() {
    }
    void pop(int i) {
        if (!que.empty() && i == que.front()) {
            que.pop_front();
        }
    }

    void push(int i) {
        while(!que.empty() && que.back() < i) {
            que.pop_back();
        }
        que.push_back(i);
    }

    int front() {
        return que.front();
    }

private:
    deque<int> que;
};
vector<int> solution239_0(vector<int>& nums, int k) {
    MyQueue que;
    vector<int> ans;
    for (int i = 0; i < k; ++ i) {
        que.push(nums[i]);
    }
    ans.push_back(que.front());
    int len = nums.size();
    for (int i = k; i < len; ++ i) {
        que.pop(nums[i - k]);
        que.push(nums[i]);
        ans.push_back(que.front());
    }
    return ans;
}
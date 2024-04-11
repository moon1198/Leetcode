#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

struct Compare{
    bool operator()(int a, int b) {
        return a > b;
    }
};

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, Compare> pq;
    for (auto &num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}
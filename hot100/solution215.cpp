#include <bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(int a, int b) {
        return a > b;
    }
};

int findKthLargest0(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, Compare> pq;
    //priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}


//select the k-th num begin from end;
int quickSelect(vector<int> &nums, int k) {
    vector<int> big, equ, small;
    int pivot = nums[rand() % nums.size()];
    for (int i = 0; i < nums.size(); ++ i) {
        if (nums[i] > pivot) {
            big.push_back(nums[i]);
        } else if (nums[i] < pivot) {
            small.push_back(nums[i]);
        } else {
            equ.push_back(nums[i]);
        }
    }

    if (big.size() >= k) {
        return quickSelect(big, k);
    } else if (big.size() + equ.size() >= k) {
        return equ[0];
    } else {
        return quickSelect(small, k - (nums.size() - small.size()));
    }

    //can't reach here;
    return 0;
}

int findKthLargest(vector<int>& nums, int k) { 
    return quickSelect(nums, k);
}
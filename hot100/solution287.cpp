#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    for (i = 0; i < n; ++ i) {
        if (nums[i] != i + 1) {
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
    }
    return -1;
}


//成环的条件，一组数据在多次换位后，达到正确排序
//若从零开始，因为不存在零必然成环，且零索引项不是环的开头
//若两个节点指向同一节点，则这两个节点包含的值就是返回值，也就是对应节点的索引值
int findDuplicate(vector<int>& nums) {
    //寻找环的入口，
    int fast = 0, slow = 0;
    do {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (fast != slow);
    int ans = 0;
    while (ans != slow) {
        ans = nums[ans];
        slow = nums[slow];
        if (ans = slow) {
            break;
        }
    }
    return ans;
}
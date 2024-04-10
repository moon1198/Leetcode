#include <bits/stdc++.h>
using namespace std;

//如何取值mid， 保证nums1,nums2的大小顺序
//取nums1,nums2的第n个值 
int find_nth(vector<int>& nums1, int bg1, vector<int>& nums2, int bg2, int n) {
    // cout << bg1 << "; " << bg2 << "; " << n << "; " << endl;
    if (nums1.size() > nums2.size()) {
        return find_nth(nums2, bg2, nums1, bg1, n);
    }
    //nums1 shorter ; nums2 longer
    if (bg1 >= nums1.size()) {
        return nums2[bg2 + n - 1];
    } else if (bg2 >= nums2.size()) {
        return nums1[bg1 + n - 1];
    }
    if (n == 1) {
        return min(nums1[bg1], nums2[bg2]);
    }
    int l1 = nums1.size();
    int mid1 = min(l1 - 1, bg1 + n / 2 - 1);
    int mid2 = bg2 + (n - (mid1 - bg1 + 1)) - 1;
    if (nums1[mid1] < nums2[mid2]) {
        return find_nth(nums1, mid1 + 1, nums2, bg2, n - (mid1 - bg1 + 1));
    } else if (nums1[mid1] > nums2[mid2]) {
        return find_nth(nums1, bg1, nums2, mid2 + 1, n - (mid2 - bg2 + 1));
    } else {
        return nums1[mid1];
    }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1 = nums1.size(), l2 = nums2.size();
    double ret = -1;
    if ((l1 + l2) % 2) {
        //odd , (l1 + l2) / 2 + 1
        int n = (l1 + l2) / 2 + 1;
        ret = find_nth(nums1, 0, nums2, 0, n);
    } else {
        //even , (l1 + l2) / 2, (l1 + l2) / 2 + 1
        int n = (l1 + l2) / 2;
        int tmp1, tmp2;
        tmp1 = find_nth(nums1, 0, nums2, 0, n);
        tmp2 = find_nth(nums1, 0, nums2, 0, n + 1);
        ret = (tmp1 + tmp2) / 2.0;
    }
    return ret;
}
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2); // Ensure nums1 is the smaller array
        }

        int n = nums1.size();
        int m = nums2.size();
        int halfLen = (n + m + 1) / 2;
        int low = 0, high = n;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = halfLen - i;

            int nums1LeftMax = (i > 0) ? nums1[i - 1] : INT_MIN;
            int nums1RightMin = (i < n) ? nums1[i] : INT_MAX;

            int nums2LeftMax = (j > 0) ? nums2[j - 1] : INT_MIN;
            int nums2RightMin = (j < m) ? nums2[j] : INT_MAX;

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                return (n + m) % 2 == 0 
                    ? (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0
                    : max(nums1LeftMax, nums2LeftMax);
            } 

            if (nums1LeftMax > nums2RightMin) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};

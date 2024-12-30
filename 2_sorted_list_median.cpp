#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, k = 0;
        vector<int> sorted_array(n + m, 0);

        for (k = 0; k < n + m; ++k) {
            int n1 = (i < n) ? nums1[i] : INT_MAX; // Handle out-of-bounds
            int n2 = (j < m) ? nums2[j] : INT_MAX; // Handle out-of-bounds

            if (n1 < n2) {
                sorted_array[k] = n1;
                i++;
            } else {
                sorted_array[k] = n2;
                j++;
            }

            if (i == n) {
                for (int l = j; l < m; ++l, ++k) {
                    sorted_array[k + 1] = nums2[l];
                }
                break;
            } else if (j == m) {
                for (int l = i; l < n; ++l, ++k) {
                    sorted_array[k + 1] = nums1[l];
                }
                break;
            }
        }

        if ((n + m) % 2 == 0) {
            int a = sorted_array[(n + m - 1) / 2] + sorted_array[((n + m - 1) / 2) + 1];
            return static_cast<double>(a) / 2;
        } else {
            return sorted_array[(n + m) / 2];
        }
    }
};

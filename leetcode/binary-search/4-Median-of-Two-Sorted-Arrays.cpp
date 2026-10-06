class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int l = 0, r = m;
        int half = (m + n + 1) / 2;

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int leftA  = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightA = (i == m) ? INT_MAX : nums1[i];

            int leftB  = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightB = (j == n) ? INT_MAX : nums2[j];

            if (leftA <= rightB && leftB <= rightA) {
                int leftMax = max(leftA, leftB);

                if ((m + n) % 2 == 1)
                    return leftMax;

                int rightMin = min(rightA, rightB);
                return (leftMax + rightMin) / 2.0;
            }

            if (leftA > rightB) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return 0.0;
    }
};
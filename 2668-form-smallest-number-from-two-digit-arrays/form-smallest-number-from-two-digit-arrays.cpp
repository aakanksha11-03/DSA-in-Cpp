class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int common = 10;

        for (int a : nums1) {
            for (int b : nums2) {
                if (a == b) {
                    common = min(common, a);
                }
            }
        }
        if (common != 10) {
            return common;
        }

        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());

        return min(min1, min2) * 10 + max(min1, min2);
    }
};
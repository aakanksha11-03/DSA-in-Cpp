class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;

        vector<int> freq(n + 1, 0);

        for (int x : nums) {
            if (x < 1 || x > n) return false;
            freq[x]++;
        }

        // 1 to n-1 should occur exactly once
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1) return false;
        }

        // n should occur exactly twice
        return freq[n] == 2;
    }
};
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int start = 0; start < n; start++) {
            if (nums[start] != 0) continue;

            // Try moving right
            vector<int> temp = nums;
            int curr = start;
            int dir = 1;

            while (curr >= 0 && curr < n) {
                if (temp[curr] == 0) {
                    curr += dir;
                } else {
                    temp[curr]--;
                    dir = -dir;
                    curr += dir;
                }
            }

            bool valid = true;
            for (int x : temp) {
                if (x != 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans++;

            // Try moving left
            temp = nums;
            curr = start;
            dir = -1;

            while (curr >= 0 && curr < n) {
                if (temp[curr] == 0) {
                    curr += dir;
                } else {
                    temp[curr]--;
                    dir = -dir;
                    curr += dir;
                }
            }

            valid = true;
            for (int x : temp) {
                if (x != 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans++;
        }

        return ans;
    }
};
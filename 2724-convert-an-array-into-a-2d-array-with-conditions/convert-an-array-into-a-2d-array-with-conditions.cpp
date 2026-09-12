class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<vector<int>> result;

        for (int num : nums) {
            freq[num]++;
        }

        while (true) {
            vector<int> row;

            for (auto& [num, count] : freq) {
                if (count > 0) {
                    row.push_back(num);
                    count--;
                }
            }

            if (row.empty()) break;

            result.push_back(row);
        }

        return result;
    }
};
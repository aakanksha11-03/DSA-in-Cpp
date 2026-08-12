class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        function<void(int)> solve = [&](int start) {
            ans.push_back(temp);

            for(int i = start; i < nums.size(); i++) {

                if ( i > start && nums [i] == nums[i-1])
                continue;

                temp.push_back(nums[i]);

                solve(i + 1);

                temp.pop_back();
            }
        };

        solve(0);

        return ans;
    }
};
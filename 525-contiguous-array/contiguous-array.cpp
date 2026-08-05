class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int , int> mp;
        int prefixSum = 0;
        int maxLength = 0;

        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
            prefixSum--;

            else
            prefixSum++;

            if (mp.find(prefixSum) != mp.end()) {
                maxLength = max(maxLength, i - mp[prefixSum]);
            }
            else {
                mp[prefixSum] = i;
            }
        }
        return maxLength;
    }
};